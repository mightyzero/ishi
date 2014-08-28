#ifndef TESTARRAY_H
#define TESTARRAY_H

#include <gtest/gtest.h>
#include <core/Array.h>

TEST(Array, DefaultConstruction) {
	Array<float, 1> array1;
	Array<float, 2> array2;
}

TEST(Array, AllocConstruction) {
	Array<float, 1> array1(3);
	Array<float, 2> array2(4, 4);
	Array<float, 3> array3(1, 2, 3);	
}

#endif  // TESTARRAY_H