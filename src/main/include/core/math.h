#ifndef CORE_ARITHMETICS_H
#define CORE_ARITHMETICS_H

#include <core/common.h>

/**
 * @brief   Compute the sum of arguments
 * @details Overload for one argument
 *
 * @param arg1 The argument
 * @return  The argument given
 */
template <typename T>
constexpr T sum(T arg1) {
	return arg1;
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param arg1 [description]
 * @param args [description]
 * @return [description]
 */
template <typename T, typename... Args>
constexpr uint sum(T arg1, Args... args) {
	return arg1 + sum(args...);
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param arg1 [description]
 * @return [description]
 */
template <typename T>
constexpr T product(T arg1) {
	return arg1;
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param arg1 [description]
 * @param args [description]
 * @return [description]
 */
template <typename T, typename... Args>
constexpr T product(T arg1, Args... args) {
	return arg1 * product(args...);
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param arg1 [description]
 * @param args [description]
 * @return [description]
 */
template <typename T, typename... Args>
constexpr uint count(T, Args...) {
	return 1 + sizeof...(Args);
}

/**
 * @brief   Return true if the arguments are equal
 * @details [long description]
 *
 * @param arg1 [description]
 * @param arg2 [description]
 * @return [description]
 */
template <typename T1, typename T2>
constexpr bool eq(T1 arg1, T2 arg2) {
	return (arg1 == arg2);
}

/**
 * @brief   Return true if the arguments are NOT equal
 * @details [long description]
 *
 * @param arg1 [description]
 * @param arg2 [description]
 * @return [description]
 */
template <typename T1, typename T2>
constexpr bool neq(T1 arg1, T2 arg2) {
	return !eq(arg1, arg2);
}

#endif //CORE_ARITHMETICS_H
