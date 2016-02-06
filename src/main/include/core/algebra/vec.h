#ifndef CORE_ALGEBRA_VEC_H
#define CORE_ALGEBRA_VEC_H

#include <iterator>
#include <core/algebra/vec_trait.h>

namespace ishi {

template<typename ScalarT, int length, template<typename, int> class ImplT>
class Vec;

/** Add two vectors. */
template<typename S, int l, template<typename, int> class T1, template<typename, int> class T2>
auto operator+(const Vec<S, l, T1> &x, const Vec<S, l, T2> &y) -> decltype(x.data() + y.data()) {
	return x.data() + y.data();
}

/** Add a vector to something else. */
template<typename S, int l, template<typename, int> class T1, typename T2>
auto operator+(const Vec<S, l, T1> &x, const T2 &y) -> decltype(x.data() + y) {
	return x.data() + y;
}

template<typename S, int l, typename T1, template<typename, int> class T2>
auto operator+(const T1 &x, const Vec<S, l, T2> &y) -> decltype(x + y.data()) {
	return x + y.data();
}

template<typename S, int l, template<typename, int> class T1, template<typename, int> class T2>
auto operator-(const Vec<S, l, T1> &x, const Vec<S, l, T2> &y) -> decltype(x.data() - y.data()) {
	return x.data() - y.data();
}

template<typename S, int l, template<typename, int> class T1, typename T2>
auto operator-(const Vec<S, l, T1> &x, const T2 &y) -> decltype(x.data() - y) {
	return x.data() - y;
}

template<typename S, int l, typename T1, template<typename, int> class T2>
auto operator-(const T1 &x, const Vec<S, l, T2> &y) -> decltype(x - y.data()) {
	return x - y.data();
}

/** Multiply vector by scalar. */
template<typename S, int l, template<typename, int> class T1, typename T2>
auto operator*(const Vec<S, l, T1> &x, const T2 &y) -> decltype(x.data() * y) {
	return x.data() * y;
}

template<typename S, int l, typename T1, template<typename, int> class T2>
auto operator*(const T1 &x, const Vec<S, l, T2> &y) -> decltype(x * y.data()) {
	return x * y.data();
}

/** Divide vector by scalar. */
template<typename S, int l, template<typename, int> class T1, typename T2>
auto operator/(const Vec<S, l, T1> &x, const T2 &y) -> decltype(x.data() * y) {
	return x.data() / y;
}

/**
 * The abstract interface for a linear algebra vector.
 *
 * Classes implementing this abstract interface support value semantics. Overridden methods should be declared final.
 */
template<typename ScalarT, int length, template<typename, int> class ImplT>
class Vec {
public:
	typedef ImplT<ScalarT, length> DataT;

//	typedef typename VecTrait<ImplT>::type ScalarT;

private:
	DataT m_data;

public:
	Vec() : m_data() {}

	/** Implicit conversion operator. */
	operator DataT() const { return m_data; }

	/** Constructor from variable scalars. */
	template <typename... ScalarTs>
	Vec(ScalarT first, ScalarTs... rest) : m_data(first, rest...) {}

	Vec(const DataT& impl) : m_data(impl) {}

	/** Access the first element in the vector. */
	ScalarT& x() { return operator[](0); }

	/** Access the second element in the vector. */
	ScalarT& y() { return operator[](1); }

	/** Access the third element in the vector, if it exists. */
	ScalarT& z() { return operator[](2); };

	/** Access the fourth element in the vector, if it exists. */
	ScalarT& w() { return operator[](3); }

	/** Index operator. */
	ScalarT& operator[](int index) { return m_data[index]; }

	/** Const index operator. */
	ScalarT operator[](int index) const { return m_data[index]; }

	template <typename T>
	Vec& operator+=(const T &that) {
		m_data+= that;
		return *this;
	}

	template <typename T>
	Vec& operator-=(const T &that) {
		m_data-=(that);
		return *this;
	}

	template <typename T>
	Vec& operator*=(const T &that) {
		m_data *= that;
		return *this;
	}

	template <typename T>
	Vec& operator/=(const T &that) {
		m_data /= that;
		return *this;
	}

	template <typename T>
	const Vec& operator=(const T & X) {
		m_data = X;
		return *this;
	}

	ImplT<ScalarT, length> data() const {
		return m_data;
	}

};

}  //namespace ishi

#endif //CORE_ALGEBRA_VEC_H
