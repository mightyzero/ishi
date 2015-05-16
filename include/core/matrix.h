#ifndef CORE_MATRIX_H
#define CORE_MATRIX_H

#include <core/tensor.h>

// #include <iostream>
// #include <type_traits>  // enable_if

// #include <core/Common.h>

// /*=============================================================================+
//  | Class Forward Declarations
//  +============================================================================*/
// template<typename T, uint32_t R, uint32_t C>
// class Matrix;

// /*=============================================================================+
//  | Function Prototypes                                                         |
//  +============================================================================*/
// template<typename T, uint32_t R, uint32_t C>
// Matrix<T,C,R> transpose(const Matrix<T,R,C>& mat);

// template<typename T, uint32_t R, uint32_t C>
// bool operator==(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

// template<typename T, uint32_t R, uint32_t C>
// bool operator!=(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

// template<typename T, uint32_t R, uint32_t C>
// Matrix<T,R,C> operator+(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

// template<typename T, uint32_t R, uint32_t C>
// Matrix<T,R,C> operator-(const Matrix<T,R,C>& mat1, const Matrix<T,R,C>& mat2);

// template<typename T, uint32_t R1, uint32_t C, uint32_t C2>
// Matrix<T,R1,C2> operator*(
// 	const Matrix<T,R1,C>& mat1,
// 	const Matrix<T,C,C2>& mat2
// );

// template<typename T, uint32_t R, uint32_t C, typename T2,
// 		 typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
// Matrix<T,R,C> operator*(const Matrix<T,R,C>& mat, const T2& factor);

// template<typename T, uint32_t R, uint32_t C, typename T2,
// 		 typename std::enable_if<std::is_integral<T2>::value,int>::type = 0>
// Matrix<T,R,C> operator*(const T2& factor, const Matrix<T,R,C>& mat);

// /*=============================================================================+
//  | Class Declaration
//  +============================================================================*/

// **************************************************************************//**
//  * \brief Parameterized class to represent and operate on matrices
//  *
//  * \tparam T The type of scalar to be contained in the matrix
//  * \tparam R The number of rows in the matrix
//  * \tparam C The number of columns in the matrix
//  *****************************************************************************
// template<typename T, uint32_t R, uint32_t C>
// class Matrix {
// private:
// 	T m_array[R][C];

// public:
// 	// Constructors
// 	Matrix();
// 	Matrix(const Matrix& other);
// 	// Matrix(const blitz::Array<T, 2>& array);

// 	/***********************************************************************//**
// 	 * \brief Destructor
// 	 **************************************************************************/
// 	~Matrix() {}

// 	// Assignment operators
// 	Matrix& operator=(const Matrix& other);
// 	// Matrix& operator=(const blitz::Array<T, 2> array);
// 	// blitz::ListInitializationSwitch<blitz::Array<T, 2>>
// 	// operator=(const T& scalar);

// 	// Arithmetic operators
// 	Matrix& operator+=(const Matrix& other);
// 	Matrix& operator-=(const Matrix& other);
// 	Matrix& operator*=(const Matrix& other);

// 	template<typename T2> Matrix& operator*=(const T2& factor);

// 	T* data();
// 	const T* data() const;

// 	/*-------------------------------------------------------------------------+
// 	| Friend function declarations
// 	+-------------------------------------------------------------------------*/
// 	friend Matrix<T,C,R> transpose<>(const Matrix<T,R,C>& mat);

// 	friend bool operator==<>(const Matrix& mat1, const Matrix& mat2);
// 	friend bool operator!=<>(const Matrix& mat1, const Matrix& mat2);

// 	friend Matrix operator+<>(const Matrix& mat1, const Matrix& mat2);
// 	friend Matrix operator-<>(const Matrix& mat1, const Matrix& mat2);

// 	template<typename T1, uint32_t R1, uint32_t C1, uint32_t C2>
// 	friend Matrix<T1,R1,C2> operator*(
// 		const Matrix<T1,R1,C1>& mat1,
// 		const Matrix<T1,C1,C2>& mat2
// 	);

// 	template<typename T1, uint32_t R1, uint32_t C1, typename T2,
// 			 typename std::enable_if<std::is_integral<T2>::value,int>::type>
// 	friend Matrix<T1,R1,C1> operator*(
// 		const Matrix<T1,R1,C1>& mat,
// 		const T2& factor
// 	);

// 	template<typename T1, uint32_t R1, uint32_t C1, typename T2,
// 			 typename std::enable_if<std::is_integral<T2>::value,int>::type>
// 	friend Matrix<T1,R1,C1> operator*(
// 		const T2& factor,
// 		const Matrix<T1,R1,C1>& mat
// 	);
// };

// // Include implementation of Matrix template class
// // Note: The implementation must be in the header file. This is a requirement
// //       for all template classes
// #include <core/MatrixImpl.cpp>

template<typename T, uint r, uint c>
using Matrix = Tensor<T, r, c>;

#endif // CORE_MATRIX_H
