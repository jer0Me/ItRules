#include "TemplateEngine.h"
#include "Mark.h"
#include "CompositeMark.h"
#include "NonFormattingMark.h"
#include "PrimitiveFrame.h"
#include <boost/variant/get.hpp>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <boost/foreach.hpp>
#include <sstream>

TemplateEngine::TemplateEngine()
{
	this->function_store = new FunctionStore();
	this->formatter_store = new FormatterStore();
	this->lexical_analyzer = new LexicalAnalyzer();
}

TemplateEngine::~TemplateEngine()
{
	delete this->function_store;
	delete this->formatter_store;
	delete_ruleset();
	delete_buffer();
}

void TemplateEngine::delete_ruleset()
{
	BOOST_FOREACH(Rule* rule, rules)
	{
		delete rule;
	};
	this->rules.clear();
}

void TemplateEngine::delete_buffer()
{
	while (!this->buffers.empty())
	{
		auto* buffer = this->buffers.top();
		delete buffer;
		this->buffers.pop();
	}
}

TemplateEngine* TemplateEngine::use(std::string pathname)
{
	std::ifstream source(pathname);
	use(source);
	source.close();
	return this;
}


TemplateEngine* TemplateEngine::use(std::ifstream& source)
{
	std::vector<std::string> v;

	std::string line;
	std::string rules;

	while (std::getline(source, line))
	{
		std::istringstream is(line);
		std::string s;
		std::getline(is, s);
		s.find("\t");
		rules += s;
	}

	generate_rules(rules);
	
	return this;
}

void TemplateEngine::generate_rules(std::string input)
{
	add(lexical_analyzer->analyze(input));
}

TemplateEngine* TemplateEngine::add(std::list<Rule*> list)
{
	BOOST_FOREACH(Rule* rule, list)
	{
		rules.push_back(rule);
	};

	return this;
}

std::string TemplateEngine::render(AbstractFrame* frame)
{
	initBuffer();
	auto mark = new Mark("root");
	auto trigger = new Trigger(frame, mark);
	execute(trigger);
	delete(mark);
	delete(trigger);
	return document_of(this->buffers.top());
}

std::string document_of(Buffer* buffer)
{
	return buffer->get_content();
}

void TemplateEngine::initBuffer()
{
	delete_buffer();
	pushBuffer("");
}

void TemplateEngine::pushBuffer(std::string indentation)
{
	this->buffers.push(new Buffer(indentation));
}

bool TemplateEngine::execute(Trigger* trigger)
{
	auto rule = ruleFor(trigger);

	return rule != nullptr && execute(trigger, rule);
}

bool TemplateEngine::execute(Trigger* trigger, Rule* rule)
{
	BOOST_FOREACH(Token* token, rule->get_tokens())
	{
		execute(trigger, token);
	};
	return true;		
}

bool TemplateEngine::execute(Trigger* trigger, Token* token)
{
	if (is_abstract_mark(token)) return execute(trigger, dynamic_cast<AbstractMark *>(token));
	if (is_expression(token)) return execute(trigger, dynamic_cast<Expression*>(token));
	write(token->to_string());
	return true;
}

bool TemplateEngine::execute(Trigger* trigger, AbstractMark* mark)
{
	return render_frame(trigger->get_frame(), compose_mark(trigger, mark));
}

AbstractMark* TemplateEngine::compose_mark(Trigger* trigger, AbstractMark* mark) const
{
	return trigger->get_frame()->is_primitive() ? new CompositeMark(mark, trigger->get_mark()->get_options()) : mark;
}

bool TemplateEngine::render_frame(AbstractFrame* frame, AbstractMark* mark)
{
	return frame->is_primitive() ? render_primitive_frame(frame, mark) : render_composite_frame(frame, mark);
}

bool TemplateEngine::render_composite_frame(AbstractFrame* frame, AbstractMark* mark)
{
	auto frames = frame->get_frames(mark->get_name());
	return frames.size() != 0 && render_frames(frames, mark);
}

bool TemplateEngine::render_frames(std::list<AbstractFrame*> frames, AbstractMark* mark)
{
	auto rendered = false;
	AbstractMark* non_formatting_mark = nullptr;
	BOOST_FOREACH(AbstractFrame* abstract_frame, frames)
	{
		pushBuffer(mark->get_indentation());
		if (rendered && mark->is_multiple()) write_separator(mark);
		non_formatting_mark = new NonFormattingMark(mark, this->formatter_store);
		rendered = rendered | trigger(format(abstract_frame, mark), non_formatting_mark);
		pop_buffer();
		delete non_formatting_mark;
	}

	return rendered;
}

bool TemplateEngine::pop_buffer()
{
	auto pop = buffers.top();
	buffers.pop();

	if(pop->is_used())
	{
		buffers.top()->write(pop);
		buffers.top()->used();
	}
	return pop->is_used();
}

bool TemplateEngine::trigger(ItRules::type value, AbstractMark* mark)
{
	auto* trigger = new Trigger(frame(value), mark);
	if (!execute(trigger)) return false;
	buffers.top()->used();
	delete trigger;
	return true;
}

bool TemplateEngine::is_primitive_frame(ItRules::type value)
{
	try
	{
		if(is_abstract_frame(value))
		{
			auto primitive_frame = dynamic_cast<PrimitiveFrame*>(boost::get<AbstractFrame*>(value));
			return primitive_frame != nullptr;
		}
		return false;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

bool TemplateEngine::is_expression(Token* token)
{
	try
	{
		auto expression = dynamic_cast<Expression*>(token);
		return expression != nullptr;
	}
	catch (std::exception exception)
	{
		return false;
	}
}

ItRules::type TemplateEngine::format(ItRules::type value, Formatter* formatter)
{
	return formatter->format(value);
}

ItRules::type TemplateEngine::format(ItRules::type value, AbstractMark* mark)
{
	ItRules::type result = NULL;
	if (is_primitive_frame(value))
	{
		auto primitive_frame = dynamic_cast<PrimitiveFrame*>(boost::get<AbstractFrame*>(value));
		result = primitive_frame->get_value();
	}
	else
	{
		if(is_abstract_frame(value))
		{
			result = dynamic_cast<AbstractFrame*>(boost::get<AbstractFrame*>(value));
		}
	}

	BOOST_FOREACH(std::string option, mark->get_options())
	{
		result = format(result, formatter_store->get(option));
	};
	return result;
}

void TemplateEngine::write_separator(AbstractMark* mark)
{
	write(mark->get_separator());
}

void TemplateEngine::write(ItRules::type text)
{
	auto* buffer = this->buffers.top();
	buffer->write(text);
}

bool TemplateEngine::render_primitive_frame(AbstractFrame* frame, AbstractMark* mark)
{
	std::string mark_name = mark->get_name();
	boost::to_lower(mark_name);
	if (mark_name.compare("value") != 0) return false;
	write(format(frame, mark));
	Buffer* buffer = this->buffers.top();
	buffer->used();
	delete mark;
	return true;
}

bool TemplateEngine::is_abstract_mark(Token* token)
{
	try
	{
		auto abstractMark = dynamic_cast<AbstractMark *> (token);
		return abstractMark != nullptr;
	} 
	catch (std::exception exception) 
	{
		return false;
	}

}

Rule* TemplateEngine::ruleFor(Trigger* trigger)
{
	BOOST_FOREACH(Rule* rule, rules)
	{
		if (match(rule, trigger)) return rule;
	}
	return  nullptr;
}

bool TemplateEngine::match(Rule* rule, Trigger* trigger)
{
	BOOST_FOREACH(Condition* condition, rule->get_conditions())
	{
		if (!conditionMatchTrigger(trigger, condition)) return false;
	}
	return true;
}

bool TemplateEngine::conditionMatchTrigger(Trigger* trigger, Condition* condition)
{
	return function_store->get(condition)->match(trigger, condition->getParameter());
}

AbstractFrame* TemplateEngine::frame(ItRules::type value)
{
	if (is_abstract_frame(value))
	{
		return boost::get<AbstractFrame*>(value);
	}
	auto* primitive_frame = new PrimitiveFrame(value);
	return primitive_frame;
}

std::string TemplateEngine::document_of(Buffer* buffer)
{
	return buffer->get_content();
}

bool TemplateEngine::is_abstract_frame(ItRules::type value)
{
	try
	{
		boost::get<AbstractFrame*>(value);
		return true;
	} catch (std::exception exception)
	{
		return false;
	}
}

TemplateEngine* TemplateEngine::add(std::string name, Function* function)
{
	this->function_store->add(name, function);
	return this;
}

bool TemplateEngine::execute(Trigger* trigger, Expression* expression)
{
	auto result = true;
	while(expression != nullptr)
	{
		pushBuffer("");
		if(is_constant(expression))
		{
			this->buffers.top()->used();
		}
		BOOST_FOREACH(Token* token, expression->get_tokens())
		{
			result &= execute(trigger, token);
		}
		expression = expression->get_other();
		if (pop_buffer()) break;
	}
	return result;
}

bool TemplateEngine::is_constant(Expression * expression)
{
	BOOST_FOREACH(Token* token, expression->get_tokens())
	{
		if (is_abstract_mark(token)) return false;
	}
	return true;
}