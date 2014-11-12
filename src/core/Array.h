#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <initializer_list>    // std::initializer_list
#include <array>               // std::array

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
template<typename T, uint s, uint... sizes>
class Array {
public:
	typedef T ElemType;

	/// Number of elements
	static const uint size = product(sizeof(T), s, sizes...);

	/// Number of dimensions
	static const uint rank = count(s, sizes...);

	/// Dimensions of the data
	static const std::array<T, Array::rank> dims;

	/// Default constructor
	Array();

	/// Initialize data block using given data
	Array(std::initializer_list<T> values);

	/// Variadic constructor
	template<typename... Ts>
	Array(Ts... values);

	// Virtual destructor
	virtual ~Array() {}

	// Copy constructor
	// Move constructor

	// Copy assignment

	/// Implementation of single-element accessor
	T operator()(std::initializer_list<uint32_t> indices);

	/// Single element accessor
	template<typename... UInts>
	T operator()(const UInts... indices);



private:
	/// Data container
	std::array<T, Array::size> m_data;
};

#include <core/ArrayImpl.cpp>

#endif  // CORE_ARRAY_H
