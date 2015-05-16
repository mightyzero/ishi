#ifndef TEST_TESTMATH_H
#define TEST_TESTMATH_H

#include <gtest/gtest.h>
#include <core/math.h>

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

TEST(eq, CorrectResult) {
	// Integer comparison
	EXPECT_TRUE(eq(1, 1));
	EXPECT_TRUE(eq(0, 0));
	EXPECT_TRUE(eq(-0, -0));
	EXPECT_TRUE(eq(-1, -1));
	EXPECT_TRUE(eq(2 + 3, 1 + 4));
	EXPECT_TRUE(eq(6 - 10, -4));
	EXPECT_TRUE(eq(9 / 3, 3));
	EXPECT_TRUE(eq(9 / 2, 4));

	EXPECT_FALSE(eq(1, 2));
	EXPECT_FALSE(eq(10 - 9, 0));

	// Floating point comparison
	EXPECT_TRUE(eq(1.0f, 1.0f));
	EXPECT_TRUE(eq(0.0f, 0.0f));
	EXPECT_TRUE(eq(-0.0f, 0.0f));
	EXPECT_TRUE(eq(-1.0f, -1.0f));
	EXPECT_TRUE(eq(1.0f / 3.0f * 3.0f, 1.0f));
	EXPECT_TRUE(eq(12.0f * 5.0f, 3.0f * 20.0f));

	EXPECT_FALSE(eq(1.0f, 1.1f));

	// Floating point inexactness from calculations (YMMV)
	float f = 0.1f;
	float sum = 0;

	for (int i = 0; i < 10; ++i)
    sum += f;
	float product = f * 10;

	EXPECT_TRUE(eq(sum, product));
	EXPECT_TRUE(eq(product, f * 10));
}

#endif  // TEST_TESTMATH_H
