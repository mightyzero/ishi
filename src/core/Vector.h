#ifndef NF_VECTOR_H
#define NF_VECTOR_H

#include <core/Common.h>

/*=============================================================================+
 | Class Forward Declarations
 +============================================================================*/
template<size_t D, typename T>
class Vector;

/*=============================================================================+
 | Function Prototypes                                                         |
 +============================================================================*/
/// \brief Add two vectors and return the result.
template<size_t D, typename T>
Vector<D,T> operator+(const Vector<D,T>& v1, const Vector<D,T>& v2);

/// \brief Scale a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          Where<std::is_integral<T2>>>
          // typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<D,T> operator*(const Vector<D,T>& vec, const T2& factor);

/// \brief Scale a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<D,T> operator*(const T2& factor, const Vector<D,T>& vec);

/// \brief Divide a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<D,T> operator/(const Vector<D,T>& vec, const T2& factor);

/// \brief Negate a vector and return the result.
template<size_t D, typename T>
Vector<D,T> operator-(const Vector<D,T>& vec);

/// \brief Compute the dot product of two vectors.
template<size_t D, typename T>
T dot(const Vector<D,T>& vec1, const Vector<D,T>& vec2);

/// \brief Compute the cross product of two vectors.
template<size_t D, typename T>
Vector<D,T> cross(const Vector<D,T>& vec1, const Vector<D,T>& vec2);

/// \brief Compute the square of the vector's length.
template<size_t D, typename T>
T lengthSquared(const Vector<D,T>& vec);

/// \brief Compute the vector's length.
template<size_t D, typename T>
T length(const Vector<D,T>& vec);

/// \brief Return the normalized version of a vector without changing it.
template<size_t D, typename T>
Vector<D,T> normalized(const Vector<D,T>& vec);

/// \brief Normalize a vector and return the result.
template<size_t D, typename T>
Vector<D,T>& normalize(Vector<D,T>& vec);

/***************************************************************************//**
 * \brief Parameterized class that defines a vector (direction in space)
 * 
 *        Vector extends Array by providing named accessors (x, y, z) and 
 *        vector arithmetics, namely:
 *        - Vector addition, subtraction, multiplication, scaling
 *        - Vector normalization
 *        - Vector addition with Point class
 *        - Vector transformation (with Transform class)
 * 
 * \tparam T The precision of the scalar used to represent the vector
 * \tparam D The number of dimensions of the space the vector is in
 ******************************************************************************/
template<size_t D, typename T>
class Vector {
private:
	blitz::Array<T, 1> m_data;

public:
	Vector();
	Vector(const Vector& other);
	
	T& x();
	T& y();
	T& z();
	T& operator[](const uint32_t index);
	
	/// \brief Increment by another vector
	Vector& operator+=(const Vector& other);
	
	/// \brief Scale by a scalar
	template <
		typename T2,
		typename std::enable_if<std::is_integral<T2>::value,int>::type = 0
	>
	Vector& operator*=(const T2& factor);
	
	/// \brief Divide by a scalar
	template <
		typename T2,
		typename std::enable_if<std::is_integral<T2>::value,int>::type = 0
	>
	Vector& operator/=(const T2& factor);
};

// Include implementation of Vector template class
// Note: The implementation must be in the header file. This is a requirement
//       for all template classes
#include <core/VectorImpl.cpp>

#endif 	// NF_VECTOR_H