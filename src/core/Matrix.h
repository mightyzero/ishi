#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <type_traits>  // enable_if

#include <blitz/array.h>

#include <core/Common.h>

/*=============================================================================+
 | Class Forward Declarations
 +============================================================================*/
template<typename T, uint32_t R, uint32_t C> 
class Matrix;

/*=============================================================================+
 | Function Prototypes                                                         |
 +============================================================================*/
template<typename T, uint32_t R, uint32_t C>
Matrix<T,C,R> transpose(const Matrix<T,R,C>& mat);

template<typename T, uint32_t R, uint32_t C>
bool operator==(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

template<typename T, uint32_t R, uint32_t C>
bool operator!=(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator+(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

template<typename T, uint32_t R, uint32_t C>
Matrix<T,R,C> operator-(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

template<typename T, uint32_t R1, uint32_t C, uint32_t C2>
Matrix<T,R1,C2> operator*(
	const Matrix<T,R1,C>& mat1,
	const Matrix<T,C,C2>& mat2
);

template<typename T, uint32_t R, uint32_t C, typename T2,
		 typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Matrix<T,R,C> operator*(const Matrix<T,R,C>& mat, const T2& factor);

template<typename T, uint32_t R, uint32_t C, typename T2,
		 typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
Matrix<T,R,C> operator*(const T2& factor, const Matrix<T,R,C>& mat);

/*=============================================================================+
 | Class Declaration
 +============================================================================*/

/***************************************************************************//**
 * \brief Parameterized class to represent and operate on matrices
 * 
 * \tparam T The type of scalar to be contained in the matrix
 * \tparam R The number of rows in the matrix
 * \tparam C The number of columns in the matrix
 ******************************************************************************/
template<typename T, uint32_t R, uint32_t C> 
class Matrix {
private:
	blitz::Array<T, 2> m_array;
	
public:
	
	/***********************************************************************//**
	 * \brief Default constructor
	 **************************************************************************/
	Matrix();
	
	/***********************************************************************//**
	 * \brief Copy constructor
	 **************************************************************************/
	Matrix(const Matrix& other);
	
	/***********************************************************************//**
	 * \brief Construct a matrix around existing data
	 **************************************************************************/
	Matrix(const blitz::Array<T, 2>& array);
	
	/***********************************************************************//**
	 * \brief Destructor
	 **************************************************************************/
	~Matrix() {}
	
	/***********************************************************************//**
	 * \brief Copy assignment
	 **************************************************************************/
	Matrix& operator=(const Matrix& other);
	
	/***********************************************************************//**
	 * \brief Assignment to existing data
	 **************************************************************************/
	Matrix& operator=(const blitz::Array<T, 2> array);
	
	/***********************************************************************//**
	 * \brief Assignment to comma-separated list of scalars
	 **************************************************************************/
	blitz::ListInitializationSwitch<blitz::Array<T, 2>>
	operator=(const T& scalar);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	
	template<typename T2> Matrix& operator*=(const T2& factor);

	T* data();
	const T* data() const;

	/*-------------------------------------------------------------------------+
	| Friend function declarations
	+-------------------------------------------------------------------------*/
	
	/***********************************************************************//**
	* \relates class Matrix
	* \brief Return the transpose of a matrix.
	*
	* \param mat The matrix to take transpose of
	* 
	* \return Instance of the transpose matrix
	***************************************************************************/
	friend Matrix<T,C,R> transpose<>(const Matrix<T,R,C>& mat);

	/***********************************************************************//**
	* \relates class Matrix
	* \brief Overload of the == operator
	* 
	* Return true if the two operand matrices are equal.
	* 
	* \param mat1 The first matrix
	* \param mat2 The second matrix
	* 
	* \return True if matrix has identical data, false if not
	***************************************************************************/
	friend bool operator==<>(const Matrix& mat1, const Matrix& mat2);
	
	/***********************************************************************//**
	* \relates class Matrix
	* \brief Overload of the != operator
	* 
	* Return true if the two operand matrices are NOT equal.
	* 
	* \param mat1 The first matrix
	* \param mat2 The second matrix
	* 
	* \return True if matrix has difference in data, false if not
	***************************************************************************/
	friend bool operator!=<>(const Matrix& mat1, const Matrix& mat2);

	/***********************************************************************//**
	* \relates class Matrix
	* \brief Overload of the + operator
	* 
	* Add two matrices element-wise and return the result.
	* 
	* \param mat1 The first matrix
	* \param mat2 The second matrix
	* 
	* \return Instance of the matrix that is the element-wise sum of the two
	*         operand matrices
	***************************************************************************/
	friend Matrix operator+<>(const Matrix& mat1, const Matrix& mat2);
	
	/***********************************************************************//**
	* \relates class Matrix
	* \brief Overload of the - operator
	* 
	* Subtract the second matrix from the first matrix element-wise and 
	* return the result.
	* 
	* \param mat1 The first matrix
	* \param mat2 The second matrix
	* 
	* \return Instance of the matrix that is the element-wise subtraction of
	*         the second matrix from the first
	***************************************************************************/
	friend Matrix operator-<>(const Matrix& mat1, const Matrix& mat2);
	
	template<typename T1, uint32_t R1, uint32_t C1, uint32_t C2>
	friend Matrix<T1,R1,C2> operator*(
		const Matrix<T1,R1,C1>& mat1,
		const Matrix<T1,C1,C2>& mat2
	);
	
	template<typename T1, uint32_t R1, uint32_t C1, typename T2,
			 typename std::enable_if<std::is_integral<T2>::value,int>::type>
	friend Matrix<T1,R1,C1> operator*(
		const Matrix<T1,R1,C1>& mat,
		const T2& factor
	);
	 
	template<typename T1, uint32_t R1, uint32_t C1, typename T2,
			 typename std::enable_if<std::is_integral<T2>::value,int>::type>
	friend Matrix<T1,R1,C1> operator*(
		const T2& factor,
		const Matrix<T1,R1,C1>& mat
	);
};

#endif // MATRIX_H