#ifndef POINT_H
#define POINT_H

#include <core/Common.h>
#include <blitz/array.h>

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
	blitz::Array<T, 1> m_data;

public:
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

#endif  // POINT_H