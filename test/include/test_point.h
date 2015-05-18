#ifndef TESTPOINT_H
#define TESTPOINT_H

#include <gtest/gtest.h>
#include <core/point.h>

TEST(Point, Constructors) {
	Point p;
	// Default constructor returns origin
	p = Point();
	ASSERT_FLOAT_EQ(0, p.x());
	ASSERT_FLOAT_EQ(0, p.y());
	ASSERT_FLOAT_EQ(0, p.z());

	// Two arg constructor returns point on 0-plane
	for (float fx = -1.0f; fx < 1.0f; fx += 0.1f) {
		for (float fy = -1.0f; fy < 1.0f; fy += 0.1f) {
			p = Point(fx, fy);
			ASSERT_FLOAT_EQ(fx, p.x());
			ASSERT_FLOAT_EQ(fy, p.y());
			ASSERT_FLOAT_EQ(0, p.z());
		}
	}

	// Three arg constructor returns point in 3D space
	for (float fx = -1.0f; fx < 1.0f; fx += 0.1f) {
		for (float fy = -1.0f; fy < 1.0f; fy += 0.1f) {
			for (float fz = -1.0f; fz < 1.0f; fz += 0.1f) {
				p = Point(fx, fy, fz);
				ASSERT_FLOAT_EQ(fx, p.x());
				ASSERT_FLOAT_EQ(fy, p.y());
				ASSERT_FLOAT_EQ(fz, p.z());
			}
		}
	}
}

TEST(Point, Equality) {
	Point p;

	p = Point(1, 0, 0);
	ASSERT_TRUE((p == p));
	ASSERT_TRUE((p == Point(1, 0, 0)));
	ASSERT_TRUE((Point(1, 0, 0) == Point(1, 0, 0)));

	p = Point(4, 5, 6);
	ASSERT_TRUE((p == p));
	ASSERT_TRUE((p == Point(4, 5, 6)));
	ASSERT_TRUE((Point(4, 5, 6) == Point(4, 5, 6)));
}

TEST(Point, PointPointAddition) {
	Point p1, p2, p;

	p1 = Point(1, 2, 3);
	p2 = Point(4, 5, 6);

	// Check addition identity
	p = p1 + Point(0, 0, 0);
	ASSERT_TRUE((p == Point(1, 2, 3)));

	p = p2 + Point(0, 0, 0);
	ASSERT_TRUE((p == Point(4, 5, 6)));

	// Check result of addition
	p = p1 + p2;
	ASSERT_TRUE((p == Point(5, 7, 9)));

	// Check addition is commutative
	ASSERT_TRUE(((p1 + p2) == (p2 + p1)));
}

TEST(Point, IndexAccessor) {
	Point p;
	p = Point(5, 6);
	ASSERT_FLOAT_EQ(p[0], 5);
	ASSERT_FLOAT_EQ(p[1], 6);
	ASSERT_FLOAT_EQ(p[2], 0);

	p = Point(1, 2, 3);
	ASSERT_FLOAT_EQ(p[0], 1);
	ASSERT_FLOAT_EQ(p[1], 2);
	ASSERT_FLOAT_EQ(p[2], 3);
}


#endif // TESTPOINT_H
