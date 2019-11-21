#pragma once

#include <complex>
#include <GPM/Tools/Utils.h>

namespace GPM
{
#pragma region Constructors & Assignment
	inline Quaternion::Quaternion()
		: axis{ 0.0f, 0.0f, 0.0f }, w{ 0.0f }
	{	}

	inline Quaternion::Quaternion(const float p_x, const float p_y, const float p_z,
		const float p_w)
		: axis { p_x, p_y, p_z }, w{ p_w }
	{	}

	inline Quaternion::Quaternion(const Quaternion& p_other)
		: axis { p_other.axis.x, p_other.axis.y, p_other.axis.z }, w{ p_other.w }
	{	}
	
	inline Quaternion::Quaternion(Quaternion&& p_other) noexcept
		: axis { std::move(p_other.axis) }, w { p_other.w }
	{	}

	inline Quaternion::Quaternion(const Vector3<float>& p_axis,
		const float p_angleInRadians)
		: axis { 0.0f, 0.0f, 0.0f }
	{
		w = Tools::Utils::CosF(p_angleInRadians / 2.0f);

		axis.x = p_axis.x * Tools::Utils::SinF(p_angleInRadians / 2.0f);
		axis.y = p_axis.y * Tools::Utils::SinF(p_angleInRadians / 2.0f);
		axis.z = p_axis.z * Tools::Utils::SinF(p_angleInRadians / 2.0f);
	}

	inline std::string Quaternion::ToString() const
	{
		return { std::string("(w: " + std::to_string(w) + "; x: " + std::to_string(axis.x) + ", y: " + std::to_string(axis.y) +
			", z: " + std::to_string(axis.z)) + ')' };
	}

	inline std::string Quaternion::ToString(const Quaternion& p_quaternion)
	{
		return { p_quaternion.ToString() };
	}

	inline std::ostream& operator<<(std::ostream& p_stream,
		const Quaternion& p_quaternion)
	{
		p_stream << "(w: " << p_quaternion.w << "; x: " << p_quaternion.axis.x << ", y: " << p_quaternion.axis.y <<
			", z: " << p_quaternion.axis.z << ')';
		return  { p_stream };
	}
#pragma endregion
}