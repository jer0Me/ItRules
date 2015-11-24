#include <TemplateEngine.h>
#include <Frame.h>
#include <iostream>
#include <PrimitiveFrame.h>

using namespace boost::gregorian;

void example()
{
	auto person = new Frame();
	person->add_types({ "person","object" })
		->add_frame("name", "Pau Gasol")
		->add_frame("birthday", date(1980, Jul, 6))
		->add_frame("country", "Spain");

	auto engine = new TemplateEngine();
	std::cout << engine->use("Templates\\Person.itr")->render(person) << "\n\n" ;
	delete engine;
	delete person;
}

void example_custom_condition()
{
	auto dog_ruffo = new Frame();
	dog_ruffo->add_types({ "dog","pet" })
		->add_frame("name", "Ruffo")
		->add_frame("age", "5");

	auto cat_missy = new Frame();
	cat_missy->add_types({ "cat","pet" })
		->add_frame("name", "Missy")
		->add_frame("age", 1);

	auto dog_toby = new Frame();
	dog_toby->add_types({ "dog", "pet" })
		->add_frame("name", "Toby")
		->add_frame("age", 3);

	auto person = new Frame();
	person->add_types({ "person" })
		->add_frame("name", "Roger Dickens")
		->add_frame("petscount", 5)
		->add_frame("pets", { dog_ruffo, cat_missy, dog_toby });

	auto engine = new TemplateEngine();
	engine->use("Templates\\CustomCondition.itr");

	class one : public Function
	{
		bool match(Trigger* trigger, std::string parameter) override {
			if(trigger->get_frame()->is_primitive())
			{
				auto primitive_frame = dynamic_cast<PrimitiveFrame*>(trigger->get_frame());
				if (!is_int(primitive_frame->get_value())) return false;
				return get_int(primitive_frame->get_value()) == 1;
			}
			return false;
		}
	};

	engine->add("one", new one());
	std::cout << engine->render(person) << "\n";
	system("pause");
}


int main()
{
	example_custom_condition();
	example();
	

}
