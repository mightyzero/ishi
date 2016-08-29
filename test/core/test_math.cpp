#ifndef TEST_TESTMATH_H
#define TEST_TESTMATH_H

#include <catch/catch.hpp>
#include <core/math.h>

TEST_CASE("sum", "shoudl give correct result") {
	CHECK(sum(1) == 1);
	CHECK(sum(1, 2) == 3);
	CHECK(sum(1, 2, 3) == 6);
	CHECK(sum(1, 2, 3, 4) == 10);
}

TEST_CASE("product", "should give correct result") {
	CHECK(product(1) == 1);
	CHECK(product(1, 2) == 2);
	CHECK(product(1, 2, 3) == 6);
	CHECK(product(1, 2, 3, 4) == 24);
}

TEST_CASE("count", "should give correct result") {
	CHECK(count(1) == 1);
	CHECK(count(1, 2) == 2);
	CHECK(count(1, 2, 3) == 3);
	CHECK(count(1, 2, 3, 4) == 4);
}

TEST_CASE("eq", "[hide]") {
	SECTION("integer comparison", "should give correct result") {
		CHECK(eq(1, 1));
		CHECK(eq(0, 0));
		CHECK(eq(-0, -0));
		CHECK(eq(-1, -1));
		CHECK(eq(2 + 3, 1 + 4));
		CHECK(eq(6 - 10, -4));
		CHECK(eq(9 / 3, 3));
		CHECK(eq(9 / 2, 4));

		CHECK_FALSE(eq(1, 2));
		CHECK_FALSE(eq(10 - 9, 0));
	}

	SECTION("floating point comparison", "should give correct result") {
		CHECK(eq(1.0f, 1.0f));
		CHECK(eq(0.0f, 0.0f));
		CHECK(eq(-0.0f, 0.0f));
		CHECK(eq(-1.0f, -1.0f));
		CHECK(eq(1.0f / 3.0f * 3.0f, 1.0f));
		CHECK(eq(12.0f * 5.0f, 3.0f * 20.0f));

		CHECK_FALSE(eq(1.0f, 1.1f));
	}

	SECTION("floating point comparison after calculations") {
		float f = 0.1f;
		float sum = 0;

		for (int i = 0; i < 10; ++i)
			sum += f;
		float product = f * 10;

		CHECK(eq(sum, product));
		CHECK(eq(product, f * 10));
	}
}

#endif  // TEST_TESTMATH_H
