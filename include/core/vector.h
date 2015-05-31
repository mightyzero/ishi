#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include <Eigen/Dense>

namespace nf {

	class Vector : public Base {
	public:
		typedef Eigen::Vector3f Base;

		/** Constructor using scalars. Double as the default constructor. */
		Vector(float x = 0, float y = 0, float z = 0) : Base(x, y, z) { }

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
