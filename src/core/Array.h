#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <core/ListInitializer.h>

/*----------------------------------------------------------------------------+
|  T. Class : 
+----------------------------------------------------------------------------*/
template<typename ElemT, typename SizeT>
struct ArrayTrait
{
	typedef ElemT ElemType;
	typedef SizeT Sizes;
};

/***************************************************************************//**
 * \brief Template class functioning as a data holder.
 * 
 *        StaticArray represents an array whose size is known at compile-time.
 *        StaticArray provides the following services:
 *        - Initialization with data, copying, destruction
 *        - Index accessors
 *        - Assignment to comma-separated list of value, for 1- and 2-dimension
 *          arrays (wishlist)
 ******************************************************************************/
template<typename T, unsigned int nDims>
class Array : Array<T, nDims-1> {
public:
	typedef T ElemType;

	// Default Constructor
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