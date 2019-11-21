#pragma once
#include <GPM/Vector/Vector3.h>
#include <cmath>

#include "GPM/Tools/Utils.h"

namespace GPM
{
    template<typename T>
    inline Vector3<T>::Vector3(const T px, const T py, const T pz) : x{ px }, y{ py }, z{ pz }{}

	template<typename T>
	void Vector3<T>::Add(const Vector3<T>& p_vector)
	{
		x += p_vector.x;
		y += p_vector.y;
		z += p_vector.z;
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
		Set(x / magnitude(), y / magnitude(), z / magnitude());
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
    inline Vector3<T> Vector3<T>::Lerp(Vector3<T>& p_vectorA, Vector3<T>& p_vectorB, const T factor)
    {
        Vector3<T> lerped_vector;
        lerped_vector = p_vectorA + ((p_vectorB - p_vectorA) * factor);
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
    Vector3<T>& Vector3<T>::operator+(const Vector3<T>& p_vector)
    {
        x += p_vector.x;
        y += p_vector.y; 
        z += p_vector.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& p_vector)
    {
        return Vector3<T>(x - p_vector.x, y - p_vector.y, z - p_vector.z);
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator*(const T& p_scalar)
    {
        x *= p_scalar;
        y *= p_scalar;
        z *= p_scalar;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator*(const Vector3<T>& p_vector)
    {
        x *= p_vector.x;
        y *= p_vector.y;
        z *= p_vector.z;

        return *this;
    }

    template<typename T>
    inline Vector3<T>& Vector3<T>::operator/(const Vector3<T>& p_vector)
    {
        x /= p_vector.x;
        y /= p_vector.y;
        z /= p_vector.z;

        return *this;
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator=(const Vector3<T>& p_vector)
    {
        x = p_vector.x;
        y = p_vector.y;
        z = p_vector.z;

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
		T magnitude = magnitude() * p_vector.magnitude();

		return acos(dot / magnitude);
	}

	template<typename T>
	inline T Vector3<T>::magnitude()
	{
        return sqrt((x * x) + (y * y) + (z * z));
	}

	template<typename T>
	Vector3<T> Vector3<T>::normalized()
	{
		return { x / magnitude(), y / magnitude(), z / magnitude() };
	}
}