#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include<iostream>
#include <CircleQueue/CircleQueue.hpp>
#include"doctest.h"
#include <cstdint>

TEST_CASE("Constructor CircleQueue") {
    SUBCASE("Default constructor") {
        capacity = 8;
        CircleQueue<int> Queue;
        CHECK(Queue.empty());
    }
}
TEST_CASE("Push, Empty and Top") {
    SUBCASE("Push and Top) {
        capacity = 8;
        CircleQueue<int> Queue;
        Queue.push(1);
        Queue.push(3);
        Queue.push(2);
        CHECK(Queue.getSize() == 3);
        CHECK(Queue.top() == 1);
        CHECK(Queue.top() == 3);
        CHECK(Queue.top() == 2);
        CHECK(Queue.getSize() == 0);
    }
    SUBCASE("Top and Empty with empty queue") {
        capacity = 8;
        CircleQueue<int> Queue;
        CHECK_THROWS_WITH(Queue.top(), "Memory empty");
        Queue.push(1);
        CHECK(Queue.top() == 1);
        CHECK(Queue.empty());
        CHECK_THROWS_WITH(Queue.top(), "Memory empty");
    }
}

TEST_CASE("getSize") {
    SUBCASE("Size == 1"){
        capacity = 1;
        CircleQueue<int> Queue;
        Queue.push(3);
        CHECK(Queue.getSize() == 1);
    }
    SUBCASE("Size == 6") {
        capacity = 8;
        CircleQueue<int> Queue;
        Queue.push(3);
        Queue.push(3);
        Queue.push(3);
        Queue.push(3);
        Queue.push(3);
        Queue.push(3);
        CHECK(Queue.getSize() == 6);
    }
    SUBCASE("Check on Cyclicity") {
        capacity = 8;
        CircleQueue<int> Queue;
        Queue.push(0);
        Queue.push(1);
        Queue.push(2);
        Queue.push(3);
        Queue.push(4);
        Queue.push(5);
        Queue.push(6);
        Queue.push(7);
        CHECK(Queue.getSize() == 8);
        CHECK(Queue.top() == 0);
        CHECK(Queue.top() == 1);
        CHECK(Queue.top() == 2);
        Queue.push(8);
        Queue.push(9);
        CHECK(Queue.getSize() == 7);
    }
}
TEST_CASE("getFront and getBack") {
    capacity = 8;
    CircleQueue<int> Queue;
    Queue.push(0);
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    CHECK(Queue.getFront() == 0);
    CHECK(Queue.getBack() == 3);
    CHECK(Queue.top() == 0);
    CHECK(Queue.getFront() == 1);
    CHECK(Queue.getSize == 3);
}
TEST_CASE("Operators") {
    capacity = 8;
    CircleQueue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue += Queue;
    CHECK(*end == 5);
    Queue.push(7);
    Queue -= Queue;
    CHECK(*end == 6);
}