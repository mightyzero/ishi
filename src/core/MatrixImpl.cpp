// MatrixImpl.cpp
// Implement template class in Matrix.h
// Should be included by Matrix.h

/***********************************************************************//**
* \brief Default constructor
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix() : m_array(R, C)
{
	/// \note It may not be wise to allocate memory right here in the default
	/// constructor.
	// empty function body
}

/***********************************************************************//**
* \brief Copy constructor
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix(const Matrix<T,R,C>& other) : m_array(other.m_array)
{
	// empty function body
}

/***********************************************************************//**
* \brief Construct a matrix around existing data
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>::Matrix(const blitz::Array<T, 2>& array) : m_array(array)
{
	// empty function body
}

/***********************************************************************//**
* \brief Copy assignment
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator=(const Matrix<T,R,C>& other)
{
	m_array = other.m_array;
	return *this;
}

/***********************************************************************//**
* \brief Assignment to existing data
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator=(const blitz::Array<T, 2> array)
{
	m_array = array;
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C>& Matrix<T,R,C>::operator+=(const Matrix& other)
{
	m_array += other.m_array;
	return (*this);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
template<typename T2>
Matrix<T,R,C>& Matrix<T,R,C>::operator*=(const T2& factor) 
{
	m_array *= factor;
	return (*this);
}

/***********************************************************************//**
* \brief Assignment to comma-separated list of scalars
**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
blitz::ListInitializationSwitch<blitz::Array<T, 2>>
Matrix<T,R,C>::operator=(const T& scalar) 
{
	return m_array.operator=(scalar);
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
T* Matrix<T,R,C>::data()
{
	return m_array.data();
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C>
const T* Matrix<T,R,C>::data() const 
{
	return m_array.data();
}

/*=============================================================================+
 | Function Definitions                                                        |
 +============================================================================*/

/***********************************************************************//**
* \relates class Matrix
* \brief   Return the transpose of a matrix.
*
* \param   mat The matrix to take transpose of
* 
* \return  Instance of the transpose matrix
***************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,C,R> transpose(const Matrix<T,R,C>& mat) 
{
	return Matrix<T,C,R>(mat.m_array.transpose(
		blitz::secondDim,
		blitz::firstDim));
}

/***********************************************************************//**
* \relates class Matrix
* \brief   Overload of the == operator
* 
*          Return true if the two operand matrices are equal.
* 
* \param   mat1 The first matrix
* \param   mat2 The second matrix
* 
* \return  True if matrix has identical data, false if not
***************************************************************************/
template<typename T, uint32_t R, uint32_t C>
bool operator==(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) 
{
	bool result = true;
	
	typename blitz::Array<T, 2>::const_iterator iter1 = mat1.m_array.begin();
	typename blitz::Array<T, 2>::const_iterator iter2 = mat2.m_array.begin();
	
	while (result &&
		   iter1 != mat1.m_array.end() &&
		   iter2 != mat2.m_array.end()) 
	{
		result = (*iter1 == *iter2);
		iter1++;
		iter2++;
	}

	return result;
}

/***********************************************************************//**
* \relates class Matrix
* \brief   Overload of the != operator
* 
*          Return true if the two operand matrices are NOT equal.
* 
* \param   mat1 The first matrix
* \param   mat2 The second matrix
* 
* \return  True if matrix has difference in data, false if not
***************************************************************************/
template<typename T, uint32_t R, uint32_t C>
bool operator!=(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) 
{
	return !(mat1 == mat2);
}

/***********************************************************************//**
* \relates class Matrix
* \brief   Overload of the + operator
* 
*          Add two matrices element-wise and return the result.
* 
* \param   mat1 The first matrix
* \param   mat2 The second matrix
* 
* \return  Instance of the matrix that is the element-wise sum of the two
*          operand matrices
***************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator+(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2) 
{
// 	return Matrix<T,R,C>(blitz::Array<T, 2>(mat1.m_array + mat2.m_array));
	return mat1;
}

/***************************************************************************//**
* \relates class Matrix
* \brief   Overload of the - operator
* 
*          Subtract the second matrix from the first matrix element-wise and 
*          return the result.
* 
* \param   mat1 The first matrix
* \param   mat2 The second matrix
* 
* \return  Instance of the matrix that is the element-wise subtraction of
*          the second matrix from the first
*******************************************************************************/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator-(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2)
{
// 	return Matrix<T,R,C>(blitz::Array<T, 2>(mat1.m_array - mat2.m_array));
	return mat1;
}

/**************************************************************************/
template<typename T, uint32_t R1, uint32_t C, uint32_t C2>
Matrix<T,R1,C2> operator*(const Matrix<T,R1,C>& mat1,
	const Matrix<T,C,C2>& mat2) 
{
	blitz::Array<T, 2> result(R1, C2);
	const blitz::Array<T, 2> &arr1 = mat1.m_array, &arr2 = mat2.m_array;

	for (int i = 0; i < arr1.rows(); ++i)
	{
		for (int j = 0; j < arr2.cols(); ++j)
		{
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
Matrix<T,R,C> operator*(const Matrix<T,R,C>& mat, const T2& factor)
{
	return Matrix<T,R,C>(blitz::Array<T, 2>(mat.m_array * factor));
}

/**************************************************************************/
template<typename T, uint32_t R, uint32_t C, typename T2,
		 typename std::enable_if<std::is_integral<T2>::value,int>::type>
Matrix<T,R,C> operator*(const T2& factor, const Matrix<T,R,C>& mat)
{
	return Matrix<T,R,C>(blitz::Array<T, 2>(factor * mat.m_array));
}
