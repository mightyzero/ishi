#include <catch/catch.hpp>
#include <core/point.h>
#include <core/vector.h>

namespace nf {
	TEST_CASE("Default constructor should return origin") {
		Point p = Point();
		CHECK(p.x() == 0);
		CHECK(p.y() == 0);
		CHECK(p.z() == 0);
	}

	TEST_CASE("Two arg constructor should return point on 0-plane") {
		Point p = Point(3.6f, -5.2f);
		CHECK(p.x() == 3.6f);
		CHECK(p.y() == -5.2f);
		CHECK(p.z() == 0);
	}

	TEST_CASE("Three arg constructor returns point in 3D space") {
		Point p = Point(3.6f, -5.2f, 7.4f);
		CHECK(p.x() == 3.6f);
		CHECK(p.y() == -5.2f);
		CHECK(p.z() == 7.4f);
	}

	TEST_CASE("Equality comparison should return correct result") {
		Point p;

		p = Point(1, 0, 0);
		CHECK((p == p));
		CHECK((p == Point(1, 0, 0)));
		CHECK((Point(1, 0, 0) == Point(1, 0, 0)));

		p = Point(4, 5, 6);
		CHECK((p == p));
		CHECK((p == Point(4, 5, 6)));
		CHECK((Point(4, 5, 6) == Point(4, 5, 6)));
	}

	TEST_CASE("Index accessor should return point components") {
		Point p;
		p = Point(5, 6);
		CHECK(p[0] == 5);
		CHECK(p[1] == 6);
		CHECK(p[2] == 0);

		p = Point(1, 2, 3);
		CHECK(p[0] == 1);
		CHECK(p[1] == 2);
		CHECK(p[2] == 3);
	}

	TEST_CASE("Adding points together should add the respective components") {
		Point p1, p2, p;

		p1 = Point(1, 2, 3);
		p2 = Point(4, 5, 6);

		// Check addition identity
		p = p1 + Point(0, 0, 0);
		CHECK((p == Point(1, 2, 3)));

		p = p2 + Point(0, 0, 0);
		CHECK((p == Point(4, 5, 6)));

		// Check result of addition
		p = p1 + p2;
		CHECK((p == Point(5, 7, 9)));

		// Check addition is commutative
		CHECK(((p1 + p2) == (p2 + p1)));
	}

	TEST_CASE("Adding vector to point should produce new point") {
		Point p = Point(3, -4, 5) + Vector(1, -2, -3);
		CHECK(p.x() == 4);
		CHECK(p.y() == -6);
		CHECK(p.z() == 2);
	}
}
