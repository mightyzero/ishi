#ifndef CORE_POINT_H
#define CORE_POINT_H

#include <Eigen/Dense>

class Point : public Eigen::Vector3f {
public:
	typedef Eigen::Vector3f Base;

	/** Constructor using scalars. Double as the default constructor. */
	Point(float x = 0, float y = 0, float z = 0) : Base(x, y, z) {}

	/**
	 * Copy constructor.
	 *
	 * Allows construction from Eigen expressions.
	 */
	template <typename T>
	Point(const Eigen::MatrixBase<T>& other)
	: Base(other) {}

	/**
	 * Assignment operator.
	 *
	 * Allows assignment from Eigen expressions.
	 */
	template<typename T>
	Point& operator=(const Eigen::MatrixBase<T>& other) {
		Base::operator=(other);
		return *this;
	}
};

#endif // CORE_POINT_H
