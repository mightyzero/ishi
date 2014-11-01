#ifndef TEST_TESTARRAY_H
#define TEST_TESTARRAY_H

#include <gtest/gtest.h>
#include <core/Array.h>

TEST(Array, DefaultConstruction) {
	Array<float,  1> 	   array1;
	Array<int,    2, 2>    array2;
	Array<double, 3, 3, 3> array3;
}

TEST(Array, InitializationConstruction) {
	Array<float, 3>     array1({ 1.0f, 2.0f, 3.0f });
	Array<double, 3, 3> array2({ 1.0, 0.0, 0.0,
	                             0.0, 1.0, 0.0,
	                             0.0, 0.0, 1.0});
}

#endif  // TEST_TESTARRAY_H