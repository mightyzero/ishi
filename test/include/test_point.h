#ifndef TESTPOINT_H
#define TESTPOINT_H

#include <gtest/gtest.h>
#include <core/point.h>

namespace nf {
	/** Test default constructor returns origin. */
	TEST(Point, DefaultConstructor) {
		Point p = Point();
		EXPECT_FLOAT_EQ(0, p.x());
		EXPECT_FLOAT_EQ(0, p.y());
		EXPECT_FLOAT_EQ(0, p.z());
	}

	/** Test two arg constructor returns point on 0-plane. */
	TEST(Point, TwoArgConstructor) {
		Point p = Point(3.6, -5.2);
		EXPECT_FLOAT_EQ(3.6, p.x());
		EXPECT_FLOAT_EQ(-5.2, p.y());
		EXPECT_FLOAT_EQ(0, p.z());
	}

	/** Test three arg constructor returns point in 3D space. */
	TEST(Point, ThreeArgConstructor) {
		Point p = Point(3.6, -5.2, 7.4);
		EXPECT_FLOAT_EQ(3.6, p.x());
		EXPECT_FLOAT_EQ(-5.2, p.y());
		EXPECT_FLOAT_EQ(7.4, p.z());
	}

	/** Test point equality comparison. */
	TEST(Point, EqualityComparison) {
		Point p;

		p = Point(1, 0, 0);
		EXPECT_TRUE((p == p));
		EXPECT_TRUE((p == Point(1, 0, 0)));
		EXPECT_TRUE((Point(1, 0, 0) == Point(1, 0, 0)));

		p = Point(4, 5, 6);
		EXPECT_TRUE((p == p));
		EXPECT_TRUE((p == Point(4, 5, 6)));
		EXPECT_TRUE((Point(4, 5, 6) == Point(4, 5, 6)));
	}

	/** Test that adding points together adds the respective components. */
	TEST(Point, PointPointAddition) {
		Point p1, p2, p;

		p1 = Point(1, 2, 3);
		p2 = Point(4, 5, 6);

		// Check addition identity
		p = p1 + Point(0, 0, 0);
		EXPECT_TRUE((p == Point(1, 2, 3)));

		p = p2 + Point(0, 0, 0);
		EXPECT_TRUE((p == Point(4, 5, 6)));

		// Check result of addition
		p = p1 + p2;
		EXPECT_TRUE((p == Point(5, 7, 9)));

		// Check addition is commutative
		EXPECT_TRUE(((p1 + p2) == (p2 + p1)));
	}

	/** Test index accessor returns point components. */
	TEST(Point, IndexAccessor) {
		Point p;
		p = Point(5, 6);
		EXPECT_FLOAT_EQ(p[0], 5);
		EXPECT_FLOAT_EQ(p[1], 6);
		EXPECT_FLOAT_EQ(p[2], 0);

		p = Point(1, 2, 3);
		EXPECT_FLOAT_EQ(p[0], 1);
		EXPECT_FLOAT_EQ(p[1], 2);
		EXPECT_FLOAT_EQ(p[2], 3);
	}

}

#endif // TESTPOINT_H
