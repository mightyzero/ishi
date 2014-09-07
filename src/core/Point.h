#ifndef NF_POINT_H
#define NF_POINT_H

#include <core/Common.h>

/**
* Define the Point template class
* \note The implementation must be in the header file. This is a requirement for
*       all template classes.
*/

template <typename T, uint32_t D>
class Point;

template <typename T, uint32_t D>
Point<T,D> operator+(const Point<T,D>& p1, const Point<T,D>& p2);

template <typename T, uint32_t D>
bool operator==(const Point<T,D>& p1, const Point<T,D>& p2);

template <typename T, uint32_t D>
bool operator!=(const Point<T,D>& p1, const Point<T,D>& p2);

/***************************************************************************//**
 * \brief Parameterized class that defines a point in space
 * 
 * \tparam T The precision of the scalar used to represent the point
 * \tparam D The number of dimensions of the space the point is in
 ******************************************************************************/
template <typename T, uint32_t D>
class Point {
private:
	// blitz::Array<T, 1> m_data;

public:
	// Constructors
	Point();
	Point(const Point& other);
	template <typename... T2>
	Point(const T2&... vals);
	
	T& x();
	T& y();
	T& z();
	T& operator[](const uint32_t index);
	
	/* Friend Declarations */
	friend Point operator+<>(const Point& p1, const Point& p2);
	
	friend bool operator==<>(const Point& p1, const Point& p2);
	friend bool operator!=<>(const Point& p1, const Point& p2);
};

// Include implementation of Point template class
// Note: The implementation must be in the header file. This is a requirement
//       for all template classes
#include <core/PointImpl.cpp>

#endif  // NF_POINT_H