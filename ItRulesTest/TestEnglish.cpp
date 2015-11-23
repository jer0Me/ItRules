#include <gtest/gtest.h>
#include <EnglishPluralInflector.h>


TEST(EnglishTest, test_nouns)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("cars", inflector->plural("car"));
	ASSERT_EQ("houses", inflector->plural("house"));
	ASSERT_EQ("books", inflector->plural("book"));
	ASSERT_EQ("birds", inflector->plural("bird"));
	ASSERT_EQ("pencils", inflector->plural("pencil"));
	delete inflector;
}

TEST(EnglishTest, ending_in_ss)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("kisses", inflector->plural("kiss"));
	ASSERT_EQ("bosses", inflector->plural("boss"));
	ASSERT_EQ("addresses", inflector->plural("address"));
	ASSERT_EQ("classes", inflector->plural("class"));
	ASSERT_EQ("dresses", inflector->plural("dress"));
	delete inflector;
}

TEST(EnglishTest, ending_in_sh)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("wishes", inflector->plural("wish"));
	ASSERT_EQ("fishes", inflector->plural("fish"));
	ASSERT_EQ("brushes", inflector->plural("brush"));
	ASSERT_EQ("flashes", inflector->plural("flash"));
	delete inflector;
}

TEST(EnglishTest, ending_in_ch)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("matches", inflector->plural("match"));
	ASSERT_EQ("beaches", inflector->plural("beach"));
	ASSERT_EQ("clutches", inflector->plural("clutch"));
	ASSERT_EQ("peaches", inflector->plural("peach"));
	ASSERT_EQ("inches", inflector->plural("inch"));
	ASSERT_EQ("branches", inflector->plural("branch"));
	ASSERT_EQ("speeches", inflector->plural("speech"));
	delete inflector;
}

TEST(EnglishTest, ending_in_x)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("foxes", inflector->plural("fox"));
	ASSERT_EQ("boxes", inflector->plural("box"));
	ASSERT_EQ("suffixes", inflector->plural("suffix"));
	ASSERT_EQ("prefixes", inflector->plural("prefix"));
	delete inflector;
}

TEST(EnglishTest, ending_in_zz)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("buzzes", inflector->plural("buzz"));
	delete inflector;
}
TEST(EnglishTest, ending_in_vowel_y)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("boys", inflector->plural("boy"));
	ASSERT_EQ("holidays", inflector->plural("holiday"));
	ASSERT_EQ("keys", inflector->plural("key"));
	ASSERT_EQ("guys", inflector->plural("guy"));
	delete inflector;
}
TEST(EnglishTest, ending_in_consonant_y)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("parties", inflector->plural("party"));
	ASSERT_EQ("ladies", inflector->plural("lady"));
	ASSERT_EQ("stories", inflector->plural("story"));
	ASSERT_EQ("nannies", inflector->plural("nanny"));
	ASSERT_EQ("cities", inflector->plural("city"));
	delete inflector;
}
TEST(EnglishTest, ending_in_fe)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("lives", inflector->plural("life"));
	ASSERT_EQ("wives", inflector->plural("wife"));
	delete inflector;
}

TEST(EnglishTest, ending_in_f)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("leaves", inflector->plural("leaf"));
	ASSERT_EQ("thieves", inflector->plural("thief"));
	delete inflector;
}

TEST(EnglishTest, ending_in_is)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("analyses", inflector->plural("analysis"));
	ASSERT_EQ("bases", inflector->plural("basis"));
	ASSERT_EQ("crises", inflector->plural("crisis"));
	delete inflector;
}

TEST(EnglishTest, ending_in_o)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("potatoes", inflector->plural("potato"));
	ASSERT_EQ("echoes", inflector->plural("echo"));
	ASSERT_EQ("tomatoes", inflector->plural("tomato"));
	ASSERT_EQ("heroes", inflector->plural("hero"));
	ASSERT_EQ("torpedoes", inflector->plural("torpedo"));
	ASSERT_EQ("mosquitos", inflector->plural("mosquito"));
	delete inflector;
}

TEST(EnglishTest, irregular)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("men", inflector->plural("man"));
	ASSERT_EQ("women", inflector->plural("woman"));
	ASSERT_EQ("children", inflector->plural("child"));
	ASSERT_EQ("feet", inflector->plural("foot"));
	ASSERT_EQ("teeth", inflector->plural("tooth"));
	ASSERT_EQ("geese", inflector->plural("goose"));
	ASSERT_EQ("mice", inflector->plural("mouse"));
	ASSERT_EQ("sheep", inflector->plural("sheep"));
	ASSERT_EQ("deer", inflector->plural("deer"));
	ASSERT_EQ("moose", inflector->plural("moose"));
	ASSERT_EQ("aircraft", inflector->plural("aircraft"));
	delete inflector;
}

TEST(EnglishTest, rewards)
{
	auto inflector = new EnglishPluralInflector();
	ASSERT_EQ("ants", inflector->plural("ant"));
	ASSERT_EQ("locks", inflector->plural("lock"));
	ASSERT_EQ("bananas", inflector->plural("banana"));
	ASSERT_EQ("magazines", inflector->plural("magazine"));
	ASSERT_EQ("bicycles", inflector->plural("bicycle"));
	ASSERT_EQ("mongooses", inflector->plural("mongoose"));
	ASSERT_EQ("cows", inflector->plural("cow"));
	ASSERT_EQ("noses", inflector->plural("nose"));
	ASSERT_EQ("daughters", inflector->plural("daughter"));
	ASSERT_EQ("oranges", inflector->plural("orange"));
	ASSERT_EQ("eggs", inflector->plural("egg"));
	ASSERT_EQ("pictures", inflector->plural("picture"));
	ASSERT_EQ("flowers", inflector->plural("flower"));
	ASSERT_EQ("roses", inflector->plural("rose"));
	ASSERT_EQ("grapes", inflector->plural("grape"));
	ASSERT_EQ("spoonfuls", inflector->plural("spoonful"));
	ASSERT_EQ("humans", inflector->plural("human"));
	ASSERT_EQ("toys", inflector->plural("toy"));
	ASSERT_EQ("jugs", inflector->plural("jug"));
	ASSERT_EQ("vases", inflector->plural("vase"));
	ASSERT_EQ("kings", inflector->plural("king"));
	ASSERT_EQ("wells", inflector->plural("well"));
	ASSERT_EQ("addresses", inflector->plural("address"));
	ASSERT_EQ("fishes", inflector->plural("fish"));
	ASSERT_EQ("batches", inflector->plural("batch"));
	ASSERT_EQ("inches", inflector->plural("inch"));
	ASSERT_EQ("beaches", inflector->plural("beach"));
	ASSERT_EQ("itches", inflector->plural("itch"));
	ASSERT_EQ("bosses", inflector->plural("boss"));
	ASSERT_EQ("kisses", inflector->plural("kiss"));
	ASSERT_EQ("boxes", inflector->plural("box"));
	ASSERT_EQ("lenses", inflector->plural("lens"));
	ASSERT_EQ("branches", inflector->plural("branch"));
	ASSERT_EQ("lunches", inflector->plural("lunch"));
	ASSERT_EQ("brushes", inflector->plural("brush"));
	ASSERT_EQ("matches", inflector->plural("match"));
	ASSERT_EQ("buses", inflector->plural("bus"));
	ASSERT_EQ("minuses", inflector->plural("minus"));
	ASSERT_EQ("buzzes", inflector->plural("buzz"));
	ASSERT_EQ("patches", inflector->plural("patch"));
	ASSERT_EQ("catches", inflector->plural("catch"));
	ASSERT_EQ("peaches", inflector->plural("peach"));
	ASSERT_EQ("churches", inflector->plural("church"));
	ASSERT_EQ("pluses", inflector->plural("plus"));
	ASSERT_EQ("classes", inflector->plural("class"));
	ASSERT_EQ("prefixes", inflector->plural("prefix"));
	ASSERT_EQ("clutches", inflector->plural("clutch"));
	ASSERT_EQ("prospectuses", inflector->plural("prospectus"));
	ASSERT_EQ("coaches", inflector->plural("coach"));
	ASSERT_EQ("quizzes", inflector->plural("quiz"));
	ASSERT_EQ("complexes", inflector->plural("complex"));
	ASSERT_EQ("sixes", inflector->plural("six"));
	ASSERT_EQ("crosses", inflector->plural("cross"));
	ASSERT_EQ("slashes", inflector->plural("slash"));
	ASSERT_EQ("dishes", inflector->plural("dish"));
	ASSERT_EQ("speeches", inflector->plural("speech"));
	ASSERT_EQ("dresses", inflector->plural("dress"));
	ASSERT_EQ("suffixes", inflector->plural("suffix"));
	ASSERT_EQ("eyelashes", inflector->plural("eyelash"));
	ASSERT_EQ("taxes", inflector->plural("tax"));
	ASSERT_EQ("flashes", inflector->plural("flash"));
	ASSERT_EQ("thrushes", inflector->plural("thrush"));
	ASSERT_EQ("foxes", inflector->plural("fox"));
	ASSERT_EQ("viruses", inflector->plural("virus"));
	ASSERT_EQ("gases", inflector->plural("gas"));
	ASSERT_EQ("watches", inflector->plural("watch"));
	ASSERT_EQ("glasses", inflector->plural("glass"));
	ASSERT_EQ("wishes", inflector->plural("wish"));
	ASSERT_EQ("armies", inflector->plural("army"));
	ASSERT_EQ("enemies", inflector->plural("enemy"));
	ASSERT_EQ("babies", inflector->plural("baby"));
	ASSERT_EQ("fairies", inflector->plural("fairy"));
	ASSERT_EQ("beauties", inflector->plural("beauty"));
	ASSERT_EQ("families", inflector->plural("family"));
	ASSERT_EQ("berries", inflector->plural("berry"));
	ASSERT_EQ("ladies", inflector->plural("lady"));
	ASSERT_EQ("cherries", inflector->plural("cherry"));
	ASSERT_EQ("libraries", inflector->plural("library"));
	ASSERT_EQ("cities", inflector->plural("city"));
	ASSERT_EQ("nappies", inflector->plural("nappy"));
	ASSERT_EQ("countries", inflector->plural("country"));
	ASSERT_EQ("skies", inflector->plural("sky"));
	ASSERT_EQ("cries", inflector->plural("cry"));
	ASSERT_EQ("spies", inflector->plural("spy"));
	ASSERT_EQ("curries", inflector->plural("curry"));
	ASSERT_EQ("stories", inflector->plural("story"));
	ASSERT_EQ("diaries", inflector->plural("diary"));
	ASSERT_EQ("strawberries", inflector->plural("strawberry"));
	ASSERT_EQ("discoveries", inflector->plural("discovery"));
	ASSERT_EQ("territories", inflector->plural("territory"));
	ASSERT_EQ("duties", inflector->plural("duty"));
	ASSERT_EQ("theories", inflector->plural("theory"));
	ASSERT_EQ("alloys", inflector->plural("alloy"));
	ASSERT_EQ("joys", inflector->plural("joy"));
	ASSERT_EQ("bays", inflector->plural("bay"));
	ASSERT_EQ("keys", inflector->plural("key"));
	ASSERT_EQ("boys", inflector->plural("boy"));
	ASSERT_EQ("kidneys", inflector->plural("kidney"));
	ASSERT_EQ("chimneys", inflector->plural("chimney"));
	ASSERT_EQ("monkeys", inflector->plural("monkey"));
	ASSERT_EQ("days", inflector->plural("day"));
	ASSERT_EQ("plays", inflector->plural("play"));
	ASSERT_EQ("decoys", inflector->plural("decoy"));
	ASSERT_EQ("rays", inflector->plural("ray"));
	ASSERT_EQ("delays", inflector->plural("delay"));
	ASSERT_EQ("toys", inflector->plural("toy"));
	ASSERT_EQ("donkeys", inflector->plural("donkey"));
	ASSERT_EQ("trays", inflector->plural("tray"));
	ASSERT_EQ("guys", inflector->plural("guy"));
	ASSERT_EQ("trolleys", inflector->plural("trolley"));
	ASSERT_EQ("jerseys", inflector->plural("jersey"));
	ASSERT_EQ("valleys", inflector->plural("valley"));
	ASSERT_EQ("journeys", inflector->plural("journey"));
	ASSERT_EQ("ways", inflector->plural("way"));
	ASSERT_EQ("beeves", inflector->plural("beef"));
	ASSERT_EQ("loaves", inflector->plural("loaf"));
	ASSERT_EQ("calves", inflector->plural("calf"));
	ASSERT_EQ("selves", inflector->plural("self"));
	ASSERT_EQ("halves", inflector->plural("half"));
	ASSERT_EQ("sheaves", inflector->plural("sheaf"));
	ASSERT_EQ("housewives", inflector->plural("housewife"));
	ASSERT_EQ("shelves", inflector->plural("shelf"));
	ASSERT_EQ("knives", inflector->plural("knife"));
	ASSERT_EQ("thieves", inflector->plural("thief"));
	ASSERT_EQ("leaves", inflector->plural("leaf"));
	ASSERT_EQ("wives", inflector->plural("wife"));
	ASSERT_EQ("lives", inflector->plural("life"));
	ASSERT_EQ("wolves", inflector->plural("wolf"));
	ASSERT_EQ("bamboos", inflector->plural("bamboo"));
	ASSERT_EQ("ratios", inflector->plural("ratio"));
	ASSERT_EQ("casinos", inflector->plural("casino"));
	ASSERT_EQ("scenarios", inflector->plural("scenario"));
	ASSERT_EQ("commandos", inflector->plural("commando"));
	ASSERT_EQ("silos", inflector->plural("silo"));
	ASSERT_EQ("discos", inflector->plural("disco"));
	ASSERT_EQ("shampoos", inflector->plural("shampoo"));
	ASSERT_EQ("duos", inflector->plural("duo"));
	ASSERT_EQ("solos", inflector->plural("solo"));
	ASSERT_EQ("dynamos", inflector->plural("dynamo"));
	ASSERT_EQ("stereos", inflector->plural("stereo"));
	ASSERT_EQ("ghettos", inflector->plural("ghetto"));
	ASSERT_EQ("studios", inflector->plural("studio"));
	ASSERT_EQ("kangaroos", inflector->plural("kangaroo"));
	ASSERT_EQ("tattoos", inflector->plural("tattoo"));
	ASSERT_EQ("kilos", inflector->plural("kilo"));
	ASSERT_EQ("trios", inflector->plural("trio"));
	ASSERT_EQ("photos", inflector->plural("photo"));
	ASSERT_EQ("videos", inflector->plural("video"));
	ASSERT_EQ("pianos", inflector->plural("piano"));
	ASSERT_EQ("zeros", inflector->plural("zero"));
	ASSERT_EQ("radios", inflector->plural("radio"));
	ASSERT_EQ("zoos", inflector->plural("zoo"));
	ASSERT_EQ("buffaloes", inflector->plural("buffalo"));
	ASSERT_EQ("potatoes", inflector->plural("potato"));
	ASSERT_EQ("echoes", inflector->plural("echo"));
	ASSERT_EQ("tomatoes", inflector->plural("tomato"));
	ASSERT_EQ("heroes", inflector->plural("hero"));
	ASSERT_EQ("torpedoes", inflector->plural("torpedo"));
	delete inflector;
}

