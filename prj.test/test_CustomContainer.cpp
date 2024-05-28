#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <CustomContainer/CustomContainer.hpp>


TEST_CASE("Container") {
	CustomContainer container;
	container.add({1, 2});
	container.add({3, 4});
	container.add({2, 3});
	CHECK(container.contains({1, 2}));
	container.remove({1, 2});
	CHECK(!container.contains({2, 2}));
	CHECK(!container.contains({1, 2}));
}