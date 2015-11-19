#pragma once
#include "Rule.h"
#include <set>
#include <stack>
#include "AbstractFrame.h"
#include "Buffer.h"
#include "Trigger.h"
#include "FunctionStore.h"
#include "Formatter.h"
#include "FormatterStore.h"


class TemplateEngine
{
	std::list<Rule*> rules;
	std::stack<Buffer*> buffers;
	FunctionStore* function_store;
	FormatterStore* formatter_store;

	void initBuffer();

	void delete_buffer();
	
	void delete_ruleset();

	void pushBuffer(std::string indentation);

	bool execute(Trigger* trigger);

	bool execute(Trigger* trigger, Rule* rule);

	bool execute(Trigger* trigger, Token* token);

	Rule* ruleFor(Trigger* trigger);

	bool match(Rule* rule, Trigger* trigger);

	bool conditionMatchTrigger(Trigger* trigger, Condition* condition);

	bool is_abstract_mark(Token* token);

	bool execute(Trigger* trigger, AbstractMark* mark);

	bool render_frame(AbstractFrame* frame, AbstractMark* mark);

	bool render_primitive_frame(AbstractFrame* frame, AbstractMark* mark);

	bool render_composite_frame(AbstractFrame* frame, AbstractMark* mark);

	bool render_frames(std::list<AbstractFrame*> frames, AbstractMark* mark);

	void write_separator(AbstractMark* mark);

	void write(ItRules::type text);

	AbstractFrame* frame(ItRules::type value);

	ItRules::type format(ItRules::type value, Formatter* formatter);

	ItRules::type format(ItRules::type value, AbstractMark* mark);

	bool trigger(ItRules::type value, AbstractMark* mark);

	bool is_primitive_frame(ItRules::type value);

	bool is_abstract_frame(ItRules::type value);

	bool pop_buffer();

	std::string document_of(Buffer* buffer);

	AbstractMark* compose_mark(Trigger* trigger, AbstractMark* mark) const;
public:
	TemplateEngine();

	~TemplateEngine();

	TemplateEngine* add(std::list<Rule*> rules);

	TemplateEngine* add(std::string name, Function* function);

	std::string render(AbstractFrame* frame);


};
