#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stackarr/stackarr.hpp>

#include <cstdint>



TEST_CASE("array") {
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
}
TEST_CASE("delete") {
}

TEST_CASE("StackArrT<T>&") {
}

TEST_CASE("StackArrT<T>&&") {
}

TEST_CASE("Initializer_list<T>&") {
}

TEST_CASE("Push") {
}

TEST_CASE("Pop") {
}

TEST_CASE("Top") {
}

TEST_CASE("Swap") {
}

TEST_CASE("Merge") {
}

TEST_CASE("Empty") {
}

TEST_CASE("Size") {
}

TEST_CASE("operator==") {
}

TEST_CASE("operator!=") {
}

TEST_CASE("operator= with &") {
}

TEST_CASE("operator= with &&") {
}


