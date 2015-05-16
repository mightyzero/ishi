#ifndef TEST_TESTALGORITHMS_H
#define TEST_TESTALGORITHMS_H

#include <type_traits>
#include <typeinfo>

#include <gtest/gtest.h>
#include <core/functional/zip.h>

TEST(ZipIterator, Constructor) {
	std::array<int, 4>    c1 {{ 1, 2, 3, 4 }};
	std::array<float, 3>  c2 {{ 1.0f, 2.0f, 3.0f }};
	std::array<double, 3> c3 {{ 1.0, 2.0, 3.0 }};

	auto zipResult = zip(c1, c2, c3);

	// EXPECT_EQ(zipResult. )
}

TEST(zip, arrayReference) {
	std::array<int, 4>    c1 {{ 1, 2, 3, 4 }};
	std::array<float, 3>  c2 {{ 1.0f, 2.0f, 3.0f }};
	std::array<double, 3> c3 {{ 1.0, 2.0, 3.0 }};

	std::array<int, 4>& r1 = c1;
	std::array<float, 3>&  r2 = c2;
	std::array<double, 3>& r3 = c3;

	auto zipResult = zip(r1, r2, r3);
}

TEST(zip, arrayOfReferenceWrapper) {

}

// int add(int x, int y) { return x + y; }

// TEST(Algorithms, ReturnType) {
// 	// auto r = returnType(add);
// 	// EXPECT_TRUE((std::is_same<decltype(r)::type, int>::value));

// 	// std::cout << typeid(decltype(r)::type).name() << '\n';
// 	// std::cout << typeid(int).name() << '\n';

// 	int x, y;
// 	EXPECT_TRUE((std::is_same<decltype(add(x, y)), int>::value));
// }

// TEST(Algorithms, Map) {
// 	map([](int x, int y) { return x + y; }, {1, 2, 3}, {4, 5, 6});
// }

#endif  // TEST_TESTALGORITHMS_H

