#ifndef CORE_TENSOR_H
#define CORE_TENSOR_H

#include <initializer_list>  // std::initializer_list

#include <core/Array.h>

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

	// Binary arithmetic operators
	friend Tensor operator+(Tensor& lhs, const Tensor& rhs);
	friend Tensor operator-(Tensor& lhs, const Tensor& rhs);
};

/*=============================================================================+
 |                         I M P L E M E N T A T I O N                         |
 +============================================================================*/
template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...>::Tensor() : Array<T, s, sizes...>() {}

template<typename T, uint s, uint... sizes>
Tensor<T, s, sizes...>::Tensor(std::initializer_list<T> values)
		: Array<T, s, sizes...>(values) {}

template<typename T, uint s, uint... sizes>
template<typename... Ts>
Tensor<T, s, sizes...>::Tensor(Ts... values)
		: Array<T, s, sizes...>(values...) {}

#endif  // CORE_TENSOR_H
