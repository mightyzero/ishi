#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <core/ListInitializer.h>

template<typename T, unsigned int nDims>
class Array : Array<T, nDims-1> {
public:
	Array() {
		// TODO: Check signature
		// TODO: Implement
	}

	ListInitializer<Array, T, 0> operator=(T arg) {
		return ListInitializer<Array, T, 0>(*this, arg);
	}

	T operator[](unsigned int index) const {

	}

	T& operator[](unsigned int index) {

	}

};

template<typename T>
class Array<T, 1> {

};

#endif  // CORE_ARRAY_H