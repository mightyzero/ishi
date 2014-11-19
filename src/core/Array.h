#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <initializer_list>    // std::initializer_list
#include <array>               // std::array

#include <core/Math.h>

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
	// Type definitions
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
	T operator()(std::initializer_list<uint> indices);

	/// Single element accessor
	template<typename... UInts>
	T operator()(const UInts... indices);

private:
	typedef std::array<T, Array::size> ContainerT;

	/// Data container
	ContainerT m_data;

public:
	typedef typename ContainerT::iterator               iterator;
	typedef typename ContainerT::const_iterator         const_iterator;
	typedef typename ContainerT::reverse_iterator       reverse_iterator;
	typedef typename ContainerT::const_reverse_iterator const_reverse_iterator;

	// Iterator access
	iterator begin() { return m_data.begin(); }
	iterator end()   { return m_data.end();   }

	const_iterator cbegin() const { return m_data.cbegin(); }
	const_iterator cend()   const { return m_data.cend();   }

	reverse_iterator rbegin() { return m_data.rbegin(); }
	reverse_iterator rend()   { return m_data.rend();   }

	const_reverse_iterator crbegin() const { return m_data.crbegin(); }
	const_reverse_iterator crend()   const { return m_data.crend();   }
};

/*=============================================================================+
 |                         I M P L E M E N T A T I O N                         |
 +============================================================================*/
#include <algorithm>          // std::copy

#include <core/Exceptions.h>

template<typename T, uint s, uint... sizes>
const std::array<T, Array<T, s, sizes...>::rank>
Array<T, s, sizes...>::dims = { s, sizes... };

/**
 * @brief   Default constructor
 * @details Allocate memory for the array. Data is NOT initialized.
 */
template<typename T, uint s, uint... sizes>
Array<T, s, sizes...>::Array() {}

/**
 * @brief Initializer list constructor
 * @details [long description]
 *
 * @param values [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
Array<T, s, sizes...>::Array(std::initializer_list<T> values) {
	std::copy(values.begin(), values.end(), m_data.begin());
}

/**
 * @brief Variadic template constructor
 * @details [long description]
 *
 * @param values [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
template<typename... Ts>
Array<T, s, sizes...>::Array(Ts... values) : m_data { values... } {}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param indices [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
T Array<T, s, sizes...>::operator()(std::initializer_list<uint> indices) {
	ASSERT(indices.size() == Array::rank);

	uint offset = 0;
	auto i = indices.begin();
	auto d = dims.crbegin() + 1;
	for (; i != indices.end(), d != dims.crend(); ++i, ++d) {
		offset += (*d) * (*i);
	}
	offset += (*i);

	return m_data[offset];
}

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @param indices [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
template<typename... UInts>
T Array<T, s, sizes...>::operator()(const UInts... indices) {
	return (*this)({indices...});
}

#endif  // CORE_ARRAY_H
