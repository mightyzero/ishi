#ifndef TESTMATRIX_H
#define TESTMATRIX_H

#include <gtest/gtest.h>
#include <core/Matrix.h>

TEST(Matrix, DefaultConstructor) {
	Matrix<int, 3, 3> m1;
	Matrix<float, 4, 4> m2;
	Matrix<double, 3, 4> m3;
}

TEST(Matrix, Assignment) {
	Matrix<int,3,3> m { 1, 1, 1,
	                    2, 2, 2,
	                    3, 3, 3 };
	EXPECT_EQ(1, m(0, 0));
	EXPECT_EQ(1, m(0, 1));
	EXPECT_EQ(1, m(0, 2));
	EXPECT_EQ(2, m(1, 0));
	EXPECT_EQ(2, m(1, 1));
	EXPECT_EQ(2, m(1, 2));
	EXPECT_EQ(3, m(2, 0));
	EXPECT_EQ(3, m(2, 1));
	EXPECT_EQ(3, m(2, 2));

	Matrix<float, 3, 3> m2 {
		8.0f, 7.5f, 7.0f,
		6.5f, 6.0f, 5.5f,
		5.0f, 4.5f, 4.0f
	};
	EXPECT_FLOAT_EQ(8.0f, m2(0, 0));
	EXPECT_FLOAT_EQ(7.5f, m2(0, 1));
	EXPECT_FLOAT_EQ(7.0f, m2(0, 2));
	EXPECT_FLOAT_EQ(6.5f, m2(1, 0));
	EXPECT_FLOAT_EQ(6.0f, m2(1, 1));
	EXPECT_FLOAT_EQ(5.5f, m2(1, 2));
	EXPECT_FLOAT_EQ(5.0f, m2(2, 0));
	EXPECT_FLOAT_EQ(4.5f, m2(2, 1));
	EXPECT_FLOAT_EQ(4.0f, m2(2, 2));
}

TEST(Matrix, ScalarMultiply) {
	Matrix<int, 3, 3> m1, m2, m3;
	m1 = { 1, 0, 0,
	       0, 1, 0,
	       0, 0, 1 };
	m2 = { 2, 0, 0,
	       0, 2, 0,
	       0, 0, 2 };
	ASSERT_TRUE(m1 * 2 == m2);
	ASSERT_TRUE(2 * m1 == m2);

	// m1 = 1, 2, 3,
	//      4, 5, 6,
	//      7, 8, 9;
	// m2 =  3,  6,  9,
	//      12, 15, 18,
	//      21, 24, 27;
	// ASSERT_TRUE(m1 * 3 == m2);
	// ASSERT_TRUE(3 * m1 == m2);
}

// TEST(Matrix, MatrixMultiply) {
// 	Matrix<float, 4, 4> i, m1, m2, m3, m4, r1, r2;

// 	// Product of a matrix and an identity matrix is itself
// 	// Product of an identity matrix and a matrix is that matrix
// 	i = 1.0f, 0.0f, 0.0f, 0.0f,
// 	    0.0f, 1.0f, 0.0f, 0.0f,
// 	    0.0f, 0.0f, 1.0f, 0.0f,
// 	    0.0f, 0.0f, 0.0f, 1.0f,
// 	m1 = 1.0f, 2.0f, 3.0f, 4.0f,
// 	     5.0f, 6.0f, 7.0f, 8.0f,
// 	     1.5f, 2.6f, 3.7f, 4.8f,
// 	     5.1f, 6.2f, 7.3f, 8.4f;
// 	m2 = m1 * i;
// 	m3 = i * m1;

// 	EXPECT_FLOAT_EQ(m1(0,) m2(0));
// 	EXPECT_FLOAT_EQ(m1(1,) m2(1));
// 	EXPECT_FLOAT_EQ(m1(2,) m2(2));
// 	EXPECT_FLOAT_EQ(m1(3,) m2(3));
// 	EXPECT_FLOAT_EQ(m1(4,) m2(4));
// 	EXPECT_FLOAT_EQ(m1(5,) m2(5));
// 	EXPECT_FLOAT_EQ(m1(6,) m2(6));
// 	EXPECT_FLOAT_EQ(m1(7,) m2(7));
// 	EXPECT_FLOAT_EQ(m1(8,) m2(8));
// 	EXPECT_FLOAT_EQ(m1(9,) m2(9));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m2(1]));

// 	EXPECT_FLOAT_EQ(m1(0,) m3(0));
// 	EXPECT_FLOAT_EQ(m1(1,) m3(1));
// 	EXPECT_FLOAT_EQ(m1(2,) m3(2));
// 	EXPECT_FLOAT_EQ(m1(3,) m3(3));
// 	EXPECT_FLOAT_EQ(m1(4,) m3(4));
// 	EXPECT_FLOAT_EQ(m1(5,) m3(5));
// 	EXPECT_FLOAT_EQ(m1(6,) m3(6));
// 	EXPECT_FLOAT_EQ(m1(7,) m3(7));
// 	EXPECT_FLOAT_EQ(m1(8,) m3(8));
// 	EXPECT_FLOAT_EQ(m1(9,) m3(9));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m1(1]), m3(1]));

// 	m2 = 1.0f, 2.0f, 3.0f, 4.0f,
// 	     5.0f, 6.0f, 7.0f, 8.0f,
// 	     9.0f, 0.0f, 1.0f, 2.0f,
// 	     3.0f, 4.0f, 5.0f, 6.0f;
// 	r1 =  50.0f, 30.0f,  40.0f,  50.0f,
// 		122.0f, 78.0f, 104.0f, 130.0f,
// 		 62.2f, 37.8f,  50.4f,  63.0f,
// 		127.0f, 81.0f, 108.0f, 135.0f;
// 	m3 = m1 * m2;

// 	EXPECT_FLOAT_EQ(r1(0,) m3(0));
// 	EXPECT_FLOAT_EQ(r1(1,) m3(1));
// 	EXPECT_FLOAT_EQ(r1(2,) m3(2));
// 	EXPECT_FLOAT_EQ(r1(3,) m3(3));
// 	EXPECT_FLOAT_EQ(r1(4,) m3(4));
// 	EXPECT_FLOAT_EQ(r1(5,) m3(5));
// 	EXPECT_FLOAT_EQ(r1(6,) m3(6));
// 	EXPECT_FLOAT_EQ(r1(7,) m3(7));
// 	EXPECT_FLOAT_EQ(r1(8,) m3(8));
// 	EXPECT_FLOAT_EQ(r1(9,) m3(9));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(r1(1]), m3(1]));

// 	// The transpose of the product of 2 matrices is the product of the
// 	// transposes of these same matrices, multiplied in reverse order.
// 	m4 = transpose(m1 * m2);
// 	r2 = transpose(m2) * transpose(m1);

// 	EXPECT_FLOAT_EQ(r2(0,) m4(0));
// 	EXPECT_FLOAT_EQ(r2(1,) m4(1));
// 	EXPECT_FLOAT_EQ(r2(2,) m4(2));
// 	EXPECT_FLOAT_EQ(r2(3,) m4(3));
// 	EXPECT_FLOAT_EQ(r2(4,) m4(4));
// 	EXPECT_FLOAT_EQ(r2(5,) m4(5));
// 	EXPECT_FLOAT_EQ(r2(6,) m4(6));
// 	EXPECT_FLOAT_EQ(r2(7,) m4(7));
// 	EXPECT_FLOAT_EQ(r2(8,) m4(8));
// 	EXPECT_FLOAT_EQ(r2(9,) m4(9));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// 	EXPECT_FLOAT_EQ(r2(1]), m4(1]));
// }

// TEST(Matrix, Equality) {
// 	Matrix<int, 3, 3> m4 {
// 		1, 1, 1,
// 		2, 2, 2,
// 		3, 3, 3
// 	};
// 	ASSERT_TRUE(m4 == m4);
// 	ASSERT_FALSE(m4 != m4);

// 	Matrix<int, 3, 3> m5;
// 	m5 = 1, 1, 1,
// 	     2, 2, 2,
// 		 3, 3, 3;
// 	ASSERT_TRUE(m4 == m5);
// 	ASSERT_FALSE(m4 != m5);

// 	Matrix<int, 3, 3> m6;
// 	m6 = 4, 4, 4,
// 	     5, 5, 5,
// 		 6, 6, 6;
// 	ASSERT_FALSE(m4 == m6);
// 	ASSERT_TRUE(m4 != m6);
// }

// TEST(Matrix, Transpose) {
// 	Matrix<float, 4, 4> m1, m2, m3, mi, t_mi;

// 	// Transpose of identity matrix is itself
// 	mi = 1.0f, 0.0f, 0.0f, 0.0f,
// 	     0.0f, 1.0f, 0.0f, 0.0f,
// 		 0.0f, 0.0f, 1.0f, 0.0f,
// 		 0.0f, 0.0f, 0.0f, 1.0f;
// 	t_mi = transpose(mi);
// 	EXPECT_FLOAT_EQ(mi(0,) t_mi(0));
// 	EXPECT_FLOAT_EQ(mi(1,) t_mi(1));
// 	EXPECT_FLOAT_EQ(mi(2,) t_mi(2));
// 	EXPECT_FLOAT_EQ(mi(3,) t_mi(3));
// 	EXPECT_FLOAT_EQ(mi(4,) t_mi(4));
// 	EXPECT_FLOAT_EQ(mi(5,) t_mi(5));
// 	EXPECT_FLOAT_EQ(mi(6,) t_mi(6));
// 	EXPECT_FLOAT_EQ(mi(7,) t_mi(7));
// 	EXPECT_FLOAT_EQ(mi(8,) t_mi(8));
// 	EXPECT_FLOAT_EQ(mi(9,) t_mi(9));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));
// 	EXPECT_FLOAT_EQ(mi(1]), t_mi(1]));

// 	// Check transpose for arbitrary matrix
// 	m1 = 1.f, 2.f, 3.f, 4.f,
// 		5.f, 6.f, 7.f, 8.f,
// 		1.5, 2.6, 3.7, 4.8,
// 		5.1, 6.2, 7.3, 8.4;
// 	m2 = 1.f, 5.f, 1.5, 5.1,
// 		2.f, 6.f, 2.6, 6.2,
// 		3.f, 7.f, 3.7, 7.3,
// 		4.f, 8.f, 4.8, 8.4;
// 	m3 = transpose(m1);
// 	EXPECT_FLOAT_EQ(m2(0,) m3(0));
// 	EXPECT_FLOAT_EQ(m2(1,) m3(1));
// 	EXPECT_FLOAT_EQ(m2(2,) m3(2));
// 	EXPECT_FLOAT_EQ(m2(3,) m3(3));
// 	EXPECT_FLOAT_EQ(m2(4,) m3(4));
// 	EXPECT_FLOAT_EQ(m2(5,) m3(5));
// 	EXPECT_FLOAT_EQ(m2(6,) m3(6));
// 	EXPECT_FLOAT_EQ(m2(7,) m3(7));
// 	EXPECT_FLOAT_EQ(m2(8,) m3(8));
// 	EXPECT_FLOAT_EQ(m2(9,) m3(9));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// 	EXPECT_FLOAT_EQ(m2(1]), m3(1]));
// }

#endif // TESTMATRIX_H
