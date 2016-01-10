#ifndef CORE_ALGEBRA_ARRAY_VEC_H
#define CORE_ALGEBRA_ARRAY_VEC_H

#include <array>

#include <core/algebra/vec.h>
#include <core/algebra/vec_trait.h>

namespace ishi {

// Forward declaration
template <typename ScalarT, size_t length>
class ArrayVecImpl;

/**
 * Specialization of VecTrait for ArrayVecImpl.
 */
template <typename ScalarT, size_t length>
struct VecTrait<ArrayVecImpl<ScalarT, length>> {
	typedef ScalarT type;
};

// Forward declaration of friend method swap
template <typename ScalarT, size_t length>
void swap(ArrayVecImpl<ScalarT, length> &lhs, ArrayVecImpl<ScalarT, length> &rhs);

/**
 * Addition operator.
 */
template <typename ScalarT, size_t length>
ArrayVecImpl<ScalarT, length> operator+(ArrayVecImpl<ScalarT, length> lhs, const ArrayVecImpl<ScalarT, length>& rhs) {
	lhs += rhs;
	return lhs;
}

/**
 * Subtraction operator.
 */
template<typename ScalarT, size_t length>
ArrayVecImpl<ScalarT, length> operator-(ArrayVecImpl<ScalarT, length> lhs, const ArrayVecImpl<ScalarT, length>& rhs) {
	lhs -= rhs;
	return lhs;
}

/**
 * Multiplication operator.
 */
template<typename ScalarT, size_t length>
ArrayVecImpl<ScalarT, length> operator*(ArrayVecImpl<ScalarT, length> lhs, ScalarT scalar) {
	lhs *= scalar;
	return lhs;
}

/**
 * Multiplication operator.
 */
template<typename ScalarT, size_t length>
ArrayVecImpl<ScalarT, length> operator*(ScalarT scalar, ArrayVecImpl<ScalarT, length> rhs) {
	return rhs * scalar;
}

/**
 * Division operator.
 */
template<typename ScalarT, size_t length>
ArrayVecImpl<ScalarT, length> operator/(ArrayVecImpl<ScalarT, length> lhs, ScalarT scale) {
	lhs /= scale;
	return lhs;
}

/**
 * Implementation of Vec using std::array as backing data store.
 */
template <typename ScalarT, size_t length>
class ArrayVecImpl {
public:
	typedef typename VecTrait<ArrayVecImpl>::type value_type;

private:
	std::array<ScalarT, length> m_data;

public:
	friend void swap(ArrayVecImpl &lhs, ArrayVecImpl &rhs) {
		std::swap(lhs.m_data, rhs.m_data);
	}

public:
	/** Default constructor. */
	ArrayVecImpl() {
		m_data.fill(0);
	}

	/** Constructor from variable scalars. */
	template <typename... ScalarTs>
	ArrayVecImpl(ScalarT first, ScalarTs... rest) {
		m_data = {{first, rest...}};
	}

	/** Copy constructor. */
	ArrayVecImpl(const ArrayVecImpl &that) : m_data(that.m_data) { }

	/** Move constructor. */
	ArrayVecImpl(ArrayVecImpl &&that) : ArrayVecImpl() {
		swap(*this, that);
	}

	/**
	 * Assignment operator.
	 *
	 * This method is implemented using the copy-and-swap idiom. See:
	 * http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
	 */
	ArrayVecImpl &operator=(ArrayVecImpl that) {
		swap(*this, that);
		return *this;
	}

	/** Index operator. */
	ScalarT &operator[](size_t index) {
		return m_data[index];
	}

	/** Const version of index operator. */
	ScalarT operator[](size_t index) const {
		return m_data[index];
	}

	/** Compound addition operator. */
	ArrayVecImpl &operator+=(const ArrayVecImpl &that) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] += that[i];
		}
		return *this;
	}

	/** Compound subtraction operator. */
	ArrayVecImpl &operator-=(const ArrayVecImpl &that) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] -= that[i];
		}
		return *this;
	}

	/** Compound multiplication operator. */
	ArrayVecImpl &operator*=(ScalarT scalar) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] *= scalar;
		}
		return *this;
	}

	/** Compound division operator. */
	ArrayVecImpl &operator/=(ScalarT scalar) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] /= scalar;
		}
		return *this;
	}
};

template<typename ScalarT, size_t length>
using ArrayVec = Vec<ScalarT, length, ArrayVecImpl>;

}  //namespace ishi

#endif //CORE_ALGEBRA_ARRAY_VEC_H
