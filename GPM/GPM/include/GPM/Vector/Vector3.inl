#pragma once
#include <GPM/Vector/Vector3.h>
#include <cmath>

#include "GPM/Tools/Utils.h"

namespace GPM
{
	template<typename T>
	void Vector3<T>::Add(Vector3<T>& p_vec)
	{
		x += p_vec.x;
		y += p_vec.y;
		z += p_vec.z;
	}

	template<typename T>
	void Vector3<T>::Substract(Vector3<T>& p_vec)
	{
		x -= p_vec.x;
		y -= p_vec.y;
		z -= p_vec.z;
	}

	template<typename T>
	void Vector3<T>::Multiply(Vector3<T>& p_vec)
	{
		x *= p_vec.x;
		y *= p_vec.y;
		z *= p_vec.z;
	}

	template<typename T>
	void Vector3<T>::Divide(Vector3<T>& p_vec)
	{
		x /= p_vec.x;
		y /= p_vec.y;
		z /= p_vec.z;
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
		Set(x / GetMagnitude(), y / GetMagnitude(), z / GetMagnitude());
	}

	template<typename T>
	Vector3<T> Vector3<T>::Forward()
	{
		Vector3<T> tmp;
		tmp.x = 0;
		tmp.y = 0;
		tmp.z = 1;

		return tmp;
	}

	template<typename T>
	Vector3<T> Vector3<T>::Right()
	{
		Vector3<T> tmp;
		tmp.x = 1;
		tmp.y = 0;
		tmp.z = 0;

		return tmp;
	}

	template<typename T>
	Vector3<T> Vector3<T>::Up()
	{
		Vector3<T> tmp;
		tmp.x = 0;
		tmp.y = 1;
		tmp.z = 0;

		return tmp;
	}

	template<typename T>
	Vector3<T> Vector3<T>::Zero()
	{
		Vector3<T> tmp;
		tmp.x = 0;
		tmp.y = 0;
		tmp.z = 0;

		return tmp;
	}

	template<typename T>
	Vector3<T> Vector3<T>::One()
	{
		Vector3<T> tmp;
		tmp.x = 1;
		tmp.y = 1;
		tmp.z = 1;

		return tmp;
	}

	template<typename T>
	T Vector3<T>::Distance(Vector3<T>& vec1, Vector3<T>& vec2)
	{
		return sqrt(pow((vec1.x - vec2.x), 2) + pow((vec1.y - vec2.y), 2) + pow((vec1.z - vec2.z), 2));
	}

	template<typename T>
	T Vector3<T>::Dot(Vector3<T>& p_vec)
	{
		T dot = (x * p_vec.x) + (y * p_vec.y) + (z * p_vec.z);

		return dot;
	}

	template<typename T>
	inline T Vector3<T>::Angle(Vector3<T>& p_vec)
	{
		T dot = (x * p_vec.x) + (y * p_vec.y) + (z * p_vec.z);
		T magnitude = GetMagnitude() * p_vec.GetMagnitude();

		return acos(dot / magnitude);
	}

	template<typename T>
	T Vector3<T>::GetMagnitude()
	{
		T magnitude = sqrt((x * x) + (y * y) + (z * z));

		return magnitude;
	}

	template<typename T>
	Vector3<T> Vector3<T>::GetNormalized()
	{
		Vector3<T> tmp;
		tmp.Set(x / GetMagnitude(), y / GetMagnitude(), z / GetMagnitude());

		return tmp;
	}
}