#ifndef NF_COMMON_H
#define NF_COMMON_H

#include <stdint.h>  // *int*_t
#include <assert.h>  // assert

#define ASSERT assert

/**
Template utility to test type equality.
Scope member value is 1 if types are equal, 0 if not.

Usage examples:
TypeEqual<T, int>
*/
template<typename T1, typename T2>
struct TypeEqual {
	enum { value = 0 };
};

template<typename T>
struct TypeEqual<T, T> {
	enum { value = 1 };
};

/**
Template utility to test a condition.
Throw a compile error if the condition is false at compile time.

Usage examples:
Where<T, Is<int>>
*/
template<bool Cond>
struct Where;

template<>
struct Where<true> {};

#endif  // NF_COMMON_H