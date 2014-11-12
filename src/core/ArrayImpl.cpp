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


template<typename T, uint s, uint... sizes>
Array<T, s, sizes...>::Array(std::initializer_list<T> values) {
	std::copy(values.begin(), values.end(), m_data.begin());
}

template<typename T, uint s, uint... sizes>
template<typename... Ts>
Array<T, s, sizes...>::Array(Ts... values) : m_data { values... } {}

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

template<typename T, uint s, uint... sizes>
template<typename... UInts>
T Array<T, s, sizes...>::operator()(const UInts... indices) {
	return (*this)({indices...});
}
