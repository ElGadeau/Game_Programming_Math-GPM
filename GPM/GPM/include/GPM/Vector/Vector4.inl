#pragma once

#include <stdexcept>
#include "GPM/Tools/Utils.h"

namespace GPM
{
#pragma region Constructors & Assignment

	template <typename T>
	constexpr Vector4<T>::Vector4()
		: x{ 0 }, y{ 0 }, z{ 0 }, w{ 1 } {}

	template <typename T>
	constexpr Vector4<T>::Vector4(T p_x, T p_y, T p_z, T p_w)
		: x{ p_x }, y{ p_y }, z{ p_z }, w{ p_w } {}

	template <typename T>
	constexpr Vector4<T>::Vector4(const Vector3<T>& p_other)
		: x{ p_other.x }, y{ p_other.y }, z{ p_other.z }, w{ 1 } {}

	template <typename T>
	constexpr Vector4<T>::Vector4(Vector3<T>&& p_other)
		: x{ p_other.x }, y{ p_other.y }, z{ p_other.z }, w{ 1 } {}

	template <typename T>
	constexpr Vector4<T>::Vector4(const Vector4<T>& p_other)
	{
		*this = p_other;
	}

	template <typename T>
	constexpr Vector4<T>::Vector4(Vector4<T>&& p_other) noexcept
	{
		*this = p_other;
	}

	template <typename T>
	constexpr Vector4<T>& Vector4<T>::operator=(const Vector4<T>& p_other)
	{
		x = p_other.x;
		y = p_other.y;
		z = p_other.z;
		w = p_other.w;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T>& Vector4<T>::operator=(Vector4<T>&& p_other) noexcept
	{
		x = p_other.x;
		y = p_other.y;
		z = p_other.z;
		w = p_other.w;

		return *this;
	}

#pragma endregion

#pragma region Arithmetic Operations

#pragma region Add

	template <typename T>
	Vector4<T>& Vector4<T>::Add(T p_scalar)
	{
		x += p_scalar;
		y += p_scalar;
		z += p_scalar;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Add(const Vector4<T>& p_left, const T p_scalar)
	{
		return Vector4<T>(p_left).Add(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::Add(const Vector4<T>& p_other)
	{
		x += p_other.x;
		y += p_other.y;
		z += p_other.z;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Add(const Vector4<T>& p_left, const Vector4<T>& p_right)
	{
		return Vector4<T>(p_left).Add(p_right);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator+(const T p_scalar) const
	{
		return Vector4<T>(*this).Add(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator+=(const T p_scalar)
	{
		return Add(p_scalar);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator+(const Vector4<T>& p_other) const
	{
		return Vector4<T>(*this).Add(p_other);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& p_other)
	{
		return Add(p_other);
	}

#pragma endregion
#pragma region Subtract

	template <typename T>
	Vector4<T>& Vector4<T>::Subtract(const T p_scalar)
	{
		x -= p_scalar;
		y -= p_scalar;
		z -= p_scalar;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Subtract(const Vector4<T>& p_left, const T p_scalar)
	{
		return Vector4<T>(p_left).Subtract(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::Subtract(const Vector4<T>& p_other)
	{
		x -= p_other.x;
		y -= p_other.y;
		z -= p_other.z;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Subtract(const Vector4<T>& p_left, const Vector4<T>& p_right)
	{
		return Vector4<T>(p_left).Subtract(p_right);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator-(const T p_scalar) const
	{
		return Vector4<T>(*this).Subtract(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator-=(const T p_scalar)
	{
		return Subtract(p_scalar);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator-(const Vector4<T>& p_other) const
	{
		return Vector4<T>(*this).Subtract(p_other);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& p_other)
	{
		return Subtract(p_other);
	}

#pragma endregion
#pragma region Multiply

	template <typename T>
	Vector4<T>& Vector4<T>::Multiply(const T p_scalar)
	{
		x *= p_scalar;
		y *= p_scalar;
		z *= p_scalar;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Multiply(const Vector4<T>& p_left, T p_scalar)
	{
		return Vector4<T>(p_left).Multiply(p_scalar);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator*(const T p_scalar) const
	{
		return Vector4<T>(*this).Multiply(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator*=(const T p_scalar)
	{
		return Multiply(p_scalar);
	}

#pragma endregion
#pragma region Divide

	template <typename T>
	Vector4<T>& Vector4<T>::Divide(const T p_scalar)
	{
		if (p_scalar == 0)
			throw std::logic_error("Division by 0");

		x /= p_scalar;
		y /= p_scalar;
		z /= p_scalar;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Divide(const Vector4<T>& p_left, const T p_scalar)
	{
		return Vector4<T>(p_left).Divide(p_scalar);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::operator/(const T p_scalar) const
	{
		return Vector4<T>(*this).Divide(p_scalar);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::operator/=(const T p_scalar)
	{
		return Divide(p_scalar);
	}

#pragma endregion

#pragma endregion
#pragma region Vector Operations

	template <typename T>
	constexpr T Vector4<T>::Length() const
	{
		return (static_cast<T>(Tools::Utils::SquareRootF(x * x + y * y + z * z)));
	}

	template <typename T>
	constexpr T Vector4<T>::Length(const Vector4<T>& p_vector)
	{
		return p_vector.Length();
	}

	template <typename T>
	constexpr T Vector4<T>::LengthSquare() const
	{
		return (static_cast<T>(x * x + y * y + z * z));
	}

	template <typename T>
	constexpr T Vector4<T>::LengthSquare(const Vector4<T>& p_vector)
	{
		return p_vector.LengthSquare();
	}

	template <typename T>
	constexpr T Vector4<T>::DotProduct(const Vector4<T>& p_other) const
	{
		Vector4<T> left = Vector4<T>::Homogenize(*this);
		Vector4<T> right = Vector4<T>::Homogenize(p_other);

		return left.x * right.x + left.y * right.y + left.z * right.z;
	}

	template <typename T>
	constexpr T Vector4<T>::DotProduct(const Vector4<T>& p_left, const Vector4<T>& p_right)
	{
		return p_left.DotProduct(p_right);
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::CrossProduct(const Vector4<T>& p_other) const
	{
		Vector4<T> result;

		if (w == 0 || p_other.w == 0)
			throw std::logic_error("Can't Compute CrossProduct, One of the params is a point: W = 0");

		Vector4<T> right = Vector4<T>::Homogenize(*this);
		Vector4<T> left = Vector4<T>::Homogenize(p_other);

		result.x = right.y * left.z - right.z * left.y;
		result.y = right.z * left.x - right.x * left.z;
		result.z = right.x * left.y - right.y * left.x;

		return result;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::CrossProduct(const Vector4<T>& p_left, const Vector4<T>& p_right)
	{
		return p_left.CrossProduct(p_right);
	}

	template <typename T>
	constexpr T Vector4<T>::TripleProduct(const Vector4<T>& p_left, const Vector4<T>& p_middle,
		const Vector4<T>& p_right)
	{
		const Vector4<T> resultCross = p_middle.CrossProduct(p_right);
		return p_left.DotProduct(resultCross);
	}

	template <typename T>
	constexpr T Vector4<T>::AngleBetween(const Vector4<T>& p_other) const
	{
		if (w == 0 || p_other.w == 0)
			throw std::logic_error("Can't Compute angle, One of the params is a point: W = 0");

		float dotProduct = DotProduct(p_other);
		T lengthProduct = Length() * p_other.Length();

		T fractionResult = dotProduct / lengthProduct;

		if (fractionResult > -1 && fractionResult < 1)
			return (static_cast<T>(Tools::Utils::Arccos(fractionResult)));

		return 0;
	}

	template <typename T>
	constexpr T Vector4<T>::AngleBetween(const Vector4<T>& p_left, const Vector4<T>& p_right)
	{
		return p_left.AngleBetween(p_right);
	}

	template <typename T>
	Vector4<T>& Vector4<T>::Normalize()
	{
		float length = Length();

		if (length > 0)
		{
			x /= length;
			y /= length;
			z /= length;
		}

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Normalize(const Vector4<T>& p_vector)
	{
		return Vector4<T>(p_vector).Normalize();
	}

	template <typename T>
	Vector4<T>& Vector4<T>::Homogenize()
	{
		if (w == 0)
			throw std::logic_error("Can't Homogenize a point: W = 0");

		if (w != 1)
		{
			x /= w;
			y /= w;
			z /= w;
			w = 1;
		}

		return *this;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Homogenize(const Vector4<T>& p_vector)
	{
		return Vector4<T>(p_vector).Homogenize();
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Lerp(const Vector4<T>& p_start, const Vector4<T>& p_end,
		float p_interpolationCoefficient)
	{
		if (p_interpolationCoefficient >= 0 && p_interpolationCoefficient <= 1)
			return (p_start + (p_end - p_start) * p_interpolationCoefficient);

		return p_start;
	}

	template <typename T>
	constexpr Vector4<T> Vector4<T>::Slerp(const Vector4<T>& p_start, const Vector4<T>& p_end,
		float p_interpolationCoefficient)
	{
		if (p_interpolationCoefficient >= 0 && p_interpolationCoefficient <= 1)
		{
			const float angle = p_start.AngleBetween(p_end) * p_interpolationCoefficient;
			Vector4<T> relativeVector = p_end - p_start * p_start.DotProduct(p_end);
			relativeVector.Normalize();

			return ((p_start * Tools::Utils::Cos(angle)) + (relativeVector * Tools::Utils::Sin(angle)));
		}

		return p_start;
	}

#pragma endregion
#pragma region Conversions

	template <typename T>
	constexpr std::string Vector4<T>::ToString() const
	{
		return std::string("x : " + std::to_string(x) + " y : " + std::to_string(y) +
			" z : " + std::to_string(z) + " w : " + std::to_string(w));
	}

	template <typename T>
	constexpr std::string Vector4<T>::ToString(const Vector4<T>& p_vector)
	{
		return p_vector.ToString();
	}

#pragma endregion

#pragma region Outside Operators

	template <typename T>
	constexpr std::ostream& operator<<(std::ostream& p_stream, const GPM::Vector4<T>& p_vector)
	{
		p_stream << "x : " << p_vector.x << " y : " << p_vector.y <<
			" z : " << p_vector.z << " w : " << p_vector.w;
		return p_stream;
	}

	template <typename T>
	constexpr Vector4<T> operator+(T p_scalar, const Vector4<T>& p_vector)
	{
		return p_vector + p_scalar;
	}

	template <typename T>
	constexpr Vector4<T>& operator+=(T p_scalar, Vector4<T>& p_vector)
	{
		return p_vector += p_scalar;
	}

	template <typename T>
	constexpr Vector4<T> operator-(T p_scalar, const Vector4<T>& p_vector)
	{
		return p_vector - p_scalar;
	}

	template <typename T>
	constexpr Vector4<T>& operator-=(T p_scalar, Vector4<T>& p_vector)
	{
		return p_vector -= p_scalar;
	}

	template <typename T>
	constexpr Vector4<T> operator*(T p_scalar, const Vector4<T>& p_vector)
	{
		return p_vector * p_scalar;
	}

	template <typename T>
	constexpr Vector4<T>& operator*=(T p_scalar, Vector4<T>& p_vector)
	{
		return p_vector *= p_scalar;
	}

	template <typename T>
	constexpr Vector4<T> operator/(T p_scalar, const Vector4<T>& p_vector)
	{
		return p_vector / p_scalar;
	}

	template <typename T>
	constexpr Vector4<T>& operator/=(T p_scalar, Vector4<T>& p_vector)
	{
		return p_vector /= p_scalar;
	}

#pragma endregion
}
