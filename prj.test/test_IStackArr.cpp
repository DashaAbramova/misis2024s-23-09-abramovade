#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include"doctest.h"
#include <IStack/IStackArr.hpp>


TEST_CASE_TEMPLATE("[stackarrt] - Constructor", T, int, float, double, long long) {
    SUBCASE("Default constructor") {
        StackArr<T> defCtor;
        CHECK(defCtor.empty());
    }
    SUBCASE("Copy constructor") {
        StackArr<T> copyCtor;
        copyCtor.push(1);
        copyCtor.push(4);
        StackArr<T> copyCtor2(copyCtor);
        CHECK(!copyCtor2.empty());
        CHECK(copyCtor2.top() == 4);
        CHECK(copyCtor2.size() == 2);
    }
    SUBCASE("Move constructor") {
        StackArr<T> moveCtor;
        moveCtor.push(1);
        moveCtor.push(4);
        StackArr<T> moveCtor2(std::move(moveCtor));
        CHECK(!moveCtor2.empty());
        CHECK(moveCtor2.top() == 4);
        CHECK(moveCtor2.size() == 2);
    }
    SUBCASE("Copy constructor with empty list") {
        StackArr<T> copyCtor;
        StackArr<T> copyCtor2(copyCtor);
        CHECK(copyCtor2.empty());
    }
    SUBCASE("Initializer list constructor") {
        StackArr<T> initListCtor = { 1, 2, 6, 4 };
        CHECK(!initListCtor.empty());
        CHECK(initListCtor.top() == 4);
        CHECK(initListCtor.size() == 4);
    }
    SUBCASE("Move constructor with empty list") {
        StackArr<T> moveCtor;
        StackArr<T> moveCtor2(std::move(moveCtor));
        CHECK(moveCtor2.empty());
    }
    SUBCASE("Initializer list constructor with empty list") {
        StackArr<T> initListCtor{};
        CHECK(initListCtor.empty());
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Push, Pop and Top", T, int, float, double,
    long long) {
    SUBCASE("Push and Pop") {
        StackArr<T> s;
        s.push(3);
        s.push(1);
        s.push(2);
        CHECK(s.top() == 2);
        CHECK(s.size() == 3);
        s.pop();
        s.pop();
        CHECK(s.top() == 3);
        CHECK(s.size() == 1);
    }
    SUBCASE("Top and Pop with empty stack") {
        StackArr<T> s;
        CHECK_THROWS_WITH(s.pop(), "Empty stack.");
        CHECK_THROWS_WITH(s.top(), "Empty stack.");
        s.push(1);
        CHECK(s.top() == 1);
        CHECK(!s.empty());
        s.pop();
        CHECK_THROWS_WITH(s.pop(), "Empty stack.");
        CHECK_THROWS_WITH(s.top(), "Empty stack.");
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Compare", T, int, float, double, long long) {
    SUBCASE("Compare with non-empty stack") {
        StackArr<T> c1{ 2, 3, 1, 4 };
        StackArr<T> c2{ 2, 3, 1, 4 };
        StackArr<T> c3{ 5, 1, 2, 8 };
        CHECK(c1 == c2);
        CHECK(c1 != c3);
    }
    SUBCASE("Compare with empty stack") {
        StackArr<T> c1{ 2, 3, 1, 4 };
        StackArr<T> empty1;
        StackArr<T> empty2;
        CHECK(empty1 == empty2);
        CHECK(empty1 != c1);
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Swap and merge", T, int, float, double,
    long long) {
    SUBCASE("Swap") {
        StackArr<T> s1{ 2, 3, 1, 4 };
        StackArr<T> s1Cp{ 2, 3, 1, 4 };
        StackArr<T> s2{ 5, 1, 2, 8 };
        StackArr<T> s2Cp{ 5, 1, 2, 8 };
        StackArr<T> s3;
        s1.swap(s2);
        CHECK(s1 == s2Cp);
        CHECK(s2 == s1Cp);
        s1.swap(s3);
        CHECK(s1.empty());
        CHECK(s3 == s2Cp);
    }
    SUBCASE("Merge") {
        StackArr<T> s1{ 1, 2, 3, 4 };
        StackArr<T> s2{ 5, 6, 7, 8 };
        StackArr<T> merged{ 1, 2, 3, 4, 5, 6, 7, 8 };
        s1.merge(s2);
        CHECK(s1 == merged);
    }
    SUBCASE("Merge with empty stack") {
        StackArr<T> s1{ 1, 2, 3, 4 };
        StackArr<T> s1Copy{ 1, 2, 3, 4 };
        StackArr<T> s2;
        s1.merge(s2);
        CHECK(s1 == s1Copy);

        StackArr<T> s3;
        StackArr<T> s4 = { 5, 6, 7, 8 };
        StackArr<T> s3merged = { 5, 6, 7, 8 };
        s3.merge(s4);
        CHECK(s3 == s3merged);
    }
}

TEST_CASE_TEMPLATE("[stackarrt] - Assignment", T, int, float, double,
    long long) {
    StackArr<T> s1{ 2, 3, 1, 4 };
    StackArr<T> s2{ 5, 1, 2, 8 };
    s1 = s2;
    CHECK(s1 == s2);
    StackArr<T> s3;
    StackArr<T> s4 = { 5, 1, 2, 8 };
    s4 = s3;
    CHECK(s4.empty());
}

TEST_CASE_TEMPLATE("[stackarrt] - stream output", T, int, float, double,
long long) {
    StackArr<T> s{2, 3, 1, 4};
    std::ostringstream output;
    output << s;
    CHECK(output.str() == "[4, 1, 3, 2]");
}