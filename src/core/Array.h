#ifndef ARRAY_H
#define ARRAY_H

// Container to hold data

template<typename T, unsigned int size>
struct Size;

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
template<typename ArrayTrait>
struct StaticArray
{
	typedef ArrayTrait::ElemType ElemType
	
	// Constructor
	
	// Copy constructor
	StaticArray(StaticArray& other);
	
	// Copy assignment
	operator=(StaticArray& other);
	ElemType operator[](size_t index);
	
};

#endif  // ARRAY_H