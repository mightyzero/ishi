#include <core/Point.h>

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D>::Point() : m_data(D) {
	m_data = 0;
}

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D>::Point(const Point<T,D>& other) : m_data(other.m_data) {
	// empty function body
}

/**************************************************************************/
template <typename T, uint32_t D>
template <typename... T2>
Point<T,D>::Point(const T2&... vals) : m_data(D) {
	std::initializer_list<T> tmp = { vals... };
	
	uint32_t i = 0;
	for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
		m_data(i) = *iter;
		i++;
	}
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::x() {
	return m_data(0);
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::y() {
	return m_data(1);
}

/**************************************************************************/
template <typename T, uint32_t D>
T& Point<T,D>::z() {
	return m_data(2);
}

/**************************************************************************/
template <typename T, uint32_t D>
Point<T,D> operator+(const Point<T,D>& p1, const Point<T,D>& p2) {
	
}

/**************************************************************************/
template <typename T, uint32_t D>
bool operator==(const Point<T,D>& p1, const Point<T,D>& p2) {
	return true;
}

/**************************************************************************/
template <typename T, uint32_t D>
bool operator!=(const Point<T,D>& p1, const Point<T,D>& p2) {
	return !(p1 == p2);
}