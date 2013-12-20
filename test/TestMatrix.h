#ifndef TESTMATRIX_H
#define TESTMATRIX_H

#include <gtest/gtest.h>
#include <core/Matrix.h>

TEST(Matrix, Constructor) {
	Matrix<int, 3, 3> m1;
	Matrix<float, 4, 4> m2;
	Matrix<double, 3, 4> m3;
}

TEST(Matrix, Assignment) {
	Matrix<int,3,3> m;
	m = 1, 1, 1,
	    2, 2, 2,
	    3, 3, 3;
	ASSERT_EQ(1, m.data()[0]);
	ASSERT_EQ(1, m.data()[1]);
	ASSERT_EQ(1, m.data()[2]);
	ASSERT_EQ(2, m.data()[3]);
	ASSERT_EQ(2, m.data()[4]);
	ASSERT_EQ(2, m.data()[5]);
	ASSERT_EQ(3, m.data()[6]);
	ASSERT_EQ(3, m.data()[7]);
	ASSERT_EQ(3, m.data()[8]);

	Matrix<float, 3, 3> m2;
	m2 = 8.0f, 7.5f, 7.0f,
	     6.5f, 6.0f, 5.5f,
	     5.0f, 4.5f, 4.0f;
	ASSERT_FLOAT_EQ(8.0f, m2.data()[0]);
	ASSERT_FLOAT_EQ(7.5f, m2.data()[1]);
	ASSERT_FLOAT_EQ(7.0f, m2.data()[2]);
	ASSERT_FLOAT_EQ(6.5f, m2.data()[3]);
	ASSERT_FLOAT_EQ(6.0f, m2.data()[4]);
	ASSERT_FLOAT_EQ(5.5f, m2.data()[5]);
	ASSERT_FLOAT_EQ(5.0f, m2.data()[6]);
	ASSERT_FLOAT_EQ(4.5f, m2.data()[7]);
	ASSERT_FLOAT_EQ(4.0f, m2.data()[8]);
}

TEST(Matrix, Equality) {
	Matrix<int, 3, 3> m4;
	m4 = 1, 1, 1,
	     2, 2, 2,
		 3, 3, 3;
	ASSERT_TRUE(m4 == m4);
	ASSERT_FALSE(m4 != m4);
	
	Matrix<int, 3, 3> m5;
	m5 = 1, 1, 1,
	     2, 2, 2,
		 3, 3, 3;
	ASSERT_TRUE(m4 == m5);
	ASSERT_FALSE(m4 != m5);

	Matrix<int, 3, 3> m6;
	m6 = 4, 4, 4,
	     5, 5, 5,
		 6, 6, 6;
	ASSERT_FALSE(m4 == m6);
	ASSERT_TRUE(m4 != m6);
}

TEST(Matrix, Transpose) {
	Matrix<float, 4, 4> m1, m2, m3, mi, t_mi;

	// Transpose of identity matrix is itself
	mi = 1.0f, 0.0f, 0.0f, 0.0f,
	     0.0f, 1.0f, 0.0f, 0.0f,
		 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f;
	t_mi = transpose(mi);
	ASSERT_FLOAT_EQ(mi.data()[0], t_mi.data()[0]);
	ASSERT_FLOAT_EQ(mi.data()[1], t_mi.data()[1]);
	ASSERT_FLOAT_EQ(mi.data()[2], t_mi.data()[2]);
	ASSERT_FLOAT_EQ(mi.data()[3], t_mi.data()[3]);
	ASSERT_FLOAT_EQ(mi.data()[4], t_mi.data()[4]);
	ASSERT_FLOAT_EQ(mi.data()[5], t_mi.data()[5]);
	ASSERT_FLOAT_EQ(mi.data()[6], t_mi.data()[6]);
	ASSERT_FLOAT_EQ(mi.data()[7], t_mi.data()[7]);
	ASSERT_FLOAT_EQ(mi.data()[8], t_mi.data()[8]);
	ASSERT_FLOAT_EQ(mi.data()[9], t_mi.data()[9]);
	ASSERT_FLOAT_EQ(mi.data()[10], t_mi.data()[10]);
	ASSERT_FLOAT_EQ(mi.data()[11], t_mi.data()[11]);
	ASSERT_FLOAT_EQ(mi.data()[12], t_mi.data()[12]);
	ASSERT_FLOAT_EQ(mi.data()[13], t_mi.data()[13]);
	ASSERT_FLOAT_EQ(mi.data()[14], t_mi.data()[14]);
	ASSERT_FLOAT_EQ(mi.data()[15], t_mi.data()[15]);

	// Check transpose for arbitrary matrix
	m1 = 1.f, 2.f, 3.f, 4.f,
		5.f, 6.f, 7.f, 8.f,
		1.5, 2.6, 3.7, 4.8,
		5.1, 6.2, 7.3, 8.4;
	m2 = 1.f, 5.f, 1.5, 5.1,
		2.f, 6.f, 2.6, 6.2,
		3.f, 7.f, 3.7, 7.3,
		4.f, 8.f, 4.8, 8.4;
	m3 = transpose(m1);
	ASSERT_FLOAT_EQ(m2.data()[0], m3.data()[0]);
	ASSERT_FLOAT_EQ(m2.data()[1], m3.data()[1]);
	ASSERT_FLOAT_EQ(m2.data()[2], m3.data()[2]);
	ASSERT_FLOAT_EQ(m2.data()[3], m3.data()[3]);
	ASSERT_FLOAT_EQ(m2.data()[4], m3.data()[4]);
	ASSERT_FLOAT_EQ(m2.data()[5], m3.data()[5]);
	ASSERT_FLOAT_EQ(m2.data()[6], m3.data()[6]);
	ASSERT_FLOAT_EQ(m2.data()[7], m3.data()[7]);
	ASSERT_FLOAT_EQ(m2.data()[8], m3.data()[8]);
	ASSERT_FLOAT_EQ(m2.data()[9], m3.data()[9]);
	ASSERT_FLOAT_EQ(m2.data()[10], m3.data()[10]);
	ASSERT_FLOAT_EQ(m2.data()[11], m3.data()[11]);
	ASSERT_FLOAT_EQ(m2.data()[12], m3.data()[12]);
	ASSERT_FLOAT_EQ(m2.data()[13], m3.data()[13]);
	ASSERT_FLOAT_EQ(m2.data()[14], m3.data()[14]);
	ASSERT_FLOAT_EQ(m2.data()[15], m3.data()[15]);
}

TEST(Matrix, ScalarMultiply) {
	Matrix<int, 3, 3> m1, m2, m3;
	m1 = 1, 0, 0,
	     0, 1, 0,
	     0, 0, 1;
	m2 = 2, 0, 0,
	     0, 2, 0,
	     0, 0, 2;
	ASSERT_TRUE(m1 * 2 == m2);
	ASSERT_TRUE(2 * m1 == m2);
	
	m1 = 1, 2, 3,
	     4, 5, 6,
	     7, 8, 9;
	m2 =  3,  6,  9,
	     12, 15, 18,
	     21, 24, 27;
	ASSERT_TRUE(m1 * 3 == m2);
	ASSERT_TRUE(3 * m1 == m2);
	
}

TEST(Matrix, MatrixMultiply) {
	Matrix<float, 4, 4> i, m1, m2, m3, m4, r1, r2;

	// Product of a matrix and an identity matrix is itself
	// Product of an identity matrix and a matrix is that matrix
	i = 1.0f, 0.0f, 0.0f, 0.0f,
	    0.0f, 1.0f, 0.0f, 0.0f,
	    0.0f, 0.0f, 1.0f, 0.0f,
	    0.0f, 0.0f, 0.0f, 1.0f,
	m1 = 1.0f, 2.0f, 3.0f, 4.0f,
	     5.0f, 6.0f, 7.0f, 8.0f,
	     1.5f, 2.6f, 3.7f, 4.8f,
	     5.1f, 6.2f, 7.3f, 8.4f;
	m2 = m1 * i;
	m3 = i * m1;

	ASSERT_FLOAT_EQ(m1.data()[0], m2.data()[0]);
	ASSERT_FLOAT_EQ(m1.data()[1], m2.data()[1]);
	ASSERT_FLOAT_EQ(m1.data()[2], m2.data()[2]);
	ASSERT_FLOAT_EQ(m1.data()[3], m2.data()[3]);
	ASSERT_FLOAT_EQ(m1.data()[4], m2.data()[4]);
	ASSERT_FLOAT_EQ(m1.data()[5], m2.data()[5]);
	ASSERT_FLOAT_EQ(m1.data()[6], m2.data()[6]);
	ASSERT_FLOAT_EQ(m1.data()[7], m2.data()[7]);
	ASSERT_FLOAT_EQ(m1.data()[8], m2.data()[8]);
	ASSERT_FLOAT_EQ(m1.data()[9], m2.data()[9]);
	ASSERT_FLOAT_EQ(m1.data()[10], m2.data()[10]);
	ASSERT_FLOAT_EQ(m1.data()[11], m2.data()[11]);
	ASSERT_FLOAT_EQ(m1.data()[12], m2.data()[12]);
	ASSERT_FLOAT_EQ(m1.data()[13], m2.data()[13]);
	ASSERT_FLOAT_EQ(m1.data()[14], m2.data()[14]);
	ASSERT_FLOAT_EQ(m1.data()[15], m2.data()[15]);
	
	ASSERT_FLOAT_EQ(m1.data()[0], m3.data()[0]);
	ASSERT_FLOAT_EQ(m1.data()[1], m3.data()[1]);
	ASSERT_FLOAT_EQ(m1.data()[2], m3.data()[2]);
	ASSERT_FLOAT_EQ(m1.data()[3], m3.data()[3]);
	ASSERT_FLOAT_EQ(m1.data()[4], m3.data()[4]);
	ASSERT_FLOAT_EQ(m1.data()[5], m3.data()[5]);
	ASSERT_FLOAT_EQ(m1.data()[6], m3.data()[6]);
	ASSERT_FLOAT_EQ(m1.data()[7], m3.data()[7]);
	ASSERT_FLOAT_EQ(m1.data()[8], m3.data()[8]);
	ASSERT_FLOAT_EQ(m1.data()[9], m3.data()[9]);
	ASSERT_FLOAT_EQ(m1.data()[10], m3.data()[10]);
	ASSERT_FLOAT_EQ(m1.data()[11], m3.data()[11]);
	ASSERT_FLOAT_EQ(m1.data()[12], m3.data()[12]);
	ASSERT_FLOAT_EQ(m1.data()[13], m3.data()[13]);
	ASSERT_FLOAT_EQ(m1.data()[14], m3.data()[14]);
	ASSERT_FLOAT_EQ(m1.data()[15], m3.data()[15]);

	m2 = 1.0f, 2.0f, 3.0f, 4.0f,
	     5.0f, 6.0f, 7.0f, 8.0f,
	     9.0f, 0.0f, 1.0f, 2.0f,
	     3.0f, 4.0f, 5.0f, 6.0f;
	r1 =  50.0f, 30.0f,  40.0f,  50.0f,
		122.0f, 78.0f, 104.0f, 130.0f,
		 62.2f, 37.8f,  50.4f,  63.0f,
		127.0f, 81.0f, 108.0f, 135.0f;
	m3 = m1 * m2;

	ASSERT_FLOAT_EQ(r1.data()[0], m3.data()[0]);
	ASSERT_FLOAT_EQ(r1.data()[1], m3.data()[1]);
	ASSERT_FLOAT_EQ(r1.data()[2], m3.data()[2]);
	ASSERT_FLOAT_EQ(r1.data()[3], m3.data()[3]);
	ASSERT_FLOAT_EQ(r1.data()[4], m3.data()[4]);
	ASSERT_FLOAT_EQ(r1.data()[5], m3.data()[5]);
	ASSERT_FLOAT_EQ(r1.data()[6], m3.data()[6]);
	ASSERT_FLOAT_EQ(r1.data()[7], m3.data()[7]);
	ASSERT_FLOAT_EQ(r1.data()[8], m3.data()[8]);
	ASSERT_FLOAT_EQ(r1.data()[9], m3.data()[9]);
	ASSERT_FLOAT_EQ(r1.data()[10], m3.data()[10]);
	ASSERT_FLOAT_EQ(r1.data()[11], m3.data()[11]);
	ASSERT_FLOAT_EQ(r1.data()[12], m3.data()[12]);
	ASSERT_FLOAT_EQ(r1.data()[13], m3.data()[13]);
	ASSERT_FLOAT_EQ(r1.data()[14], m3.data()[14]);
	ASSERT_FLOAT_EQ(r1.data()[15], m3.data()[15]);

	// The transpose of the product of 2 matrices is the product of the
	// transposes of these same matrices, multiplied in reverse order.
	m4 = transpose(m1 * m2);
	r2 = transpose(m2) * transpose(m1);

	ASSERT_FLOAT_EQ(r2.data()[0], m4.data()[0]);
	ASSERT_FLOAT_EQ(r2.data()[1], m4.data()[1]);
	ASSERT_FLOAT_EQ(r2.data()[2], m4.data()[2]);
	ASSERT_FLOAT_EQ(r2.data()[3], m4.data()[3]);
	ASSERT_FLOAT_EQ(r2.data()[4], m4.data()[4]);
	ASSERT_FLOAT_EQ(r2.data()[5], m4.data()[5]);
	ASSERT_FLOAT_EQ(r2.data()[6], m4.data()[6]);
	ASSERT_FLOAT_EQ(r2.data()[7], m4.data()[7]);
	ASSERT_FLOAT_EQ(r2.data()[8], m4.data()[8]);
	ASSERT_FLOAT_EQ(r2.data()[9], m4.data()[9]);
	ASSERT_FLOAT_EQ(r2.data()[10], m4.data()[10]);
	ASSERT_FLOAT_EQ(r2.data()[11], m4.data()[11]);
	ASSERT_FLOAT_EQ(r2.data()[12], m4.data()[12]);
	ASSERT_FLOAT_EQ(r2.data()[13], m4.data()[13]);
	ASSERT_FLOAT_EQ(r2.data()[14], m4.data()[14]);
	ASSERT_FLOAT_EQ(r2.data()[15], m4.data()[15]);
}

#endif // TESTMATRIX_H