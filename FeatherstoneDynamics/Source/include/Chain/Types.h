#pragma once

#include <vector>
#include <eigen3/Eigen/Dense>

enum JOINT_TYPE
{
	REVOLUTE = 0,
	PRISMATIC = 1,
	SIXDOF = 2
};

enum COORD_AXIS
{
	X = 0,
	Y = 1,
	Z = 2
};

namespace MathTypes {
	// Vectors
	using Vec2 = typename Eigen::Matrix<float, 2, 1>;
	using Vec3 = typename Eigen::Matrix<float, 3, 1>;
	using Vec4 = typename Eigen::Matrix<float, 4, 1>;
	using Vec6 = typename Eigen::Matrix<float, 6, 1>;
	using Vec12 = typename Eigen::Matrix<float, 12, 1>;
	using Vec18 = typename Eigen::Matrix<float, 18, 1>;

	// Matrices

	using Mat3 = typename Eigen::Matrix<float, 3, 3>;
	using Mat4 = typename Eigen::Matrix<float, 4, 4>;
	using Mat6 = typename Eigen::Matrix<float, 6, 6>;
	using Mat12 = typename Eigen::Matrix<float, 12, 12>;
	using Mat18 = typename Eigen::Matrix<float, 18, 18>;
}