//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include "/home/ds/CSE2341-16F-jacobhillman1/Sprint1/DSString.h"

TEST_CASE("LinkedList class", "[LinkedList]"){

    SECTION("Default constructor"){
        LinkedList<int> test;

    }

    SECTION("Constructor with head"){
        int x = 10;
        LinkedList<int> test(x);
        REQUIRE(test.get(0) == 10);
        LinkedList<int> test2(0);
        REQUIRE(test2.get(0) == 0);
    }

    SECTION("Copy constructor"){
        LinkedList<int> test;
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.add(17);
        LinkedList<int> copy(test);
        REQUIRE(copy.get(0) == 0);
        REQUIRE(copy.get(1) == 5);
        REQUIRE(copy.get(2) == 10);
        REQUIRE(copy.get(3) == 15);
        REQUIRE(copy.get(4) == 14);
        REQUIRE(copy.get(5) == 17);
    }

    SECTION("add and get"){
        LinkedList<int> test;
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.add(17);
        REQUIRE(test.get(0) == 0);
        REQUIRE(test.get(1) == 5);
        REQUIRE(test.get(2) == 10);
        REQUIRE(test.get(3) == 15);
        REQUIRE(test.get(4) == 14);
        REQUIRE(test.get(5) == 17);

        LinkedList<String> stringTest;
        stringTest.add(String("first element"));
        stringTest.add(String("second element"));
        REQUIRE(stringTest.get(0) == "first element");
        REQUIRE(stringTest.get(1) == "second element");

    }

    SECTION("addTohead"){
        LinkedList<int> test;
        test.addTohead((17));
        REQUIRE(test.get(0) == 17);
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.addTohead(50);
        REQUIRE(test.get(0) == 50);
        REQUIRE(test.get(1) == 17);
        REQUIRE(test.get(2) == 0);
        REQUIRE(test.get(3) == 5);
        REQUIRE(test.get(4) == 10);
        REQUIRE(test.get(5) == 15);
        REQUIRE(test.get(6) == 14);
    }

    SECTION("size"){
        LinkedList<int> test;
        REQUIRE(test.size() == 0);
        test.add(0);
        REQUIRE(test.size() == 1);
        test.add(5);
        REQUIRE(test.size() == 2);
        test.add(10);
        REQUIRE(test.size() == 3);
        test.add(15);
        REQUIRE(test.size() == 4);
        test.add(14);
        REQUIRE(test.size() == 5);
        test.add(17);
        REQUIRE(test.size() == 6);
        test.addTohead(33);
        REQUIRE(test.size() == 7);
        int x = test.get(5);
        REQUIRE(test.size() == 7);
    }

    SECTION("remove"){
        LinkedList<int> test;
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.add(17);
        REQUIRE(test.remove(3) == 15);
        REQUIRE(test.size() == 5);
        REQUIRE(test.get(3) == 14);
        REQUIRE(test.remove(3) == 14);
        REQUIRE(test.get(3) == 17);
        REQUIRE(test.get(0) == 0);
        REQUIRE(test.remove(0) == 0);
        REQUIRE(test.size() == 3);
        REQUIRE(test.get(0) == 5);

    }

    SECTION("[] operator"){
        LinkedList<int> test;
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.add(17);
        REQUIRE(test[0] == 0);
        REQUIRE(test[1] == 5);
        REQUIRE(test[2] == 10);
        REQUIRE(test[3] == 15);
        REQUIRE(test[4] == 14);
        REQUIRE(test[5] == 17);
        test[0] = 1;
        REQUIRE(test[0] == 1);
    }

    SECTION("assignment operator"){
        LinkedList<int> test;
        test.add(0);
        test.add(5);
        test.add(10);
        test.add(15);
        test.add(14);
        test.add(17);
        LinkedList<int> copy;
        copy = test;
        REQUIRE(copy.get(0) == 0);
        REQUIRE(copy.get(1) == 5);
        REQUIRE(copy.get(2) == 10);
        REQUIRE(copy.get(3) == 15);
        REQUIRE(copy.get(4) == 14);
        REQUIRE(copy.get(5) == 17);
    }


}

TEST_CASE("Stack class", "[stack]"){

    SECTION("Push"){
        Stack<int> test;
        test.push(1);
        REQUIRE(test.peek() == 1);
        test.push(2);
        REQUIRE(test.peek() == 2);
        test.push(3);
        REQUIRE(test.peek() == 3);
        test.push(100);
        REQUIRE(test.peek() == 100);

    }

    SECTION("Pop"){
        Stack<int> test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.push(4);
        REQUIRE(test.pop() == 4);
        REQUIRE(test.pop() == 3);
        REQUIRE(test.pop() == 2);
        REQUIRE(test.pop() == 1);
        REQUIRE(test.isEmpty());
    }

    SECTION("Peek"){
        Stack<int> test;
        test.push(1);
        REQUIRE(test.peek() == 1);
        test.push(2);
        REQUIRE(test.peek() == 2);
        test.push(3);
        REQUIRE(test.peek() == 3);
        test.push(100);
        REQUIRE(test.peek() == 100);
    }

}

TEST_CASE("Queue class", "[queue]"){

    SECTION("Enqueue"){
        Queue<int> test;
        test.enqueue(1);
        test.enqueue(2);
        test.enqueue(3);
        test.enqueue(4);
        test.enqueue(5);
        test.enqueue(10);
        REQUIRE(test.dequeue() == 1);
        REQUIRE(test.dequeue() == 2);
        REQUIRE(test.dequeue() == 3);
        REQUIRE(test.dequeue() == 4);
        REQUIRE(test.dequeue() == 5);
        REQUIRE(test.dequeue() == 10);
    }

    SECTION("Dequeue"){
        Queue<int> test;
        test.enqueue(10);
        test.enqueue(20);
        test.enqueue(30);
        test.enqueue(40);
        test.enqueue(50);
        test.enqueue(100);
        REQUIRE(test.dequeue() == 10);
        REQUIRE(test.dequeue() == 20);
        REQUIRE(test.dequeue() == 30);
        REQUIRE(test.dequeue() == 40);
        REQUIRE(test.dequeue() == 50);
        REQUIRE(test.dequeue() == 100);
    }

    SECTION("Peek"){
        Queue<int> test;
        test.enqueue(1);
        REQUIRE(test.peek() == 1);
        test.enqueue(2);
        REQUIRE(test.peek() == 1);
        test.enqueue(3);
        REQUIRE(test.peek() == 1);
        test.dequeue();
        REQUIRE(test.peek() == 2);
        test.enqueue(10);
        REQUIRE(test.peek() == 2);
        test.dequeue();
        REQUIRE(test.peek() == 3);
        test.dequeue();
        REQUIRE(test.peek() == 10);
        test.dequeue();
        REQUIRE(test.isEmpty() == true);

    }

}
