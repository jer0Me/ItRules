#include <gtest/gtest.h>
#include <Formatter.h>
#include <FormatterStore.h>
#include <boost/variant/get.hpp>

TEST(FormatterStoreTest, should_render_in_uppercase)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("HELLO WORLD", boost::get<std::string>(formatter_store->get("UpperCase")->format("Hello world")));
}

TEST(FormatterStoreTest, should_render_in_lowercase)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("hello world", boost::get<std::string>(formatter_store->get("LowerCase")->format("hello world")));
}

TEST(FormatterStoreTest, should_render_in_uppercase_first_letter)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("Hello world", boost::get<std::string>(formatter_store->get("FirstUpperCase")->format("Hello world")));
}

TEST(FormatterStoreTest, should_render_in_lowercase_first_letter)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("hELLO WORLD", boost::get<std::string>(formatter_store->get("FirstLowerCase")->format("HELLO WORLD")));
}

TEST(FormatterStoreTest, should_render_in_capitalize)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("Hello world", boost::get<std::string>(formatter_store->get("Capitalize")->format("Hello World")));
}

TEST(FormatterStoreTest, should_render_in_camelcase)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("HelloWorld", boost::get<std::string>(formatter_store->get("CamelCase")->format("Hello world")));
}

TEST(FormatterStoreTest, should_render_in_lower_camelcase)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("helloWorld", boost::get<std::string>(formatter_store->get("LowerCamelCase")->format("Hello world")));
}

TEST(FormatterStoreTest, should_render_a_year)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ(1950, boost::get<int>(formatter_store->get("Year")->format(boost::gregorian::date(1950, boost::gregorian::Jan,20))));
}

TEST(FormatterStoreTest, should_render_short_date)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("20/01/1950", boost::get<std::string>(formatter_store->get("ShortDate")->format(boost::gregorian::date(1950, boost::gregorian::Jan, 20))));
}

TEST(FormatterStoreTest, should_render_a_number_in_letters)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("one thousand nine hundred and fifty", boost::get<std::string>(formatter_store->get("Words")->format(1950)));
}

TEST(FormatterStoreTest, should_render_a_number_with_separators)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("1,950", boost::get<std::string>(formatter_store->get("Separators")->format(1950)));
}

TEST(FormatterStoreTest, should_render_a_number_with_two_decimals)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("1950.00", boost::get<std::string>(formatter_store->get("TwoDecimals")->format(1950.0)));
}


TEST(FormatterStoreTest, should_render_letter_counts)
{
	auto formatter_store = new FormatterStore();
	ASSERT_EQ("5", boost::get<std::string>(formatter_store->get("Length")->format("Hello")));
}




