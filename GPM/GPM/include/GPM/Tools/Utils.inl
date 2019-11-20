#pragma once

#include <cmath>
#include <type_traits>

namespace GPM::Tools
{
	inline float Utils::ToRadians(const float p_angle)
	{
		return p_angle * 3.1415926535f / 180.0f;
	}

	inline float Utils::ToDegrees(const float p_angle)
	{
		return p_angle * 180.0f / 3.1415926535f;
	}
	
	template<typename T>
	inline T Utils::Pow(const T p_value, const int p_exp)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to pow must be arithmetic");
		return static_cast<T>(std::pow(p_value, p_exp));
	}

	template<typename T>
	inline T Utils::Pow(const T p_value, const float p_exp)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to pow must be arithmetic");
		return static_cast<T>(std::pow(p_value, p_exp));
	}

	template <typename T>
	inline T Utils::SquareRoot(const T p_value)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to root must be arithmetic");
		return static_cast<T>(std::sqrt(p_value));
	}

	template <typename T>
	T Utils::SquareRootF(const T p_value)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to root must be arithmetic");
		return static_cast<T>(std::sqrtf(p_value));
	}

	template<typename T>
	inline T Utils::Root(const T p_value, const float p_nRoot)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to root must be arithmetic");
		return static_cast<T>(std::pow(p_value, 1 / p_nRoot));
	}

	template<typename T>
	inline T Utils::Abs(const T p_value)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to Abs must be arithmetic");
		return static_cast<T>(std::abs(p_value));
	}
}