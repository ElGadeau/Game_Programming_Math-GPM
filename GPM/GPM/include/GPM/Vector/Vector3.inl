#pragma once
#include <cmath>
#include <iostream>

#include "GPM/Tools/Utils.h"

namespace GPM
{
#pragma region Constructor

	template <typename T>
	template <typename U>
	constexpr Vector3<T>::Vector3(const Vector3<U>& p_other) : x{ p_other.x }, y{ p_other.y }, z{ p_other.z }{}

	template <typename T>
    template <typename U>
	constexpr Vector3<T>::Vector3(Vector3<U>&& p_other) noexcept
	{
		x = static_cast<T>(p_other.x);
		y = static_cast<T>(p_other.y);
		z = static_cast<T>(p_other.z);
	}

	template<typename T>
	constexpr void Vector3<T>::Set(T p_x, T p_y, T p_z)
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}

	template<typename T>
	Vector3<T> Vector3<T>::forward{ 0, 0, 1 };

	template<typename T>
	Vector3<T> Vector3<T>::right{ 1, 0, 0 };

	template<typename T>
	Vector3<T> Vector3<T>::up{ 0, 1, 0 };

	template<typename T>
	Vector3<T> Vector3<T>::zero{ 0, 0, 0 };

	template<typename T>
	Vector3<T> Vector3<T>::one{ 1, 1, 1 };

#pragma endregion
#pragma region Arithmetic

	template<typename T>
	template<typename U>
	constexpr Vector3<T> Vector3<T>::Add(const Vector3<U>& p_other)
	{
		x += p_other.x;
		y += p_other.y;
		z += p_other.z;

		return  { Vector3<T>(x + p_other.x, y + p_other.y, z + p_other.z) };
	}

	template<typename T>
	template<typename U>
	constexpr Vector3<T> Vector3<T>::Add(const Vector3<T>& p_left, const Vector3<U>& p_right)
	{
		return { Vector3<T>(p_left).Add(p_right) };
	}

	template<typename T>
	template<typename U>
	constexpr void Vector3<T>::Subtract(const Vector3<U>& p_other)
	{
		x -= p_other.x;
		y -= p_other.y;
		z -= p_other.z;
	}

	template<typename T>
	template<typename U>
	constexpr void Vector3<T>::Multiply(const Vector3<U>& p_other)
	{
		x *= p_other.x;
		y *= p_other.y;
		z *= p_other.z;
	}

	template<typename T>
	template<typename U>
	constexpr void Vector3<T>::Divide(const Vector3<U>& p_other)
	{
		x /= p_other.x;
		y /= p_other.y;
		z /= p_other.z;
	}

	template<typename T>
	constexpr void Vector3<T>::Scale(T p_factor)
	{
		x *= p_factor;
		y *= p_factor;
		z *= p_factor;
	}

#pragma endregion
#pragma region Vector Operations

	template<typename T>
	constexpr void Vector3<T>::Normalize()
	{
		Set(x / Magnitude(), y / Magnitude(), z / Magnitude());
	}
	template <typename T>
	template <typename U>
	constexpr Vector3<T> Vector3<T>::Cross(const Vector3<U>& p_other) const
	{
		Vector3<T> tmp{};
		tmp.x = (y * p_other.z) - (z * p_other.y);
		tmp.y = (z * p_other.x) - (x * p_other.z);
		tmp.z = (x * p_other.y) - (y * p_other.x);

		return tmp;
	}

	template<typename T>
	template<typename U>
	constexpr Vector3<T> Vector3<T>::Cross(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB)
	{
		Vector3<T> tmp;
		tmp.x = (p_vectorA.y * p_vectorB.z) - (p_vectorA.z * p_vectorB.y);
		tmp.y = (p_vectorA.z * p_vectorB.x) - (p_vectorA.x * p_vectorB.z);
		tmp.z = (p_vectorA.x * p_vectorB.y) - (p_vectorA.y * p_vectorB.x);

		return tmp;
	}

	template<typename T>
	template<typename U>
	constexpr Vector3<T> Vector3<T>::Lerp(Vector3<T>& p_vectorA, Vector3<U>& p_vectorB, const T p_factor)
	{
        if (p_factor < 0)
            return p_vectorA;

		Vector3<T> lerped_vector;
		lerped_vector = p_vectorA + ((p_vectorB - p_vectorA) * p_factor);
		return lerped_vector;
	}

    template<typename T>
    template<typename U>
    constexpr Vector3<T> Vector3<T>::Slerp(Vector3<T>& p_vectorA, Vector3<U>& p_vectorB, const T p_factor)
    {
        if (p_factor < 0)
            return p_vectorA;

       /* Vector3<T> tmpVec;
        float angle = p_vectorA.Angle(p_vectorB) * p_factor;
        tmpVec = p_vectorB - p_vectorA * p_vectorA.Dot(p_vectorB);
        tmpVec.Normalize();*/

        float dot = p_vectorA.Angle(p_vectorB);
        float theta = acos(dot) * p_factor;
        Vector3<T> relativeVec = p_vectorB - p_vectorA * dot;
        relativeVec.Normalize();

        return { ((p_vectorA * cos(theta)) + (relativeVec * sin(theta))) };
        //return { (p_vectorA * cos(angle)) + (tmpVec * sin(angle)) };
    }

	template<typename T>
	template<typename U>
	constexpr T Vector3<T>::Distance(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB)
	{
		return sqrt(pow((p_vectorA.x - p_vectorB.x), 2) + pow((p_vectorA.y - p_vectorB.y), 2) + pow((p_vectorA.z - p_vectorB.z), 2));
	}

	template<typename T>
	template<typename U>
	constexpr bool Vector3<T>::Equals(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB)
	{
		if (p_vectorA.x == p_vectorB.x && p_vectorA.y == p_vectorB.y && p_vectorA.z == p_vectorB.z)
			return true;
		else
			return false;
	}

	template<typename T>
	template<typename U>
	constexpr T Vector3<T>::Dot(const Vector3<U>& p_other) const
	{
        Vector3<T> tmp = p_other.Normalized();
        Vector3<T> tmp2 = Normalized();
		return (tmp2.x * tmp.x) + (tmp2.y * tmp.y) + (tmp2.z * tmp.z);
	}

	template<typename T>
	template<typename U>
	constexpr T Vector3<T>::Angle(const Vector3<U>& p_other) const
	{
		T dot = (x * p_other.x) + (y * p_other.y) + (z * p_other.z);
		T mag = Magnitude() * p_other.Magnitude();

		return acos(dot / mag);
	}

	template<typename T>
	constexpr T Vector3<T>::Magnitude() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	template<typename T>
	constexpr Vector3<T> Vector3<T>::Normalized() const
	{
		return { x / Magnitude(), y / Magnitude(), z / Magnitude() };
	}

#pragma endregion
#pragma region Operator Overloading
	template<typename T>
    template<typename U>
	constexpr Vector3<T> Vector3<T>::operator+(const Vector3<U>& p_other) const
	{
		return Vector3<T>(x + p_other.x, y + p_other.y, z + p_other.z);
	}

	template<typename T>
    template<typename U>
	constexpr Vector3<T> Vector3<T>::operator-(const Vector3<U>& p_other) const
	{
		return Vector3<T>(x - p_other.x, y - p_other.y, z - p_other.z);
	}

	template<typename T>
	constexpr Vector3<T> Vector3<T>::operator*(const T& p_scalar) const
	{
		return Vector3<T>(x * p_scalar, y * p_scalar, z * p_scalar);
	}

	template<typename T>
    template<typename U>
	constexpr Vector3<T> Vector3<T>::operator*(const Vector3<U>& p_other) const
	{
		return Vector3<T>(x * p_other.x, y * p_other.y, z * p_other.z);
	}

	template<typename T>
    template<typename U>
	constexpr Vector3<T> Vector3<T>::operator/(const Vector3<U>& p_other) const
	{
		if (p_other.x == 0 || p_other.y == 0 || p_other.z == 0 || x == 0 || y == 0 || z == 0)
		{
			std::cout << "Can't divide by zero!\n";
			return Vector3<T>(0, 0, 0);
		}
		return Vector3<T>(x / p_other.x, y / p_other.y, z / p_other.z);
	}

	template <typename T>
    template <typename U>
	constexpr Vector3<T>& Vector3<T>::operator=(const Vector3<U>& p_other) 
	{
		x = p_other.x;
		y = p_other.y;
		z = p_other.z;

		return *this;
	}

	template<typename T>
    template<typename U>
	constexpr inline Vector3<T>& Vector3<T>::operator+=(const Vector3<U> p_other)
	{
		x += p_other.x;
		y += p_other.y;
		z += p_other.z;

		return *this;
	}

	template<typename T>
    template<typename U>
	constexpr inline Vector3<T>& Vector3<T>::operator-=(const Vector3<U> p_other)
	{
		x -= p_other.x;
		y -= p_other.y;
		z -= p_other.z;

		return *this;
	}

	template<typename T>
    template<typename U>
	constexpr inline Vector3<T>& Vector3<T>::operator*=(const Vector3<U> p_other)
	{
		x *= p_other.x;
		y *= p_other.y;
		z *= p_other.z;

		return *this;
	}

	template <typename T>
	constexpr Vector3<T>& Vector3<T>::operator*=(const T p_scalar)
	{
		x *= p_scalar;
		y *= p_scalar;
		z *= p_scalar;

		return { *this };
	}

	template<typename T>
    template<typename U>
	constexpr inline Vector3<T>& Vector3<T>::operator/=(const Vector3<U> p_other)
	{
		x /= p_other.x;
		y /= p_other.y;
		z /= p_other.z;

		return *this;
	}

	template<typename T>
    template<typename U>
	constexpr inline bool Vector3<T>::operator==(const Vector3<U>& p_other) const
	{
		if (x == p_other.x && y == p_other.y && z == p_other.z)
			return true;
		else
			return false;
	}

	template<typename T>
    template<typename U>
	constexpr inline bool Vector3<T>::operator!=(const Vector3<U>& p_other) const 
	{
		if (x == p_other.x && y == p_other.y && z == p_other.z)
			return false;
		else
			return true;
	}
#pragma endregion
#pragma region Utils
	template<typename T>
	constexpr inline std::string Vector3<T>::ToString()
	{

		return std::string(std::to_string(x) + "/" + std::to_string(y) + "/" + std::to_string(z) + "\n");
	}

    template <typename T>
    constexpr std::ostream& operator<<(std::ostream& p_stream, const Vector3<T>& p_vector)
    {
        p_stream << "x : " << p_vector.x << " y : " << p_vector.y <<
            " z : " << p_vector.z;
        return  { p_stream };
    }
#pragma endregion
}