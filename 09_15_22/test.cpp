#include <gtest/gtest.h>
#include "book.h"
using namespace std;
	

TEST(bookTest, Test1) {
	genreType g[1];
    g[0] = CHILD;
	book b("Maurice Sendak", "Where the Wild things are", 
    "Monsters", "Harper & Row", "0-06-025492-0", g, 1);
	genreType g1[2];
    g[0] = FANTASY;
    g[1] = SCIFI;
    book b1("Madeleine L'Engle", "A Wrinkle in Time", 
    "Timey Wimey Stuff", "Ariel Books", "9780582151840", g, 1);
	book b3(b);
	ASSERT_FALSE(b != b3);
	std::cout << "after first expect" << std::endl;
	EXPECT_TRUE(b != b1);
	std::cout << "after second expect" << std::endl;
	ASSERT_STRCASEEQ(b.getTitle().c_str(), b3.getTitle().c_str());
	ASSERT_EQ(b.getTitle(), "Where the wild things are");

}

extern "C" int startTest(int x,char ** y) {
	//cout << "begin" << endl;
	//int x = 0;
	//char ** y = NULL;
    testing::InitGoogleTest(&x, y);
	//cout << "Init Complete"<< endl;
    int code = RUN_ALL_TESTS();
	//exit(code);
	return code;
}
//int i = startTest();
extern "C" int __wrap_main(int x,char ** y) {
	return startTest(x,y);
} 