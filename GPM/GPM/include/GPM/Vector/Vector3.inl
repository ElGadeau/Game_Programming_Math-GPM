#pragma once
#include <GPM/Vector/Vector3.h>
#include <cmath>
#include <iostream>

#include "GPM/Tools/Utils.h"

namespace GPM
{
    template <typename T>
    constexpr Vector3<T>::Vector3(const Vector3<T>& p_other)
    {
        *this = p_other;
    }

    template <typename T>
    constexpr Vector3<T>::Vector3(Vector3<T>&& p_other) noexcept
    {
        *this = p_other;
    }

	template<typename T>
    Vector3<T> Vector3<T>::Add(const Vector3<T>& p_vector)
	{
		x += p_vector.x;
		y += p_vector.y;
		z += p_vector.z;

        return  { Vector3<T>(x + p_vector.x, y + p_vector.y, z + p_vector.z) };
	}

    template<typename T>
    constexpr Vector3<T> Vector3<T>::Add(const Vector3<T>& p_left, const Vector3<T>& p_right)
    {
        return { Vector3<T>(p_left).Add(p_right) };
    }

	template<typename T>
	void Vector3<T>::Substract(const Vector3<T>& p_vector)
	{
		x -= p_vector.x;
		y -= p_vector.y;
		z -= p_vector.z;
	}

	template<typename T>
	void Vector3<T>::Multiply(const Vector3<T>& p_vector)
	{
		x *= p_vector.x;
		y *= p_vector.y;
		z *= p_vector.z;
	}

	template<typename T>
	void Vector3<T>::Divide(const Vector3<T>& p_vector)
	{
		x /= p_vector.x;
		y /= p_vector.y;
		z /= p_vector.z;
	}

	template<typename T>
	void Vector3<T>::Set(T px, T py, T pz)
	{
		x = px;
		y = py;
		z = pz;
	}

	template<typename T>
	void Vector3<T>::Normalize()
	{
		Set(x / Magnitude(), y / Magnitude(), z / Magnitude());
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

    template<typename T>
    inline Vector3<T> Vector3<T>::Cross(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB)
    {
        Vector3<T> tmp;
        tmp.x = (p_vectorA.y * p_vectorB.z) - (p_vectorA.z * p_vectorB.y);
        tmp.y = (p_vectorA.z * p_vectorB.x) - (p_vectorA.x * p_vectorB.z);
        tmp.z = (p_vectorA.x * p_vectorB.y) - (p_vectorA.y * p_vectorB.x);

        return tmp;
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::Lerp(Vector3<T>& p_vectorA, Vector3<T>& p_vectorB, const T p_factor)
    {
        Vector3<T> lerped_vector;
        //lerped_vector = p_vectorA + ((p_vectorB - p_vectorA) * factor);
        lerped_vector = p_vectorA + p_vectorB;
        return lerped_vector;
    }

    template<typename T>
	T Vector3<T>::Distance(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB)
	{
		return sqrt(pow((p_vectorA.x - p_vectorB.x), 2) + pow((p_vectorA.y - p_vectorB.y), 2) + pow((p_vectorA.z - p_vectorB.z), 2));
	}

    template<typename T>
    inline bool Vector3<T>::Equals(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB)
    {
        if (p_vectorA.x == p_vectorB.x && p_vectorA.y == p_vectorB.y && p_vectorA.z == p_vectorB.z)
            return true;
        else
            return false;
    }

    template<typename T>
    constexpr Vector3<T> Vector3<T>::operator+(const Vector3<T>& p_other)
    {
        return Vector3<T>(x + p_other.x, y + p_other.y, z + p_other.z);
    }

    template<typename T>
    constexpr Vector3<T> Vector3<T>::operator-(const Vector3<T>& p_vector)
    {
        return Vector3<T>(x - p_vector.x, y - p_vector.y, z - p_vector.z);
    }

    template<typename T>
    constexpr Vector3<T> Vector3<T>::operator*(const T& p_scalar)
    {
        return Vector3<T>(x * p_scalar, y * p_scalar, z * p_scalar);
    }

    template<typename T>
    constexpr Vector3<T> Vector3<T>::operator*(const Vector3<T>& p_vector)
    {
        return Vector3<T>(x * p_vector.x, y * p_vector.y, z * p_vector.z);
    }

    template<typename T>
    constexpr Vector3<T> Vector3<T>::operator/(const Vector3<T>& p_vector)
    {
        if (p_vector.x == 0 || p_vector.y == 0 || p_vector.z == 0 || x == 0 || y == 0 || z == 0)
        {
            std::cout << "Can't divide by zero!\n";
            return Vector3<T>(0, 0, 0);
        }
        return Vector3<T>(x / p_vector.x, y / p_vector.y, z / p_vector.z);
    }

    template <typename T>
    constexpr Vector3<T>& Vector3<T>::operator=(const Vector3<T>& p_other)
    {
        x = p_other.x;
        y = p_other.y;
        z = p_other.z;

        return *this;
    }

    template<typename T>
    inline bool operator ==(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB)
    {
        return false;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T> p_vector)
    {
        x += p_vector.x;
        y += p_vector.y;
        z += p_vector.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T> p_vector)
    {
        x -= p_vector.x;
        y -= p_vector.y;
        z -= p_vector.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator*=(const Vector3<T> p_vector)
    {
        x *= p_vector.x;
        y *= p_vector.y;
        z *= p_vector.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator/=(const Vector3<T> p_vector)
    {
        x /= p_vector.x;
        y /= p_vector.y;
        z /= p_vector.z;

        return *this;
    }

    template<typename T>
    inline bool Vector3<T>::operator==(const Vector3<T>& p_vector)
    {
        if (x == p_vector.x && y == p_vector.y && z == p_vector.z)
            return true;
        else
            return false;
    }

    template<typename T>
    inline bool Vector3<T>::operator!=(const Vector3<T>& p_vector)
    {
        if (x == p_vector.x && y == p_vector.y && z == p_vector.z)
            return false;
        else
            return true;
    }

	template<typename T>
	inline T Vector3<T>::Dot(const Vector3<T>& p_vector)
	{
		return (x * p_vector.x) + (y * p_vector.y) + (z * p_vector.z);
	}

	template<typename T>
	inline T Vector3<T>::Angle(const Vector3<T>& p_vector)
	{
		T dot = (x * p_vector.x) + (y * p_vector.y) + (z * p_vector.z);
		T magnitude = magnitude() * p_vector.Magnitude();

		return acos(dot / magnitude);
	}

	template<typename T>
	inline T Vector3<T>::Magnitude()
	{
        return sqrt((x * x) + (y * y) + (z * z));
	}

	template<typename T>
	Vector3<T> Vector3<T>::Normalized()
	{
		return { x / Magnitude(), y / Magnitude(), z / Magnitude() };
	}
    template<typename T>
    inline std::string Vector3<T>::ToString()
    {
        
        return std::string(std::to_string(x) + "/" + std::to_string(y) + "/" + std::to_string(z) + "\n");
    }
}