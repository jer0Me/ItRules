#include <iostream>
#include <Frame.h>
#include <LexicalAnalyzer.h>
#include <TemplateEngine.h>
#include <PrimitiveFrame.h>
#include <boost/variant/get.hpp>
#include <algorithm>
#include <Rule.h>

int main()
{
		
	std::string const input = "def type(Person)\n\t$Name has $PetsCount+Letters pets:\n\t* $Pets...[ , ]\nend"
		"\n\ndef type(Dog)\n\t$Name, a $Age dog\nend\n\ndef type(Cat)\n\t\t\t$Name, a $Age kitty\nend\n\n"
		"def trigger(Age) one()\n\tone year old\nend\n\ndef trigger(Age)\n\t$value+Letters years old\nend";
	LexicalAnalyzer analyzer;
	auto* template_engine = new TemplateEngine();


	std::list<Rule*> rules = analyzer.analyze(input);

	
	
	

	template_engine->add(rules);

	class one : public Function
	{
		bool match(Trigger* trigger, std::string parameter) override
		{
			return trigger->get_frame()->is_primitive() && is_value_one(trigger->get_frame());
		}

		bool is_value_one(AbstractFrame* abstract_frame) const
		{
			PrimitiveFrame* primitive_frame = dynamic_cast<PrimitiveFrame*>(abstract_frame);
			try
			{
				int test = boost::get<int>(primitive_frame->get_value());
				return test == 1;
			}
			catch (std::exception exception)
			{
				return false;
			}
		}
	};

	template_engine->add("one", new one());

	Frame* ruffo = new Frame();
	ruffo->add_types({ "dog","pet","object" })
		->add_frame("name", "Ruffo")
		->add_frame("age", 5);

	Frame* missy = new Frame();
	missy->add_types({ "cat","pet","object" })
		->add_frame("name", "Missy")
		->add_frame("age", 1);

	Frame* toby = new Frame();
	toby->add_types({ "dog","pet","object" })
		->add_frame("name", "Toby")
		->add_frame("age", 3);

	Frame* frame = new Frame();
	frame->add_types({ "object", "person" })
		->add_frame("name", "Roger Dickens")
		->add_frame("petscount", 3)
		->add_frame("pets", { ruffo,missy,toby });


	std::cout << template_engine->render(frame);
	system("pause");
	return 1;
}
