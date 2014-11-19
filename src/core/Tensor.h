#ifndef CORE_TENSOR_H
#define CORE_TENSOR_H

#include <initializer_list>  // std::initializer_list
#include <algorithm>         // std::equal

#include <core/Array.h>

/*=============================================================================+
 |                            I N T E R F A C E                                |
 +============================================================================*/
/* Forward declaration of class */
template<typename T, uint s, uint... sizes>
class Tensor;

/* Forward declaration of friend operators */
template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator+(Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs);

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator-(Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs);

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator*(Tensor<T, s, sizes...>& lhs, const T scale);

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator*(const T scale, Tensor<T, s, sizes...>& rhs);

template<typename T, uint s, uint... sizes>
bool operator==(const Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs);

template<typename T, uint s, uint... sizes>
bool operator!=(const Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs);

/**
 * @brief [brief description]
 * @details [long description]
 *
 * @tparam T [description]
 * @tparam s [description]
 * @tparam sizes [description]
 */
template<typename T, uint s, uint... sizes>
class Tensor : public Array<T, s, sizes...> {
public:
	// Contructors
	Tensor();
	Tensor(std::initializer_list<T> values);

	template<typename... Ts>
	Tensor(Ts... values);

	// Compound arithmetic operators
	Tensor& operator+=(const Tensor& rhs);
	Tensor& operator-=(const Tensor& rhs);
	Tensor& operator*=(const T scale);

	// Binary arithmetic operators
	friend Tensor operator+<>(Tensor& lhs, const Tensor& rhs);
	friend Tensor operator-<>(Tensor& lhs, const Tensor& rhs);
	friend Tensor operator*<>(Tensor& lhs, const T scale);
	friend Tensor operator*<>(const T scale, Tensor& rhs);

	// Comparison operators
	friend bool operator==<>(const Tensor& lhs, const Tensor& rhs);
	friend bool operator!=<>(const Tensor& lhs, const Tensor& rhs);
};

/*=============================================================================+
 |                         I M P L E M E N T A T I O N                         |
 +============================================================================*/
/**
 * @brief   Default constructor
 * @details [long description]
 *
 * @param y [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...>::Tensor() : Array<T, s, sizes...>() {}

/**
 * @brief   Initializer list constructor
 * @details [long description]
 *
 * @param  [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...>::Tensor(std::initializer_list<T> values)
		: Array<T, s, sizes...>(values) {}

/**
 * @brief   Variadic template constructor
 * @details [long description]
 *
 * @param values [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
template<typename... Ts>
Tensor<T, s, sizes...>::Tensor(Ts... values)
		: Array<T, s, sizes...>(values...) {}

/**
 * @brief   Compound scaling operator
 * @details [long description]
 *
 * @param scale [description]
 * @return [description]
 */
template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...>& Tensor<T, s, sizes...>::operator*=(const T scale) {
	return (*this);
}

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator*(Tensor<T, s, sizes...>& lhs, const T scale) {
	return lhs *= scale;
}

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...> operator*(const T scale, Tensor<T, s, sizes...>& rhs) {
	return rhs *= scale;
}

template<typename T, uint s, uint... sizes>
bool operator==(const Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs) {
	return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
}

template<typename T, uint s, uint... sizes>
bool operator!=(const Tensor<T, s, sizes...>& lhs, const Tensor<T, s, sizes...>& rhs) {
	return !(lhs == rhs);
}


#endif  // CORE_TENSOR_H
