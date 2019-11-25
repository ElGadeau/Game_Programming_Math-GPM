#pragma once

#include <cmath>
#include <type_traits>

namespace GPM::Tools
{
	inline float Utils::ToRadians(const float p_angle)
	{
		return p_angle * (static_cast<float>(M_PI) / 180.0f);
	}

	inline float Utils::ToDegrees(const float p_angle)
	{
		return p_angle * (180.0f / static_cast<float>(M_PI));
	}

	inline float Utils::Sin(const float p_value)
	{
		return std::sin(p_value);
	}

	inline float Utils::SinF(const float p_value)
	{
		return std::sinf(p_value);
	}

	inline float Utils::Cos(const float p_value)
	{
		return std::cos(p_value);
	}

	inline float Utils::CosF(const float p_value)
	{
		return std::cosf(p_value);
	}

	inline float Utils::Tan(const float p_value)
	{
		return std::tan(p_value);
	}

	inline float Utils::TanF(const float p_value)
	{
		return std::tanf(p_value);
	}

	inline float Utils::Arccos(const float p_value)
	{
		return std::acos(p_value);
	}

	inline float Utils::ArccosF(const float p_value)
	{
		return std::acosf(p_value);
	}

	inline float Utils::Arcsin(const float p_value)
	{
		return std::asin(p_value);
	}

	inline float Utils::ArcsinF(const float p_value)
	{
		return std::asinf(p_value);
	}

	inline float Utils::Arctan(const float p_value)
	{
		return std::atan(p_value);
	}
	
	inline float Utils::ArctanF(const float p_value)
	{
		return std::atanf(p_value);
	}

	inline float Utils::Arctan2(const float p_valueYx, const float p_valueXx)
	{
		return std::atan2(p_valueYx, p_valueXx);
	}

	inline float Utils::Arctan2F(const float p_valueYx, const float p_valueXx)
	{
		return std::atan2f(p_valueYx, p_valueXx);
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
		return static_cast<T>(sqrt(p_value));
	}

	template <typename T>
	inline T Utils::SquareRootF(const T p_value)
	{
		static_assert(std::is_arithmetic<T>::value, "The value to root must be arithmetic");
		return static_cast<T>(sqrtf(p_value));
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