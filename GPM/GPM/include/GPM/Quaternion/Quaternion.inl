#pragma once

#include <utility>
#include <GPM/Tools/Utils.h>

namespace GPM
{
	Quaternion Quaternion::identity = Quaternion{ 0.0f, 0.0f, 0.0f, 1.0f };

#pragma region Constructors & Assignment
	inline Quaternion::Quaternion()
		: axis{ 0.0f, 0.0f, 0.0f }, w{ 1.0f }
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

	inline Quaternion::Quaternion(const Matrix3<float>& p_matrix)
		: axis { 0.0f, 0.0f, 0.0f }, w { 1.0f }
	{
		const float trace = p_matrix.m_data[0] + p_matrix.m_data[4] + p_matrix.m_data[8];

		if (trace > 0.0f)
		{      //s=4*qw

			w = 0.5f * Tools::Utils::SquareRootF(1.0f + trace);
			const float S = 0.25f / w;

			axis.x = S * (p_matrix.m_data[5] - p_matrix.m_data[7]);
			axis.y = S * (p_matrix.m_data[6] - p_matrix.m_data[2]);
			axis.z = S * (p_matrix.m_data[1] - p_matrix.m_data[3]);

		}
		else if (p_matrix.m_data[0] > p_matrix.m_data[4] && p_matrix.m_data[0] > p_matrix.m_data[8])
		{ //s=4*qx

			axis.x = 0.5f * Tools::Utils::SquareRootF(1.0f + p_matrix.m_data[0] - p_matrix.m_data[4] - p_matrix.m_data[8]);
			const float X = 0.25f / axis.x;

			axis.y = X * (p_matrix.m_data[3] + p_matrix.m_data[1]);
			axis.z = X * (p_matrix.m_data[6] + p_matrix.m_data[2]);
			w = X * (p_matrix.m_data[5] - p_matrix.m_data[7]);
		}
		else if (p_matrix.m_data[4] > p_matrix.m_data[8])
		{ //s=4*qy

			axis.y = 0.5f * Tools::Utils::SquareRootF(1.0f - p_matrix.m_data[0] + p_matrix.m_data[4] - p_matrix.m_data[8]);
			const float Y = 0.25f / axis.y;
			axis.x = Y * (p_matrix.m_data[3] + p_matrix.m_data[1]);
			axis.z = Y * (p_matrix.m_data[7] + p_matrix.m_data[5]);
			w = Y * (p_matrix.m_data[6] - p_matrix.m_data[2]);

		}
		else
		{ //s=4*qz

			axis.z = 0.5f * Tools::Utils::SquareRootF(1.0f - p_matrix.m_data[0] - p_matrix.m_data[4] + p_matrix.m_data[8]);
			const float Z = 0.25f / axis.z;
			axis.x = Z * (p_matrix.m_data[6] + p_matrix.m_data[2]);
			axis.y = Z * (p_matrix.m_data[7] + p_matrix.m_data[5]);
			w = Z * (p_matrix.m_data[1] - p_matrix.m_data[3]);
		}
	}

	inline Quaternion::Quaternion(const Matrix4<float>& p_matrix)
		: axis{ 0.0f, 0.0f, 0.0f }, w { 1.0f }
	{
		w = Tools::Utils::SquareRootF(std::max(0.0f, 1.0f + p_matrix.m_data[0] + p_matrix.m_data[5] + p_matrix.m_data[10])) / 2.0f;
		axis.x = Tools::Utils::SquareRootF(std::max(0.0f, 1.0f + p_matrix.m_data[0] - p_matrix.m_data[5] - p_matrix.m_data[10])) / 2.0f;
		axis.y = Tools::Utils::SquareRootF(std::max(0.0f, 1.0f - p_matrix.m_data[0] + p_matrix.m_data[5] - p_matrix.m_data[10])) / 2.0f;
		axis.z = Tools::Utils::SquareRootF(std::max(0.0f, 1.0f - p_matrix.m_data[0] - p_matrix.m_data[5] + p_matrix.m_data[10])) / 2.0f;

		axis.x *= Tools::Utils::Sign(axis.x * (p_matrix.m_data[9] - p_matrix.m_data[6]));
		axis.y *= Tools::Utils::Sign(axis.y * (p_matrix.m_data[2] - p_matrix.m_data[8]));
		axis.z *= Tools::Utils::Sign(axis.z * (p_matrix.m_data[4] - p_matrix.m_data[1]));
	}

	inline Quaternion::Quaternion(const Vector3<float>& p_axis,
		const float p_angleInRadians)
		: axis{ 0.0f, 0.0f, 0.0f }
	{
		w = Tools::Utils::CosF(p_angleInRadians / 2.0f);

		const float sinAngle = Tools::Utils::SinF(p_angleInRadians / 2.0f);
		
		axis.x = sinAngle * p_axis.x;
		axis.y = sinAngle * p_axis.y;
		axis.z = sinAngle * p_axis.z;

		std::cout << "w:" << w << "\t axis:" << axis.ToString() << "\n";
	}

	inline void Quaternion::MakeFromEuler(const Vector3<float>& p_euler)
	{
		float x = Tools::Utils::ToRadians(p_euler.x);
		float y = Tools::Utils::ToRadians(p_euler.y);
		float z = Tools::Utils::ToRadians(p_euler.z);

		x = x / 2.0f;
		y = y / 2.0f;
		z = z / 2.0f;

		w = cos(z) * cos(y) * cos(x) + sin(z) * sin(y) * sin(x);
		axis.x = cos(z) * cos(y) * sin(x) - sin(z) * sin(y) * cos(x);
		axis.y = cos(z) * sin(y) * cos(x) + sin(z) * cos(y) * sin(x);
		axis.z = sin(z) * cos(y) * cos(x) - cos(z) * sin(y) * sin(x);
	}

	inline void Quaternion::MakeFromEuler(const float p_x, const float p_y, const float p_z)
	{
		float x = Tools::Utils::ToRadians(p_x);
		float y = Tools::Utils::ToRadians(p_y);
		float z = Tools::Utils::ToRadians(p_z);

		x = x / 2.0f;
		y = y / 2.0f;
		z = z / 2.0f;

		w = cos(z) * cos(y) * cos(x) + sin(z) * sin(y) * sin(x);
		axis.x = cos(z) * cos(y) * sin(x) - sin(z) * sin(y) * cos(x);
		axis.y = cos(z) * sin(y) * cos(x) + sin(z) * cos(y) * sin(x);
		axis.z = sin(z) * cos(y) * cos(x) - cos(z) * sin(y) * sin(x);
	}

	inline Quaternion& Quaternion::operator=(Quaternion&& p_other) noexcept
	{
		w = p_other.w;
		axis = p_other.axis;

		return (*this);
	}

	inline bool Quaternion::IsIdentity() const
	{
		return axis.x == 0.0f && axis.y == 0.0f && axis.z == 0.0f;
	}

	inline bool Quaternion::IsPure() const
	{
		return w == 0.0f;
	}

	inline bool Quaternion::IsNormalized() const
	{
		return Norm() == 1.0f;
	}

	inline bool Quaternion::operator==(const Quaternion& p_otherQuaternion) const
	{
		return w == p_otherQuaternion.w && axis == p_otherQuaternion.axis;
	}

	inline bool Quaternion::operator!=(const Quaternion& p_otherQuaternion) const
	{
		return w != p_otherQuaternion.w || axis != p_otherQuaternion.axis;
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
		return { (*this).Multiply(p_otherQuaternion) };
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

		return { Quaternion{ sPart, Vector3F { xPart, yPart, zPart } } };
	}

	inline Quaternion& Quaternion::operator*=(const Vector3<float>& p_toMultiply)
	{
		const float sPart = -(axis.x * p_toMultiply.x + axis.y * p_toMultiply.y + axis.z * p_toMultiply.z);
		const float xPart = w * p_toMultiply.x + axis.y * p_toMultiply.z - axis.z * p_toMultiply.y;
		const float yPart = w * p_toMultiply.y + axis.z * p_toMultiply.x - axis.x * p_toMultiply.z;
		const float zPart = w * p_toMultiply.z + axis.x * p_toMultiply.y - axis.y * p_toMultiply.x;

		w = sPart;
		axis = Vector3F{ xPart, yPart, zPart };

		return { (*this) };
	}

	inline Quaternion Quaternion::Multiply(const Quaternion& p_quaternion) const
	{
		const float scalar = w * p_quaternion.w - axis.Dot(p_quaternion.axis);

		const Vector3F imaginary = p_quaternion.axis * w + axis * p_quaternion.axis + axis.Cross(p_quaternion.axis);

		return { Quaternion { scalar,imaginary } };

	}

	inline float Quaternion::Norm() const
	{
		return Tools::Utils::SquareRootF(w * w + axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	}

	inline Quaternion& Quaternion::Inverse()
	{
		float absoluteValue = NormSquare();
		absoluteValue = 1.0f / absoluteValue;

		const Quaternion conjugateValue = Conjugate();

		const float scalar = conjugateValue.w * (absoluteValue);
		const Vector3F imaginary = conjugateValue.axis * (absoluteValue);

		w = scalar;
		axis = imaginary;

		return { (*this) };
	}

	inline Quaternion Quaternion::Inverse(const Quaternion& p_quaternion)
	{
		float absoluteValue = p_quaternion.NormSquare();
		absoluteValue = 1 / absoluteValue;

		const Quaternion conjugateValue = Conjugate(p_quaternion);

		return { Quaternion {conjugateValue.w * absoluteValue, Vector3F {conjugateValue.axis * absoluteValue} } };
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

	inline Quaternion& Quaternion::ConvertToUnitNormQuaternion()
	{
		const float angle = Tools::Utils::ToRadians(w);

		axis.Normalize();
		w = Tools::Utils::CosF(angle * 0.5f);
		axis = axis * Tools::Utils::SinF(angle * 0.5f);

		return { (*this) };
	}

	inline Vector3F Quaternion::RotateVectorAboutAngleAndAxis(const float p_angle, const Vector3F& p_axis, const Vector3F& p_vectorToRotate)
	{
		const Quaternion p{ 0, p_vectorToRotate };

		//normalize the axis
		const Vector3F uAxis = p_axis.Normalized();

		//create the real quaternion
		Quaternion q{ p_angle, uAxis };

		//convert quaternion to unit norm quaternion
		q.ConvertToUnitNormQuaternion();

		const Quaternion qInverse = Inverse(q);

		const Quaternion rotatedVector = q * p * qInverse;

		return rotatedVector.axis;
	}

	inline Vector3<float> Quaternion::GetRotationAxis() const
	{
		return axis;
	}

	inline float Quaternion::GetXAxisValue() const
	{
		return axis.x;
	}

	inline float Quaternion::GetYAxisValue() const
	{
		return axis.y;
	}

	inline float Quaternion::GetZAxisValue() const
	{
		return axis.z;
	}

	inline float Quaternion::GetRealValue() const
	{
		return w;
	}

	inline void Quaternion::SetXAxisValue(const float p_xValue)
	{
		axis.x = p_xValue;
	}

	inline void Quaternion::SetYAxisValue(const float p_yValue)
	{
		axis.y = p_yValue;
	}

	inline void Quaternion::SetZAxisValue(const float p_zValue)
	{
		axis.z = p_zValue;
	}

	inline void Quaternion::SetRealValue(const float p_realValue)
	{
		w = p_realValue;
	}

	inline Quaternion Quaternion::Lerp(const Quaternion& p_first, const Quaternion& p_second,
		const float p_alpha)
	{
		const float coefficient = 1.0f - p_alpha;

		return  { Quaternion { coefficient * p_first.axis.x + p_alpha * p_second.axis.x,
							coefficient * p_first.axis.y + p_alpha * p_second.axis.y,
							coefficient * p_first.axis.z + p_alpha * p_second.axis.z,
							coefficient * p_first.w + p_alpha * p_second.w }.Normalize() };
	}

	inline Quaternion Quaternion::Slerp(const Quaternion& p_first, const Quaternion& p_second,
		const float p_alpha)
	{
		Quaternion result;

		const float coefficient = 1.0f - p_alpha;
		const float theta = Tools::Utils::ArccosF(p_first.axis.x * p_second.axis.x + p_first.axis.y * p_second.axis.y + p_first.axis.z * p_second.axis.z + p_first.w * p_second.w);
		const float sn = Tools::Utils::SinF(theta);
		const float wa = Tools::Utils::SinF(coefficient * theta) / sn;
		const float wb = Tools::Utils::SinF(p_alpha * theta) / sn;

		result.axis.x = wa * p_first.axis.x + wb * p_second.axis.x;
		result.axis.y = wa * p_first.axis.y + wb * p_second.axis.y;
		result.axis.z = wa * p_first.axis.z + wb * p_second.axis.z;
		result.w = wa * p_first.w + wb * p_second.w;

		result.Normalize();

		return result;
	}

	inline Quaternion Quaternion::Nlerp(const Quaternion& p_first,
		const Quaternion& p_second, const float p_alpha)
	{
		return Lerp(p_first, p_second, p_alpha).Normalize();
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

	inline Quaternion Quaternion::ToUnitNormQuaternion()
	{
		const float angle = Tools::Utils::ToRadians(w);

		axis.Normalize();

		return { Quaternion { Tools::Utils::CosF(angle * 0.5f), axis * Tools::Utils::SinF(angle * 0.5f)} };
	}

	inline Vector3<float> Quaternion::ToEuler() const
	{
		Vector3<float> euler{};

		// roll (x-axis rotation)
		const float sinr_cosp = 2.0f * (w * axis.x + axis.y * axis.z);
		const float cosr_cosp = 1.0f - 2.0f * (axis.x * axis.x + axis.y * axis.y);
		euler.x = Tools::Utils::Arctan2F(sinr_cosp, cosr_cosp);

		// pitch (y-axis rotation)
		const float sinp = 2.0f * (w * axis.y - axis.z * axis.x);
		if (std::abs(sinp) >= 1.0f)
			euler.y = std::copysign(static_cast<float>(Tools::M_PI) / 2.0f, sinp); // use 90 degrees if out of range
		else
			euler.y = Tools::Utils::Arcsin(sinp);

		// yaw (z-axis rotation)
		const float siny_cosp = 2.0f * (w * axis.z + axis.x * axis.y);
		const float cosy_cosp = 1.0f - 2.0f * (axis.y * axis.y + axis.z * axis.z);
		euler.z = Tools::Utils::Arctan2F(siny_cosp, cosy_cosp);

		euler.x = Tools::Utils::ToDegrees(euler.x);
		euler.y = Tools::Utils::ToDegrees(euler.y);
		euler.z = Tools::Utils::ToDegrees(euler.z);

		return euler;
	}

	inline Quaternion Quaternion::ToQuaternion(const Vector3F& p_euler)
	{
		return { ToQuaternion(p_euler.x, p_euler.y, p_euler.z) };
	}

	inline Quaternion Quaternion::ToQuaternion(const float p_yaw, const float p_pitch, const float p_roll)
	{
		Quaternion result;

		const float cosYaw = Tools::Utils::CosF(p_yaw * 0.5f);
		const float sinYaw = Tools::Utils::SinF(p_yaw * 0.5f);
		const float cosPitch = Tools::Utils::CosF(p_pitch * 0.5f);
		const float sinPitch = Tools::Utils::SinF(p_pitch * 0.5f);
		const float cosRoll = Tools::Utils::CosF(p_roll * 0.5f);
		const float sinRoll = Tools::Utils::SinF(p_roll * 0.5f);

		result.w = cosYaw * cosPitch * cosRoll + sinYaw * sinPitch * sinRoll;
		result.axis.x = cosYaw * cosPitch * sinRoll - sinYaw * sinPitch * cosRoll;
		result.axis.y = sinYaw * cosPitch * sinRoll + cosYaw * sinPitch * cosRoll;
		result.axis.z = sinYaw * cosPitch * cosRoll - cosYaw * sinPitch * sinRoll;

		return { result };
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

	inline Matrix3<float> Quaternion::ToMatrix3() const
	{
		Matrix3<float> result;

		result.m_data[0] = 2.0f * (w * w + axis.x * axis.x) - 1.0f;
		result.m_data[3] = 2.0f * (axis.x * axis.y - w * axis.z);
		result.m_data[6] = 2.0f * (axis.x * axis.z + w * axis.y);

		result.m_data[1] = 2.0f * (axis.x * axis.y + w * axis.z);
		result.m_data[4] = 2.0f * (w * w + axis.y * axis.y) - 1.0f;
		result.m_data[7] = 2.0f * (axis.y * axis.z - w * axis.x);

		result.m_data[2] = 2.0f * (axis.x * axis.z - w * axis.y);
		result.m_data[5] = 2.0f * (axis.y * axis.z + w * axis.x);
		result.m_data[8] = 2.0f * (w * w + axis.z * axis.z) - 1.0f;

		return result;
	}

	inline Matrix4<float> Quaternion::ToMatrix4() const
	{
		return { Matrix4<float>{ w, -axis.x, -axis.y, -axis.z,
								axis.x, w, -axis.z, axis.y,
								axis.y, axis.z, w, -axis.x,
								axis.z, -axis.y, axis.x, w } };
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