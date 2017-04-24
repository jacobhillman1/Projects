//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "avltree.h"
#include "DSString.h"
#include "word.h"

TEST_CASE("AvlTree class", "[AvlTree]"){


    SECTION("Default constructor")
    {
        AvlTree<int> testTree;
        REQUIRE(testTree.isEmpty());
    }

    SECTION("isEmpty")
    {
        AvlTree<int> testTree;
        REQUIRE(testTree.isEmpty());
        testTree.insert(10);
        REQUIRE(!testTree.isEmpty());
    }

    SECTION("contains <int> (public)")
    {
        AvlTree<int> testTree;
        testTree.insert(10);
        REQUIRE(testTree.contains(10));
        REQUIRE(!testTree.contains(11));
        testTree.insert(50);
        REQUIRE(testTree.contains(50));
        REQUIRE(!testTree.contains(51));
        testTree.insert(5);
        REQUIRE(testTree.contains(5));
        REQUIRE(!testTree.contains(6));
        testTree.insert(25);
        REQUIRE(testTree.contains(25));
        REQUIRE(!testTree.contains(26));
    }

    SECTION("tree order/ print tree")
    {
        AvlTree<int> testTree;
        testTree.insert(10);
        testTree.insert(50);
        testTree.insert(5);
        testTree.insert(25);
        testTree.insert(26);
        testTree.insert(27);
        testTree.printTree();
    }

    SECTION("contains <String> (public)")
    {
        AvlTree<String> stringTestTree;
        String test = "test";
        stringTestTree.insert(test);
        REQUIRE(stringTestTree.contains("test"));
        String test2("apple");
        stringTestTree.insert(test2);
        REQUIRE(stringTestTree.contains("apple"));
        REQUIRE(!stringTestTree.contains("banana"));
        String test3("computer");
        String test4("table");
        String test5("a");
        stringTestTree.insert(test3);
        stringTestTree.insert(test4);
        stringTestTree.insert(test5);
        stringTestTree.printTree();
    }

}

TEST_CASE("Word class", "[Word]"){

    SECTION("Overloaded > operator")
    {
        Word test1(String("test1"));
        Word test2(String("test2"));

        REQUIRE(test2 > test1);
        REQUIRE(!(test1 > test2));

        Word one(String("1"));
        Word two(String("2"));
        Word a(String("a"));
        Word b(String("b"));

        REQUIRE(b > a);
        REQUIRE(a > two);
        REQUIRE(two > one);
        REQUIRE(!(one > two));
        REQUIRE(!(two > a));
        REQUIRE(!(a > b));
    }

    SECTION("Inserting words into AVL tree")
    {
        Word test1(String("test1"));
        Word test2(String("test2"));
        Word one(String("1"));
        Word two(String("2"));
        Word a(String("a"));
        Word b(String("b"));
        AvlTree<Word> test;
        test.insert(a);
        test.insert(one);
        test.insert(b);
        test.insert(test2);
        test.insert(two);
        test.insert(test1);

        test.printTree();

    }

    SECTION("contains Word obects")
    {
        Word test1(String("test1"));
        Word test2(String("test2"));
        Word one(String("1"));
        Word two(String("2"));
        Word a(String("a"));
        Word b(String("b"));
        AvlTree<Word> test;
        test.insert(a);
        test.insert(one);
        test.insert(b);
        test.insert(test2);
        test.insert(two);
        test.insert(test1);

        REQUIRE(test.contains(String("a")));
        REQUIRE(test.contains(String("b")));
        REQUIRE(test.contains(String("1")));
        REQUIRE(test.contains(String("2")));
        REQUIRE(test.contains(String("test1")));
        REQUIRE(test.contains(String("test2")));
    }

    SECTION("Remove puncuation")
    {
        String test("test!");
        REQUIRE(test == "test!");
        test.removePunctuation();
        REQUIRE(test == "test");
    }
}

