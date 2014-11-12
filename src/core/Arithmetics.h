#ifndef CORE_ARITHMETICS
#define CORE_ARITHMETICS

#include <core/Common.h>

template<typename T>
constexpr T sum(T arg1) {
	return arg1;
}

template<typename T, typename... Args>
constexpr uint sum(T arg1, Args... args) {
	return arg1 + sum(args...);
}

template<typename T>
constexpr T product(T arg1) {
	return arg1;
}

template<typename T, typename... Args>
constexpr T product(T arg1, Args... args) {
	return arg1 * product(args...);
}

template<typename T, typename... Args>
constexpr uint count(T arg1, Args... args) {
	return 1 + sizeof...(Args);
}

#endif  // CORE_ARITHMETICS
