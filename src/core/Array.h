#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <initializer_list>

#include <core/Arithmetics.h>

/**
 * @brief   Template class functioning as a data holder.
 * @details Array is a multi-dimensional homogeneous data container whose size
 *          is known at compile-time. It provides the following services:
 *          - Single-allocation and single-deallocation of memory resources
 *          - Data initialization, copy, transfer, and modification, for:
 *            - The entire array
 *            - A subset of the array
 *            - Single data element
 *
 * @tparam T Type of the elements
 * @tparam s [description]
 * @tparam sizes [description]
 */
template<typename T, uint32_t s, uint32_t... sizes>
class Array {
public:
	static const uint32_t size;

	/**
	 * @brief   Default constructor
	 * @details Allocate memory for the array. Data is NOT initialized.
	 */
	Array() {
		printf("size is: %d\n", size);
	}

	/**
	 * @brief   Construct and initialize the array with an initializer list
	 * @details [long description]
	 *
	 * @param args [description]
	 */
	Array(std::initializer_list<T> args) {
		printf("size is: %d\n", size);
	}

};

template<typename T, uint32_t s, uint32_t... sizes>
const uint32_t Array<T, s, sizes...>::size = sizeof(T) * mult(s, sizes...);

#endif  // CORE_ARRAY_H
