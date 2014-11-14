#ifndef TEST_TESTMATH_H
#define TEST_TESTMATH_H

#include <gtest/gtest.h>
#include <core/Math.h>

TEST(sum, CorrectResult) {
	EXPECT_EQ(1, sum(1));
	EXPECT_EQ(3, sum(1, 2));
	EXPECT_EQ(6, sum(1, 2, 3));
	EXPECT_EQ(10, sum(1, 2, 3, 4));
}

TEST(product, CorrectResult) {
	EXPECT_EQ(1, product(1));
	EXPECT_EQ(2, product(1, 2));
	EXPECT_EQ(6, product(1, 2, 3));
	EXPECT_EQ(24, product(1, 2, 3, 4));
}

TEST(count, CorrectResult) {
	EXPECT_EQ(1, count(1));
	EXPECT_EQ(2, count(1, 2));
	EXPECT_EQ(3, count(1, 2, 3));
	EXPECT_EQ(4, count(1, 2, 3, 4));
}


#endif  // TEST_TESTMATH_H
