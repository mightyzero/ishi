#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include <Eigen/Dense>

namespace nf {

	class Vector : public Base {
		typedef Eigen::Vector3f Base;

		Vector() : Base() { }

		/**
	 * Copy constructor.
	 *
	 * Allows construction from Eigen expressions.
	 */
		template<typename T>
		Vector(const Eigen::MatrixBase <T> &other)
				: Base(other) { }

		/**
	 * Assignment operator.
	 *
	 * Allows assignment from Eigen expressions.
	 */
		template<typename T>
		Vector &operator=(const Eigen::MatrixBase <T> &other) {
			Base::operator=(other);
			return *this;
		}
	};
}


#endif 	// CORE_VECTOR_H
