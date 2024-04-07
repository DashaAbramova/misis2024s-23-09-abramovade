#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("Rational input/output") {
	Rational t(1, 2);
	std::ostringstream output;
	output << t;
	CHECK(output.str() == "1/2");
	Rational m(5, 3);
	std::istringstream input;
	input >> m;
	CHECK(m == Rational(5, 3));
}


TEST_CASE("rational ctor") {
	Rational r_def;
	CHECK(0 == r_def.num());
	CHECK(1 == r_def.den());

	Rational r_int(3);
	CHECK(3 == r_int.num());
	CHECK(1 == r_int.den());

	Rational r_constr(7, -3);
	CHECK(-7 == r_constr.num());
	CHECK(3 == r_constr.den());

	Rational unreduced(8, 4);
	CHECK(2 == unreduced.num());
	CHECK(1 == unreduced.den());

	CHECK_THROWS(void(Rational(1, 0)));
}

TEST_CASE("comparesent") {
	Rational rhs{ 4, 9 };
	Rational lhs{ 2, 3 };
	CHECK((rhs > lhs) == false);
	CHECK((rhs < lhs) == true);
	CHECK((rhs == lhs) == false);
	CHECK((rhs != lhs) == true);
}

TEST_CASE("math") {
	Rational r_num1(2, 7);
	Rational r_num2(7, 3);
	CHECK(r_num1 + r_num2 == Rational{ 55, 21 });
	CHECK(r_num1 - r_num2 == Rational{ -43, 21 });
	CHECK(r_num1 * r_num2 == Rational{ 2, 3 });
	CHECK(r_num1 / r_num2 == Rational{ 6, 49 });
}