#pragma once
#include <utility>
#include <sstream>
#include <math.h>
#include <string>

namespace GPM
{
	template<typename T>
	struct Vector2
	{
        static_assert(std::is_arithmetic<T>::value, "Vector2 should only be used with arithmetic types");
		
		T x;
		T y;

		constexpr Vector2();
		constexpr Vector2(const T p_x, const T p_y);
		~Vector2() = default;
		constexpr Vector2(const Vector2& p_other);

		constexpr void Set(T p_x, T p_y);
		
		static const Vector2<T> zero;
		static const Vector2<T> up ;
		static const Vector2<T> right;

		constexpr std::string ToString() const;
		
#pragma region Member Operator Overloads
		
		constexpr bool operator==(Vector2<T> const& p_other);
		constexpr bool operator!=(Vector2<T> const& p_other);
		constexpr Vector2<T>& operator=(const Vector2<T>& p_other);
		
#pragma endregion

#pragma region Vector Operations
#pragma region Non-Static
		
		constexpr void Normalize();
		constexpr GPM::Vector2<T> normalized() const;
		constexpr T Magnitude() const;
		constexpr T Dot(const Vector2<T>& p_other) const;
		constexpr T Distance(const Vector2<T>& p_other) const;
		constexpr Vector2<T> Perpendicular() const;
		constexpr void Scale(T p_scalar);
		
#pragma endregion
#pragma region Static
		
		static constexpr Vector2<T> normalized(const Vector2<T>& p_vector2);
		static constexpr void Normalize(Vector2<T>& p_vector2);
		static constexpr T Dot(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right);
		static constexpr T Angle(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right);
		static constexpr T Distance(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right);
		static constexpr Vector2<T> Lerp(const Vector2<T>& p_vector2Start, const Vector2<T>& p_vector2End, const float p_alpha);
		static constexpr Vector2<T> Perpendicular(const Vector2<T>& p_vector2);
		
#pragma endregion
		
#pragma endregion
		
#pragma region Arithmetic Operations
		
#pragma region Non-Static
		constexpr void Add(const GPM::Vector2<T>& p_otherVector2);
		constexpr void Subtract(const GPM::Vector2<T>& p_otherVector2);
		constexpr void Divide(const T& p_scalar);
		constexpr void Multiply(const T& p_scalar);
		constexpr bool Equals(const GPM::Vector2<T>& p_otherVector2) const;
		
#pragma endregion

#pragma region Static
		static constexpr GPM::Vector2<T> Add(const GPM::Vector2<T>& p_vector2Left, const GPM::Vector2<T>& p_vector2Right);
		static constexpr GPM::Vector2<T> Add(const GPM::Vector2<T>& p_vector2, const T& p_scalar);
		static constexpr GPM::Vector2<T> Subtract(const GPM::Vector2<T>& p_vector2Left, const GPM::Vector2<T>& p_vector2Right);
		static constexpr GPM::Vector2<T> Subtract(const GPM::Vector2<T>& p_vector2, const T& p_scalar);
		static constexpr GPM::Vector2<T> Multiply(const GPM::Vector2<T>& p_vector2, const T& p_scalar);
		static constexpr GPM::Vector2<T> Divide(const GPM::Vector2<T>& p_vector2, const T& p_scalar);

#pragma endregion
#pragma endregion
	};
	
#pragma region Non-member Operator Overloads
	template<typename T, typename U>
	constexpr Vector2<T> operator+(Vector2<T> const& p_vector2Left, Vector2<U> const& p_vector2Right);

	template<typename T, typename U>
	constexpr Vector2<T> operator-(Vector2<T> const& p_vector2Left, Vector2<U> const& p_vector2Right);

	template<typename T, typename U>
	constexpr Vector2<U> operator*(const T & p_scalar, const Vector2<U>& p_vector2);

	template<typename T, typename U>
	constexpr Vector2<T> operator*(const Vector2<T>& p_vector2, const U& p_scalar);

	/**
		 * Multiplies parameters of the 2 Vector2s individually (x * x, y * y)
		 * @param p_vector2Left
		 * @param p_vector2Right
		 */
	template<typename T, typename U>
	constexpr Vector2<T> operator*(const Vector2<T>& p_vector2Left, const Vector2<U>& p_vector2Right);

	template<typename T, typename U>
	constexpr Vector2<T> operator/(Vector2<T> const& p_vector2, const U& p_scalar);

	template <typename T, typename U>
	constexpr void operator+=(Vector2<T>& p_vector2Left, const Vector2<U>& p_vector2Right);
	
	template <typename T, typename U>
	constexpr void operator-=(Vector2<T>& p_vector2Left, const Vector2<U>& p_vector2Right);

	template <typename T, typename U>
	constexpr void operator*=(Vector2<T>& p_vector2Left, const U& p_scalar);

	template <typename T, typename U>
	constexpr void operator/=(Vector2<T>& p_vector2Left, const U& p_scalar);

#pragma endregion
	
using Vector2U = GPM::Vector2<unsigned int>;
using Vector2I = GPM::Vector2<int>;
using Vector2F = GPM::Vector2<float>;
using Vector2D = GPM::Vector2<double>;
using Vector2L = GPM::Vector2<long>;
}


#include <GPM/Vector/Vector2.inl>