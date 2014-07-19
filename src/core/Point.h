#ifndef POINT_H
#define POINT_H

#include <core/Common.h>
#include <blitz/array.h>

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

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D>::Point() : m_data(D)
{
	m_data = 0;
}

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D>::Point(const Point<T,D>& other) : m_data(other.m_data)
{
	// empty function body
}

/**************************************************************************/
template <typename T, uint32_t D>
template <typename... T2>
Point<T,D>::Point(const T2&... vals) : m_data(D)
{
	std::initializer_list<T> tmp = { vals... };
	
	uint32_t i = 0;
	for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
		m_data(i) = *iter;
		i++;
	}
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::x()
{
	return m_data(0);
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::y()
{
	return m_data(1);
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::z()
{
	return m_data(2);
}

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D> operator+(const Point<T,D>& p1, const Point<T,D>& p2)
{
	
}

/**************************************************************************/
template <typename T, uint32_t D>
bool operator==(const Point<T,D>& p1, const Point<T,D>& p2)
{
	return true;
}

/**************************************************************************/
template <typename T, uint32_t D>
bool operator!=(const Point<T,D>& p1, const Point<T,D>& p2)
{
	return !(p1 == p2);
}

#endif  // POINT_H