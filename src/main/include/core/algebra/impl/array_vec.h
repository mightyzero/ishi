#ifndef CORE_ALGEBRA_ARRAY_VEC_H
#define CORE_ALGEBRA_ARRAY_VEC_H

#include <array>

#include <core/algebra/vec.h>
#include <core/algebra/vec_trait.h>

namespace ishi {

// Forward declaration
template <typename ScalarT, size_t length>
class ArrayVec;

/**
 * Specialization of VecTrait for ArrayVec.
 */
template <typename ScalarT, size_t length>
struct VecTrait<ArrayVec<ScalarT, length>> {
	typedef ScalarT type;
};

// Forward declaration of friend method swap
template <typename ScalarT, size_t length>
void swap(ArrayVec<ScalarT, length> &lhs, ArrayVec<ScalarT, length> &rhs);

/**
 * Addition operator.
 */
template <typename ScalarT, size_t length>
ArrayVec<ScalarT, length> operator+(ArrayVec<ScalarT, length> lhs, const ArrayVec<ScalarT, length>& rhs) {
	lhs += rhs;
	return lhs;
}

/**
 * Subtraction operator.
 */
template<typename ScalarT, size_t length>
ArrayVec<ScalarT, length> operator-(ArrayVec<ScalarT, length> lhs, const ArrayVec<ScalarT, length>& rhs) {
	lhs -= rhs;
	return lhs;
}

/**
 * Multiplication operator.
 */
template<typename ScalarT, size_t length>
ArrayVec<ScalarT, length> operator*(ArrayVec<ScalarT, length> lhs, ScalarT scalar) {
	lhs *= scalar;
	return lhs;
}

/**
 * Multiplication operator.
 */
template<typename ScalarT, size_t length>
ArrayVec<ScalarT, length> operator*(ScalarT scalar, ArrayVec<ScalarT, length> rhs) {
	return rhs * scalar;
}

/**
 * Division operator.
 */
template<typename ScalarT, size_t length>
ArrayVec<ScalarT, length> operator/(ArrayVec<ScalarT, length> lhs, ScalarT scale) {
	lhs /= scale;
	return lhs;
}

/**
 * Implementation of Vec using std::array as backing data store.
 */
template <typename ScalarT, size_t length>
class ArrayVec : public Vec<ArrayVec<ScalarT, length>> {
public:
	typedef typename VecTrait<ArrayVec>::type value_type;

private:
	std::array<ScalarT, length> m_data;

public:
	friend void swap(ArrayVec &lhs, ArrayVec &rhs) {
		std::swap(lhs.m_data, rhs.m_data);
	}

public:
	/** Default constructor. */
	ArrayVec() {
		m_data.fill(0);
	}

	/** Constructor from variable scalars. */
	template <typename... ScalarTs>
	ArrayVec(ScalarT first, ScalarTs... rest) {
		m_data = {{first, rest...}};
	}

	/** Copy constructor. */
	ArrayVec(const ArrayVec &that) : m_data(that.m_data) { }

	/** Move constructor. */
	ArrayVec(ArrayVec &&that) : ArrayVec() {
		swap(*this, that);
	}

	/**
	 * Assignment operator.
	 *
	 * This method is implemented using the copy-and-swap idiom. See:
	 * http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
	 */
	ArrayVec &operator=(ArrayVec that) {
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
	ArrayVec &operator+=(const Vec<ArrayVec> &that) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] += that[i];
		}
		return *this;
	}

	/** Compound subtraction operator. */
	ArrayVec &operator-=(const Vec<ArrayVec> &that) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] -= that[i];
		}
		return *this;
	}

	/** Compound multiplication operator. */
	ArrayVec &operator*=(ScalarT scalar) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] *= scalar;
		}
		return *this;
	}

	/** Compound division operator. */
	ArrayVec &operator/=(ScalarT scalar) {
		for (size_t i = 0; i < length; ++i) {
			m_data[i] /= scalar;
		}
		return *this;
	}
};

}

#endif //CORE_ALGEBRA_ARRAY_VEC_H
