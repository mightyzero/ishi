#ifndef VECTOR_H
#define VECTOR_H

#include <core/Common.h>
#include <blitz/array.h>

/*=============================================================================+
 | Class Forward Declarations
 +============================================================================*/
template <typename T, uint32_t D>
class Vector;

/*=============================================================================+
 | Function Prototypes                                                         |
 +============================================================================*/
/// \brief Add two vectors and return the result.
template <typename T, uint32_t D>
Vector<T,D> operator+(const Vector<T,D>& v1, const Vector<T,D>& v2);

/// \brief Scale a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<T,D> operator*(const Vector<T,D>& vec, const T2& factor);

/// \brief Scale a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<T,D> operator*(const T2& factor, const Vector<T,D>& vec);

/// \brief Divide a vector by a scalar and return the result.
template <typename T, uint32_t D, typename T2,
          typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Vector<T,D> operator/(const Vector<T,D>& vec, const T2& factor);

/// \brief Negate a vector and return the result.
template <typename T, uint32_t D>
Vector<T,D> operator-(const Vector<T,D>& vec);

/// \brief Compute the dot product of two vectors.
template <typename T, uint32_t D>
T dot(const Vector<T,D>& vec1, const Vector<T,D>& vec2);

/// \brief Compute the cross product of two vectors.
template <typename T, uint32_t D>
Vector<T,D> cross(const Vector<T,D>& vec1, const Vector<T,D>& vec2);

/// \brief Compute the square of the vector's length.
template <typename T, uint32_t D>
T lengthSquared(const Vector<T,D>& vec);

/// \brief Compute the vector's length.
template <typename T, uint32_t D>
T length(const Vector<T,D>& vec);

/// \brief Return the normalized version of a vector without changing it.
template <typename T, uint32_t D>
Vector<T,D> normalized(const Vector<T,D>& vec);

/// \brief Normalize a vector and return the result.
template <typename T, uint32_t D>
Vector<T,D>& normalize(Vector<T,D>& vec);

/***************************************************************************//**
 * \brief Parameterized class that defines a vector (direction in space)
 * 
 * \tparam T The precision of the scalar used to represent the vector
 * \tparam D The number of dimensions of the space the vector is in
 ******************************************************************************/
template <typename T, uint32_t D>
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
 
#endif 	// VECTOR_H