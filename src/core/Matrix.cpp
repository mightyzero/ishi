#include <core/Matrix.h>

/*=============================================================================+
 | Class Method Definitions
 +============================================================================*/
/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix() : m_array(R, C) {
	/// \note It may not be wise to allocate memory right here in the default
	/// constructor.
	// empty function body
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix(const Matrix<T,R,C>& other) : m_array(other.m_array) {
	// empty function body
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix(const blitz::Array<T, 2>& array) : m_array(array) {
	// empty function body
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator=(const Matrix<T,R,C>& other) {
	m_array = other.m_array;
	return *this;
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator=(const blitz::Array<T, 2> array) {
	m_array = array;
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator+=(const Matrix& other) {
	m_array += other.m_array;
	return (*this);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
template<typename T2>
Matrix<T,R,C>& Matrix<T,R,C>::operator*=(const T2& factor) {
	m_array *= factor;
	return (*this);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
blitz::ListInitializationSwitch<blitz::Array<T, 2>>
Matrix<T,R,C>::operator=(const T& scalar) {
	return m_array.operator=(scalar);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
T* Matrix<T,R,C>::data() {
	return m_array.data();
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
const T* Matrix<T,R,C>::data() const {
	return m_array.data();
}

/*=============================================================================+
 | Function Definitions                                                        |
 +============================================================================*/

template<typename T, uint32_t R, uint32_t C>
Matrix<T,C,R> transpose(const Matrix<T,R,C>& mat) {
	return Matrix<T,C,R>(mat.m_array.transpose(
		blitz::secondDim,
		blitz::firstDim));
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
bool operator==(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) {
	bool result = true;
	
	typename blitz::Array<T, 2>::const_iterator iter1 = mat1.m_array.begin();
	typename blitz::Array<T, 2>::const_iterator iter2 = mat2.m_array.begin();
	
	while (
		result &&
		iter1 != mat1.m_array.end() &&
		iter2 != mat2.m_array.end()
	) {
		result = (*iter1 == *iter2);
		iter1++;
		iter2++;
	}

	return result;
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
bool operator!=(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) {
	return !(mat1 == mat2);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator+(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) {
// 	return Matrix<T,R,C>(blitz::Array<T, 2>(mat1.m_array + mat2.m_array));
	return mat1;
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator-(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) {
// 	return Matrix<T,R,C>(blitz::Array<T, 2>(mat1.m_array - mat2.m_array));
	return mat1;
}

/**************************************************************************/
template<typename T, uint32_t R1, uint32_t C, uint32_t C2>
Matrix<T,R1,C2> operator*(
	const Matrix<T,R1,C>& mat1,
	const Matrix<T,C,C2>& mat2
) {
	blitz::Array<T, 2> result(R1, C2);
	const blitz::Array<T, 2> &arr1 = mat1.m_array, &arr2 = mat2.m_array;

	for (int i = 0; i < arr1.rows(); ++i) {
		for (int j = 0; j < arr2.cols(); ++j) {
			result(i, j) = blitz::sum(
				arr1(i, blitz::Range::all()) *
				arr2(blitz::Range::all(), j)
			);
		}
	}

	return Matrix<T,R1,C2>(result);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C, typename T2,
		 typename std::enable_if<std::is_integral<T2>::value,int>::type>
Matrix<T,R,C> operator*(const Matrix<T,R,C>& mat, const T2& factor) {
	return Matrix<T,R,C>(blitz::Array<T, 2>(mat.m_array * factor));
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C, typename T2,
		 typename std::enable_if<std::is_integral<T2>::value,int>::type>
Matrix<T,R,C> operator*(const T2& factor, const Matrix<T,R,C>& mat) {
	return Matrix<T,R,C>(blitz::Array<T, 2>(factor * mat.m_array));
}
