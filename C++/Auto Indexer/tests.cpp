//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <cstring>
#include "DSString.h"
#include "DSvector.h"


TEST_CASE("String class", "[string]"){
    String s[10];
    s[0] = String("testString");
    s[1] = String("a test string");
    s[2] = String("");
    s[3] = String("THIS IS AN UPPERCASE STRING");
    s[4] = String("this is an uppercase string");
    s[5] = String("\n");
    s[6] = String("");
    s[7] = String("  split  split  split  ");
    s[8] = String("                          ");
    s[9] = String("testString");


    SECTION("Equality operators"){
        REQUIRE(s[0] == String("testString"));
        REQUIRE(s[0] == s[9]);
        REQUIRE(s[2] == "");
        REQUIRE(s[1] == "a test string");
        REQUIRE(!(s[3] == s[4]));
    }

    SECTION("Assignment operators"){
        String str;
        str = "a test string";
        REQUIRE(str == s[1]);
        str = String("testString");
        REQUIRE(str == s[0]);
        str = "";
        REQUIRE(str == s[6]);
        str = String("\n");
        REQUIRE(str == s[5]);
    }


    SECTION("Addition operator"){
        REQUIRE(String("testStringtestString") == s[0]+s[9]);
        REQUIRE(s[6] + s[6] == "");
        REQUIRE(s[5] + s[6] == String("\n"));
        REQUIRE(s[0] + s[1] + s[2] == "testStringa test string");
    }


    SECTION("Greater than operator"){
        REQUIRE(s[0] > s[1]);
        REQUIRE(s[4] > s[3]);
        REQUIRE(s[9] > s[6]);
        REQUIRE(s[7] > s[6]);
    }


    SECTION("[] Operator"){
        REQUIRE(s[0][1] == 'e');
        REQUIRE(s[9][-1] == 'g');
        REQUIRE(s[3][-3] == 'I');
        REQUIRE(s[4][4] == ' ');
        REQUIRE(s[6][0] == 0);
    }


    SECTION("Size function"){
        REQUIRE(s[9].size() == 10);
        REQUIRE(s[2].size() == 0);
        REQUIRE(s[8].size() == 26);
        REQUIRE(s[3].size() == 27);
    }


    SECTION("Sort function"){
        s[0].sort();
        REQUIRE(s[0] == "Seginrsttt");
        s[1].sort();
        REQUIRE(s[1] == "  aeginrssttt");
        s[2].sort();
        REQUIRE(s[2] == "");
    }

    SECTION("toLowerCase function"){
        s[0].toLowerCase();
        REQUIRE(s[0] == "teststring");
        s[3].toLowerCase();
        REQUIRE(s[3] == "this is an uppercase string");
    }

    SECTION("Substring function"){
        REQUIRE(s[0].substring(0, 5) == "testS");
        REQUIRE(s[1].substring(-6, -1) == "tring");
        REQUIRE(s[9].substring(0, -3) == "testStri");
        REQUIRE(s[9].substring(0, -1) == s[9]);
        REQUIRE(s[4].substring(0, 4) == "this");
    }


    SECTION("c_str function"){
        REQUIRE(strcmp(s[0].c_str(), "testString") == 0);
        REQUIRE(strcmp(s[9].c_str(), s[0].c_str()) == 0);
        REQUIRE(strcmp(s[2].c_str(), "") == 0);
    }


}

TEST_CASE("Vector class", "[vector]"){
    Vector<String> myVector;
    myVector.add(String("testString"));
    myVector.add(String("a test string"));
    myVector.add(String(""));
    myVector.add(String("banana"));
    myVector.add(String("Cat"));
    myVector.add(String("elephant"));
    myVector.add(String("!wooooo!"));
    myVector.add(String("500 days of winter"));

    SECTION("get function"){
        REQUIRE(myVector.get(0) == "testString");
        REQUIRE(myVector.get(1) == "a test string");
        REQUIRE(myVector.get(2) == "");
        REQUIRE(myVector.get(3) == "banana");
        REQUIRE(myVector.get(4) == "Cat");
        REQUIRE(myVector.get(5) == "elephant");
        REQUIRE(myVector.get(6) == "!wooooo!");
        REQUIRE(myVector.get(7) == "500 days of winter");
    }

    SECTION("size function")
    {
        REQUIRE(myVector.size() == 8);
        myVector.add(String("temp string"));
        REQUIRE(myVector.size() == 9);
        myVector.add(String("another string"));
        REQUIRE(myVector.size() == 10);
        myVector.add(String(""));
        REQUIRE(myVector.size() == 11);
    }
    SECTION("[] operator")
    {
        REQUIRE(myVector[5] == "elephant");
        REQUIRE(myVector[6] == "!wooooo!");
        REQUIRE(myVector[7] == "500 days of winter");
    }

    SECTION("copy constructor")
    {
        Vector<String> secondVector(myVector);
        REQUIRE(myVector.get(0) == "testString");
        REQUIRE(myVector.get(1) == "a test string");
        REQUIRE(myVector.get(2) == "");
        REQUIRE(myVector.get(3) == "banana");
        REQUIRE(myVector.get(4) == "Cat");
        REQUIRE(myVector.get(5) == "elephant");
        REQUIRE(myVector.get(6) == "!wooooo!");
        REQUIRE(myVector.get(7) == "500 days of winter");
    }

    SECTION("sort function")
    {
        myVector.sort();
        REQUIRE(myVector.get(0) == "");
        REQUIRE(myVector.get(1) == "!wooooo!");
        REQUIRE(myVector.get(2) == "500 days of winter");
        REQUIRE(myVector.get(3) == "Cat");
        REQUIRE(myVector.get(4) == "a test string");
        REQUIRE(myVector.get(5) == "banana");
        REQUIRE(myVector.get(6) == "elephant");
        REQUIRE(myVector.get(7) == "testString");
    }

    SECTION("contains function")
    {
        REQUIRE(myVector.contains(String("banana")) == true);
        REQUIRE(myVector.contains(String("a test string")) == true);
        REQUIRE(myVector.contains(String("This isn't here")) == false);
        REQUIRE(myVector.contains(String("")) == true);
    }

    SECTION("+= operator")
    {
        myVector += String("plus equals!");
        myVector += String("a n o t h e r vector");

        REQUIRE(myVector[8] == "plus equals!");
        REQUIRE(myVector[9] == "a n o t h e r vector");
    }

    SECTION("equal to operator")
    {
        Vector<String> secondVector;
        for(int i = 0; i < 5; i++)
            secondVector.add(String("first"));
        for(int i = 5; i < 15; i++)
            secondVector.add(String("second"));
        for(int i = 15; i < 30; i++)
            secondVector.add(String("third"));

        myVector = secondVector;

        REQUIRE(myVector[0] == "first");
        REQUIRE(myVector[1] == "first");
        REQUIRE(myVector[14] == "second");
        REQUIRE(myVector[15] == "third");
        REQUIRE(myVector[29] == "third");

    }

    SECTION("add function with specific location")
    {
        myVector.add(String("insert!"), 4);
        REQUIRE(myVector.get(0) == "testString");
        REQUIRE(myVector.get(1) == "a test string");
        REQUIRE(myVector.get(2) == "");
        REQUIRE(myVector.get(3) == "banana");
        REQUIRE(myVector.get(4) == "insert!");
        REQUIRE(myVector.get(5) == "Cat");
        REQUIRE(myVector.get(6) == "elephant");
        REQUIRE(myVector.get(7) == "!wooooo!");
        REQUIRE(myVector.get(8) == "500 days of winter");
    }
}





