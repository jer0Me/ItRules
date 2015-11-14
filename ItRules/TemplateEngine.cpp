#include "TemplateEngine.h"
#include "Mark.h"
#include "CompositeMark.h"
#include "NonFormattingMark.h"
#include "PrimitiveFrame.h"
#include <boost/foreach.hpp>
#include <boost/variant/get.hpp>

TemplateEngine::TemplateEngine()
{
	this->function_store = FunctionStore();
}


TemplateEngine TemplateEngine::add(std::list<Rule*> rules)
{
	BOOST_FOREACH(Rule* rule, rules)
	{
		ruleSet.insert(rule);
	}
	return *this;
}

std::string TemplateEngine::render(AbstractFrame* frame)
{
	initBuffer();
	auto* mark = new Mark("root");
	auto* trigger = new Trigger(frame, mark);
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
	while(!this->buffers.empty())
	{
		auto* buffer = this->buffers.top();
		delete(buffer);
		this->buffers.pop();
	}
	pushBuffer("");
}

void TemplateEngine::pushBuffer(std::string indentation)
{
	this->buffers.push(new Buffer(indentation));
}

bool TemplateEngine::execute(Trigger* trigger)
{
	auto* rule = ruleFor(trigger);
	return rule->is_initiated() && execute(trigger, rule);
}

bool TemplateEngine::execute(Trigger* trigger, Rule* rule)
{
	bool result;
	BOOST_FOREACH(Token* token, rule->get_tokens()) {
		result = execute(trigger, token);
	}
	return true;		
}

bool TemplateEngine::execute(Trigger* trigger, Token* token)
{
	if (is_abstract_mark(token)) return execute(trigger, dynamic_cast<AbstractMark *>(token));
	write(token->to_string());
	return true;
}

bool TemplateEngine::execute(Trigger* trigger, AbstractMark* mark)
{
	return render_frame(trigger->get_frame(), compose_mark(trigger, mark));
}

AbstractMark* TemplateEngine::compose_mark(Trigger* trigger, AbstractMark* mark)
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
	BOOST_FOREACH(AbstractFrame* frame, frames)
	{
		pushBuffer(mark->get_indentation());
		if (rendered && mark->is_multiple()) write_separator(mark);
		rendered = rendered | trigger(format(frame, mark), new NonFormattingMark(mark));
		pop_buffer();
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
	auto trigger = new Trigger(frame(value), mark);
	if (!execute(trigger)) return false;
	buffers.top()->used();
	return true;
}


bool TemplateEngine::is_primitive_frame(ItRules::type value)
{
	if(AbstractFrame* pi = boost::get<AbstractFrame*>(value))
	{
		return dynamic_cast<PrimitiveFrame*>(pi) != nullptr;
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
		PrimitiveFrame* primitiveFrame = dynamic_cast<PrimitiveFrame*>(boost::get<AbstractFrame*>(value));
		result = primitiveFrame->get_value();
	}
		
	BOOST_FOREACH(std::string option,mark->get_options())
	{
		result = format(result, formater_store.get(option));
	}
	return result;
}

void TemplateEngine::write_separator(AbstractMark* mark)
{
	write(mark->get_separator());
}

void TemplateEngine::write(std::string text)
{
	auto* buffer = this->buffers.top();
	buffer->write(text);
}


bool TemplateEngine::render_primitive_frame(AbstractFrame* frame, AbstractMark* mark)
{
	return frame->is_primitive() ? render_primitive_frame(frame, mark) :
		render_composite_frame(frame, mark);
}


bool TemplateEngine::is_abstract_mark(Token* token)
{
	return dynamic_cast<AbstractMark *> (token) != nullptr;
}

Rule* TemplateEngine::ruleFor(Trigger* trigger)
{
	BOOST_FOREACH(Rule* rule, ruleSet)
	{
		if (match(rule, trigger)) {
			return rule;
		}
	}
	return nullptr;
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
	return function_store.get(condition)->match(trigger, condition->getParameter());
}

AbstractFrame* TemplateEngine::frame(ItRules::type value)
{
	if (AbstractFrame* pi = boost::get<AbstractFrame*>(value))
	{
		return pi;
	}
	auto* primitive_frame = new PrimitiveFrame();
	primitive_frame->set_value(value);
	return primitive_frame;
}

std::string TemplateEngine::document_of(Buffer* buffer)
{
	return buffer->get_content();
}