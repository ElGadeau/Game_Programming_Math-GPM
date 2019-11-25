#pragma once

#include <complex>
#include <utility>
#include <GPM/Tools/Utils.h>

namespace GPM
{
#pragma region Constructors & Assignment
	inline Quaternion::Quaternion()
		: axis{ 0.0f, 0.0f, 0.0f }, w{ 0.0f }
	{	}

	inline Quaternion::Quaternion(const float p_x, const float p_y, const float p_z,
		const float p_w)
		: axis{ p_x, p_y, p_z }, w{ p_w }
	{	}

	inline Quaternion::Quaternion(const float p_scalar, const Vector3F& p_vector)
		: axis{ p_vector }, w{ p_scalar }
	{	}

	inline Quaternion::Quaternion(const Quaternion& p_other)
		: axis{ p_other.axis.x, p_other.axis.y, p_other.axis.z }, w{ p_other.w }
	{	}

	inline Quaternion::Quaternion(Quaternion&& p_other) noexcept
		: axis{ std::move(p_other.axis) }, w{ p_other.w }
	{	}

	inline Quaternion::Quaternion(const Vector3<float>& p_axis,
		const float p_angleInRadians)
		: axis{ 0.0f, 0.0f, 0.0f }
	{
		w = Tools::Utils::CosF(p_angleInRadians / 2.0f);

		axis.x = p_axis.x * Tools::Utils::SinF(p_angleInRadians / 2.0f);
		axis.y = p_axis.y * Tools::Utils::SinF(p_angleInRadians / 2.0f);
		axis.z = p_axis.z * Tools::Utils::SinF(p_angleInRadians / 2.0f);
	}

	inline Quaternion& Quaternion::operator=(Quaternion&& p_other) noexcept
	{
		w = p_other.w;
		axis = p_other.axis;

		return (*this);
	}

	inline Quaternion Quaternion::operator+(const Quaternion& p_otherQuaternion) const
	{
		return  { Quaternion{  w + p_otherQuaternion.w, axis + p_otherQuaternion.axis } };
	}

	inline Quaternion& Quaternion::operator+=(const Quaternion& p_otherQuaternion)
	{
		w += p_otherQuaternion.w;
		axis += p_otherQuaternion.axis;

		return { *this };
	}

	inline Quaternion Quaternion::operator-(const Quaternion& p_otherQuaternion) const
	{
		return  { Quaternion{  w - p_otherQuaternion.w, axis - p_otherQuaternion.axis } };
	}

	inline Quaternion& Quaternion::operator-=(const Quaternion& p_otherQuaternion)
	{
		w -= p_otherQuaternion.w;
		axis -= p_otherQuaternion.axis;

		return { *this };
	}

	inline float Quaternion::DotProduct(const Quaternion& p_otherQuaternion) const
	{
		return w * p_otherQuaternion.w + axis.x * p_otherQuaternion.axis.x + axis.y * p_otherQuaternion.axis.y + axis.z * p_otherQuaternion.axis.z;
	}

	inline float Quaternion::DotProduct(const Quaternion& p_left, const Quaternion& p_right)
	{
		return p_left.w * p_right.w + p_left.axis.x * p_right.axis.x + p_left.axis.y * p_right.axis.y + p_left.axis.z * p_right.axis.z;
	}

	inline Quaternion& Quaternion::operator*=(const float p_scale)
	{
		w *= p_scale;
		axis *= p_scale;

		return { *this };
	}

	inline Quaternion Quaternion::operator*(const float p_scale) const
	{
		return { Quaternion{w * p_scale, axis * p_scale} };
	}

	inline Quaternion Quaternion::operator*(const Quaternion& p_otherQuaternion) const
	{
		const float scalar = w * p_otherQuaternion.w - axis.Dot(p_otherQuaternion.axis);

		const Vector3F imaginary = p_otherQuaternion.axis * w + axis * p_otherQuaternion.w + axis.Cross(p_otherQuaternion.axis);

		return { Quaternion(scalar, imaginary) };
	}

	inline Quaternion& Quaternion::operator*=(const Quaternion& p_otherQuaternion)
	{
		(*this) = Multiply(p_otherQuaternion);

		return { (*this) };
	}

	inline Quaternion Quaternion::operator*(const Vector3<float>& p_toMultiply) const
	{
		const float sPart = -(axis.x * p_toMultiply.x + axis.y * p_toMultiply.y + axis.z * p_toMultiply.z);
		const float xPart = w * p_toMultiply.x + axis.y * p_toMultiply.z - axis.z * p_toMultiply.y;
		const float yPart = w * p_toMultiply.y + axis.z * p_toMultiply.x - axis.x * p_toMultiply.z;
		const float zPart = w * p_toMultiply.z + axis.x * p_toMultiply.y - axis.y * p_toMultiply.x;

		const Vector3F vectorPart(xPart, yPart, zPart);

		return { Quaternion{ sPart, vectorPart } };
	}

	inline Quaternion& Quaternion::operator*=(const Vector3<float>& p_toMultiply)
	{
		const float sPart = -(axis.x * p_toMultiply.x + axis.y * p_toMultiply.y + axis.z * p_toMultiply.z);
		const float xPart = w * p_toMultiply.x + axis.y * p_toMultiply.z - axis.z * p_toMultiply.y;
		const float yPart = w * p_toMultiply.y + axis.z * p_toMultiply.x - axis.x * p_toMultiply.z;
		const float zPart = w * p_toMultiply.z + axis.x * p_toMultiply.y - axis.y * p_toMultiply.x;

		const Vector3F vectorPart(xPart, yPart, zPart);

		w = sPart;
		axis = vectorPart;

		return { (*this) };
	}

	inline Quaternion Quaternion::Multiply(const Quaternion& p_quaternion) const
	{
		const float scalar = w * p_quaternion.w - axis.Dot(p_quaternion.axis);

		const Vector3F imaginary = p_quaternion.axis * w + axis * p_quaternion.axis + axis.Cross(p_quaternion.axis);

		return { Quaternion {scalar,imaginary} };

	}

	inline float Quaternion::Norm() const
	{
		return Tools::Utils::SquareRootF(w * w + axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	}

	inline Quaternion& Quaternion::Inverse()
	{
		float absoluteValue = Norm();
		absoluteValue *= absoluteValue;
		absoluteValue = 1 / absoluteValue;

		const Quaternion conjugateValue = Conjugate();

		const float scalar = conjugateValue.w * (absoluteValue);
		const Vector3F imaginary = conjugateValue.axis * (absoluteValue);

		w = scalar;
		axis = imaginary;

		return { (*this) };
	}

	inline Quaternion Quaternion::Inverse(const Quaternion& p_quaternion)
	{
		float absoluteValue = p_quaternion.Norm();
		absoluteValue *= absoluteValue;
		absoluteValue = 1 / absoluteValue;

		const Quaternion conjugateValue = Conjugate(p_quaternion);

		const float scalar = conjugateValue.w * (absoluteValue);
		const Vector3F imaginary = conjugateValue.axis * (absoluteValue);

		return { Quaternion {scalar, imaginary} };
	}

	inline Quaternion& Quaternion::Conjugate()
	{
		axis *= -1.0f;

		return { (*this) };
	}

	inline Quaternion Quaternion::Conjugate(const Quaternion& p_quaternion)
	{
		return { Quaternion { p_quaternion.w, p_quaternion.axis * -1.0f } };
	}

	constexpr float Quaternion::NormSquare() const
	{
		return w * w + axis.x * axis.x + axis.y * axis.y + axis.z * axis.z;
	}

	inline Quaternion& Quaternion::Normalize()
	{
		if (Norm() != 0) {
			const float normValue = 1 / Norm();

			w *= normValue;
			axis *= normValue;
		}

		return { (*this) };
	}

	inline Quaternion Quaternion::Normalize(const Quaternion& p_quaternion)
	{
		float scalar = 0.0f;

		Vector3F vector;

		if (p_quaternion.Norm() != 0.0f) {
			const float normValue = 1.0f / p_quaternion.Norm();

			scalar = p_quaternion.w * normValue;
			vector = p_quaternion.axis * normValue;
		}

		return { Quaternion{ scalar, vector} };
	}

	inline Vector3<float> Quaternion::ToEuler() const
	{
		// 3x3 matrix - column major. X vector is 0, 1, 2, etc. (openGL prefer way)
		//	0	3	6
		//	1	4	7
		//	2	5	8

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		const float test = 2.0f * (axis.x * axis.z - w * axis.y);

		if (test != 1.0f && test != -1.0f) {

			x = atan2(axis.y * axis.z + w * axis.x, 0.5f - (axis.x * axis.x + axis.y * axis.y));
			y = asin(-2.0f * (axis.x * axis.z - w * axis.y));
			z = atan2(axis.x * axis.y + w * axis.z, 0.5f - (axis.y * axis.y + axis.z * axis.z));

		}
		else if (test == 1.0f) {
			z = atan2(axis.x * axis.y + w * axis.z, 0.5f - (axis.y * axis.y + axis.z * axis.z));
			y = static_cast<float>(-Tools::M_PI) / 2.0f;
			x = -z + atan2(axis.x * axis.y - w * axis.z, axis.x * axis.z + w * axis.y);

		}
		else if (test == -1.0f) {

			z = atan2(axis.x * axis.y + w * axis.z, 0.5f - (axis.y * axis.y + axis.z * axis.z));
			y = static_cast<float>(Tools::M_PI) / 2.0f;
			x = z + atan2(axis.x * axis.y - w * axis.z, axis.x * axis.z + w * axis.y);

		}

		x = Tools::Utils::ToDegrees(x);
		y = Tools::Utils::ToDegrees(y);
		z = Tools::Utils::ToDegrees(z);

		Vector3<float> euler(x, y, z);

		return euler;
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