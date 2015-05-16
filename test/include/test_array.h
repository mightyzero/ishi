#ifndef TEST_TESTARRAY_H
#define TEST_TESTARRAY_H

#include <gtest/gtest.h>
#include <core/Array.h>
#include <core/Exceptions.h>

TEST(Array, DefaultConstruction) {
	Array<float,  1> 	   array1;
	Array<int,    2, 2>    array2;
	Array<double, 3, 3, 3> array3;
}

TEST(Array, InitializerListConstruction) {
	Array<float, 3> array1 { 1.0f, 2.0f, 3.0f };
	EXPECT_FLOAT_EQ(1.0f, array1(0));
	EXPECT_FLOAT_EQ(2.0f, array1(1));
	EXPECT_FLOAT_EQ(3.0f, array1(2));

	Array<double, 3, 3> array2 { 1.0, 2.0, 3.0,
                               4.0, 5.0, 6.0,
                               7.0, 8.0, 9.0 };
	EXPECT_DOUBLE_EQ(1.0, array2(0, 0));
	EXPECT_DOUBLE_EQ(2.0, array2(0, 1));
	EXPECT_DOUBLE_EQ(3.0, array2(0, 2));
	EXPECT_DOUBLE_EQ(4.0, array2(1, 0));
	EXPECT_DOUBLE_EQ(5.0, array2(1, 1));
	EXPECT_DOUBLE_EQ(6.0, array2(1, 2));
	EXPECT_DOUBLE_EQ(7.0, array2(2, 0));
	EXPECT_DOUBLE_EQ(8.0, array2(2, 1));
	EXPECT_DOUBLE_EQ(9.0, array2(2, 2));
}

TEST(Array, VariadicTemplateConstructor) {
	Array<float, 3> array1( 1.0f, 2.0f, 3.0f );
	EXPECT_FLOAT_EQ(1.0f, array1(0));
	EXPECT_FLOAT_EQ(2.0f, array1(1));
	EXPECT_FLOAT_EQ(3.0f, array1(2));

	Array<double, 3, 3> array2( 1.0, 2.0, 3.0,
	                            4.0, 5.0, 6.0,
	                            7.0, 8.0, 9.0 );
	EXPECT_DOUBLE_EQ(1.0, array2(0, 0));
	EXPECT_DOUBLE_EQ(2.0, array2(0, 1));
	EXPECT_DOUBLE_EQ(3.0, array2(0, 2));
	EXPECT_DOUBLE_EQ(4.0, array2(1, 0));
	EXPECT_DOUBLE_EQ(5.0, array2(1, 1));
	EXPECT_DOUBLE_EQ(6.0, array2(1, 2));
	EXPECT_DOUBLE_EQ(7.0, array2(2, 0));
	EXPECT_DOUBLE_EQ(8.0, array2(2, 1));
	EXPECT_DOUBLE_EQ(9.0, array2(2, 2));
}

#endif  // TEST_TESTARRAY_H
