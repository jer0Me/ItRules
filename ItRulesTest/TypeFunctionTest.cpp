#include "gtest/gtest.h"
#include <TypeFunction.h>
#include <Frame.h>
#include <Mark.h>


TEST(TypeFunctionTest, should_check_types_in_frame)
{
	auto type_function = new TypeFunction();
	auto frame = new Frame();
	frame->add_types({ "X", "Y", "Z" });
	auto trigger = new Trigger(frame, new Mark("f"));

	ASSERT_TRUE(type_function->match(trigger, "Y"));
	ASSERT_FALSE(type_function->match(trigger, "T"));
	ASSERT_TRUE(type_function->match(trigger, "X&Y&Z"));
	ASSERT_TRUE(type_function->match(trigger, "X & Y & Z"));
	ASSERT_FALSE(type_function->match(trigger, "X & Y & T"));
	ASSERT_TRUE(type_function->match(trigger, "A|Y|T"));
	ASSERT_TRUE(type_function->match(trigger, "A | Y | T"));
	ASSERT_FALSE(type_function->match(trigger, "A|S|T"));
	ASSERT_FALSE(type_function->match(trigger, "A | S | T"));
}