#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <initializer_list>

#include <core/Arithmetics.h>

/***************************************************************************//**
 * @brief Template class functioning as a data holder.
 * 
 *        StaticArray represents an array whose size is known at compile-time.
 *        StaticArray provides the following services:
 *        - Initialization with data, copying, destruction
 *        - Access elements with at()
 *        - Assignment to comma-separated list of value, for 1- and 2-dimension
 *          arrays (wishlist)
 *
 * @tparams	T Type of the elements
 ******************************************************************************/
template<typename T, uint32_t s, uint32_t... sizes>
class Array {
public:
	static const uint32_t size;

	// Default Constructor
	Array() {
		printf("size is: %d\n", size);
	}

	Array(std::initializer_list<T> args) {
		printf("size is: %d\n", size);
	}

	// ListInitializer<Array, T, 0> operator=(T arg) {
	// 	return ListInitializer<Array, T, 0>(*this, arg);
	// }

	T operator[](unsigned int index) const {

	}

	T& operator[](unsigned int index) {

	}

};

template<typename T, uint32_t s, uint32_t... sizes>
const uint32_t Array<T, s, sizes...>::size = sizeof(T) * mult(s, sizes...);

#endif  // CORE_ARRAY_H