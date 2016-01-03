#include <catch/catch.hpp>
#include <core/algebra/impl/array_vec.h>

namespace ishi {

TEST_CASE("Unit tests for ArrayVec", "[ArrayVec]") {
	// Typedef test vector type. Just change this typedef for other vector implementations
	typedef ArrayVec<float, 4> TestVec;

	SECTION("x() should be able to modify first data element") {
		TestVec v = TestVec();

		v.x() = 1.0f;
		CHECK(v.x() == 1.0f);

		v.x() = 2.0f;
		CHECK(v.x() == 2.0f);
	}

	SECTION("y() should be able to modify second data element") {
		TestVec v = TestVec();

		v.y() = 1.0f;
		CHECK(v.y() == 1.0f);

		v.y() = 2.0f;
		CHECK(v.y() == 2.0f);
	}

	SECTION("z() should be able to modify second data element") {
		TestVec v = TestVec();

		v.z() = 1.0f;
		CHECK(v.z() == 1.0f);

		v.z() = 2.0f;
		CHECK(v.z() == 2.0f);
	}

	SECTION("w() should be able to modify second data element") {
		TestVec v = TestVec();

		v.w() = 1.0f;
		CHECK(v.w() == 1.0f);

		v.w() = 2.0f;
		CHECK(v.w() == 2.0f);
	}

	SECTION("Default constructor should return origin") {
		TestVec v = TestVec();

		CHECK(v.x() == 0);
		CHECK(v.y() == 0);
		CHECK(v.z() == 0);
		CHECK(v.w() == 0);
	}

	SECTION("Two arg constructor should return point on 0-plane") {
		TestVec v = TestVec(3.6f, -5.2f);

		CHECK(v.x() == 3.6f);
		CHECK(v.y() == -5.2f);
		CHECK(v.z() == 0);
		CHECK(v.w() == 0);
	}

	SECTION("Three arg constructor should return point in 3D space") {
		TestVec v = TestVec(3.6f, -5.2f, 7.4f);

		CHECK(v.x() == 3.6f);
		CHECK(v.y() == -5.2f);
		CHECK(v.z() == 7.4f);
		CHECK(v.w() == 0);
	}

	SECTION("Copy constructor should copy data elements") {
		TestVec expected = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec actual = expected;

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Copy constructor should not modify original vector") {
		TestVec actual = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec v = actual;

		CHECK(v.x() != 0);

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Assignment should copy data elements") {
		TestVec expected = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec actual;

		actual = expected;

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Assignment should not modify original vector") {
		TestVec actual = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec v;

		v = actual;

		CHECK(v.x() != 0);

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Index operator return all zeros default constructed vec") {
		TestVec v;

		CHECK(v[0] == 0);
		CHECK(v[1] == 0);
		CHECK(v[2] == 0);
		CHECK(v[3] == 0);
	}

	SECTION("Index operator should return data element at index") {
		TestVec v = TestVec(1.0f, 2.0f, 3.0f, 4.0f);

		CHECK(v[0] == v.x());
		CHECK(v[1] == v.y());
		CHECK(v[2] == v.z());
		CHECK(v[3] == v.w());
	}

	SECTION("Increment by zero vector should not change data elements") {
		TestVec actual = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec zero;

		actual += zero;

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Add to zero vector should not change data elements") {
		TestVec expected = TestVec(1.0f, 2.0f, 3.0f);
		TestVec zero;
		TestVec actual = expected + zero;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Add should add the respective components") {
		TestVec p1 = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec p2 = TestVec(4.0f, 5.0f, 6.0f, 7.0f);

		TestVec actual = p1 + p2;
		TestVec expected = TestVec(5.0f, 7.0f, 9.0f, 11.0f);

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Add should be commutative") {
		TestVec p1 = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec p2 = TestVec(4.0f, 5.0f, 6.0f, 7.0f);

		TestVec actual = p1 + p2;
		TestVec expected = p2 + p1;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Compound subtract* by zero vector should not change data elements") {
		TestVec actual = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec zero;

		actual -= zero;

		CHECK(actual.x() == 1.0f);
		CHECK(actual.y() == 2.0f);
		CHECK(actual.z() == 3.0f);
		CHECK(actual.w() == 4.0f);
	}

	SECTION("Compound subtract by self should return zero vector") {
		TestVec actual = TestVec(1.0f, 2.0f, 3.0f, 4.0f);

		actual -= actual;

		CHECK(actual.x() == 0.0f);
		CHECK(actual.y() == 0.0f);
		CHECK(actual.z() == 0.0f);
		CHECK(actual.w() == 0.0f);
	}

	SECTION("Compound subtract should reduce data elements") {
		TestVec actual(1.0f, 2.0f, 3.0f, 4.0f);
		actual -= TestVec(1.0f, 1.0f, 1.0f, 1.0f);
		TestVec expected(0.0f, 1.0f, 2.0f, 3.0f);

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Subtract by zero vector should not change data elements") {
		TestVec expected = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec zero;
		TestVec actual = expected - zero;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Subtract should add the respective components") {
		TestVec p1 = TestVec(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec p2 = TestVec(4.0f, 5.0f, 6.0f, 7.0f);

		TestVec actual = p1 - p2;
		TestVec expected = TestVec(-3.0f, -3.0f, -3.0f, -3.0f);

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Compound multiply by zero should return zero vector") {
		TestVec actual(1.0f, 2.0f, 3.0f, 4.0f);

		actual *= 0;

		CHECK(actual.x() == 0.0f);
		CHECK(actual.y() == 0.0f);
		CHECK(actual.z() == 0.0f);
		CHECK(actual.w() == 0.0f);
	}

	SECTION("Compound multiply by one should return same vector") {
		TestVec actual(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected = actual;

		actual *= 1;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Compound multiply should scale all data elements") {
		TestVec actual(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected(2.0f, 4.0f, 6.0f, 8.0f);

		actual *= 2;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Multiply vector by zero should return zero vector") {
		TestVec v = TestVec(1.0f, 2.0f, 3.0f, 4.0f);

		TestVec actual = v * 0.0f;

		CHECK(actual.x() == 0.0f);
		CHECK(actual.y() == 0.0f);
		CHECK(actual.z() == 0.0f);
		CHECK(actual.w() == 0.0f);
	}

	SECTION("Multiply zero by vector should return zero vector") {
		TestVec v = TestVec(1.0f, 2.0f, 3.0f, 4.0f);

		TestVec actual = 0.0f * v;

		CHECK(actual.x() == 0.0f);
		CHECK(actual.y() == 0.0f);
		CHECK(actual.z() == 0.0f);
		CHECK(actual.w() == 0.0f);
	}

	SECTION("Multiply vector by one should return same vector") {
		TestVec expected(1.0f, 2.0f, 3.0f, 4.0f);

		TestVec actual = expected * 1.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Multiply one by vector should return same vector") {
		TestVec expected(1.0f, 2.0f, 3.0f, 4.0f);

		TestVec actual = 1.0f * expected;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Multiply vector by scalar should scale all data elements") {
		TestVec v(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected(2.0f, 4.0f, 6.0f, 8.0f);

		TestVec actual = v * 2.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Multiply scalar by vector should scale all data elements") {
		TestVec v(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected(2.0f, 4.0f, 6.0f, 8.0f);

		TestVec actual = 2.0f * v;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Compound divide by one should not change vector") {
		TestVec actual(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected = actual;

		actual /= 1.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Compound divide should divide all data elements") {
		TestVec actual(2.0f, 4.0f, 6.0f, 8.0f);
		TestVec expected(1.0f, 2.0f, 3.0f, 4.0f);

		actual /= 2.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Divide by one should not change vector") {
		TestVec v(1.0f, 2.0f, 3.0f, 4.0f);
		TestVec expected = v;

		TestVec actual = v / 1.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

	SECTION("Divide should divide all data elements") {
		TestVec v(2.0f, 4.0f, 6.0f, 8.0f);
		TestVec expected(1.0f, 2.0f, 3.0f, 4.0f);

		TestVec actual = v / 2.0f;

		CHECK(actual.x() == expected.x());
		CHECK(actual.y() == expected.y());
		CHECK(actual.z() == expected.z());
		CHECK(actual.w() == expected.w());
	}

}

}  //namespace ishi