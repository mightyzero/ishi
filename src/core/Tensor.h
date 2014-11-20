#ifndef CORE_TENSOR_H
#define CORE_TENSOR_H

#include <initializer_list> // std::initializer_list
#include <algorithm>        // std::equal

#include <core/Array.h>

/*=============================================================================+
 |                            I N T E R F A C E                                |
 +============================================================================*/
/**
 * @brief [brief description]
 * @details [long description]
 *
 * @tparam T [description]
 * @tparam s [description]
 * @tparam sizes [description]
 */
template <typename T, uint... sizes>
class Tensor : public Array<T, sizes...> {
public:
	// Contructors
	Tensor();
	Tensor(std::initializer_list<T> values);

	template <typename... Ts>
	Tensor(Ts... values);

	// Compound arithmetic operators
	Tensor &operator+=(const Tensor &rhs);
	Tensor &operator-=(const Tensor &rhs);
	Tensor &operator*=(const T scale);
};

template <typename T, uint... sizes>
Tensor<T, sizes...> operator+(Tensor<T, sizes...> &lhs,
                              const Tensor<T, sizes...> &rhs);

template <typename T, uint... sizes>
Tensor<T, sizes...> operator-(Tensor<T, sizes...> &lhs,
                              const Tensor<T, sizes...> &rhs);

template <typename T, uint... sizes>
Tensor<T, sizes...> operator*(const Tensor<T, sizes...> &lhs, const T scale);

template <typename T, uint... sizes>
Tensor<T, sizes...> operator*(const T scale, const Tensor<T, sizes...> &rhs);

template <typename T, uint... sizes>
bool operator==(const Tensor<T, sizes...> &lhs, const Tensor<T, sizes...> &rhs);

template <typename T, uint... sizes>
bool operator!=(const Tensor<T, sizes...> &lhs, const Tensor<T, sizes...> &rhs);
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
template <typename T, uint... sizes>
Tensor<T, sizes...>::Tensor()
    : Array<T, sizes...>() {}

/**
 * @brief   Initializer list constructor
 * @details [long description]
 *
 * @param  [description]
 * @return [description]
 */
template <typename T, uint... sizes>
Tensor<T, sizes...>::Tensor(std::initializer_list<T> values)
    : Array<T, sizes...>(values) {}

/**
 * @brief   Variadic template constructor
 * @details [long description]
 *
 * @param values [description]
 * @return [description]
 */
template <typename T, uint... sizes>
template <typename... Ts>
Tensor<T, sizes...>::Tensor(Ts... values)
    : Array<T, sizes...>(values...) {}

/**
 * @brief   Compound scaling operator
 * @details [long description]
 *
 * @param scale [description]
 * @return [description]
 */
template <typename T, uint... sizes>
Tensor<T, sizes...> &Tensor<T, sizes...>::operator*=(const T scale) {
	return (*this);
}

template <typename T, uint... sizes>
Tensor<T, sizes...> operator*(const Tensor<T, sizes...> &lhs, const T scale) {
	return lhs *= scale;
}

template <typename T, uint... sizes>
Tensor<T, sizes...> operator*(const T scale, const Tensor<T, sizes...> &rhs) {
	return rhs *= scale;
}

template <typename T, uint... sizes>
bool operator==(const Tensor<T, sizes...> &lhs,
                const Tensor<T, sizes...> &rhs) {
	return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin());
}

template <typename T, uint... sizes>
bool operator!=(const Tensor<T, sizes...> &lhs,
                const Tensor<T, sizes...> &rhs) {
	return !(lhs == rhs);
}

#endif // CORE_TENSOR_H
