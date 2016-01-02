#ifndef CORE_ALGEBRA_VEC_H
#define CORE_ALGEBRA_VEC_H

#include <iterator>
#include <core/algebra/vec_trait.h>

namespace ishi {

/**
 * The abstract interface for a linear algebra vector.
 *
 * Classes implementing this abstract interface support value semantics. Overridden methods should be declared final.
 */
template<typename ImplT>
class Vec {
public:
	typedef typename VecTrait<ImplT>::type ScalarT;

private:
	ImplT* m_impl;

public:
	Vec() : m_impl(static_cast<ImplT*>(this)) {}

	/** Access the first element in the vector. */
	ScalarT& x() {
		return m_impl->x();
	}

	/** Access the second element in the vector. */
	ScalarT& y() {
		return m_impl->y();
	}

	/** Access the third element in the vector, if it exists. */
	ScalarT& z() {
		return m_impl->z();
	};

	/** Access the fourth element in the vector, if it exists. */
	ScalarT& w() {
		return m_impl->w();
	}

	/** Index operator. */
	ScalarT& operator[](size_t index) {
		return m_impl->operator[](index);
	}

	/** Const index operator. */
	ScalarT operator[](size_t index) const {
		return m_impl->operator[](index);
	}

	Vec& operator+=(const Vec &that) {
		return m_impl->operator+=(that);
	}

};

}  //namespace ishi

#endif //CORE_ALGEBRA_VEC_H