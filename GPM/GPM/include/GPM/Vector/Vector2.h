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
		T X;
		T Y;

		static const Vector2<T> Zero;
		static const Vector2<T> Up ;
		static const Vector2<T> Right;

		
		bool operator==(Vector2<T> const& p_1);
		bool operator!=(Vector2<T> const& p_1);

		//non-static methods
		void Normalize();
		T Magnitude() const;
		T Dot(Vector2<T>& p_other);
		T Distance(Vector2<T>& p_other);
		std::string ToString() const;

		//Static methods
		static Vector2<T> Normalized(const Vector2<T>& p_1);
		static T Dot(Vector2<T>& p_1, Vector2<T>& p_2);
		static T Angle(Vector2<T>& p_1, Vector2<T>& p_2);
		static T Distance(Vector2<T>& p_1, Vector2<T>& p_2);

	};

	
	template<typename T, typename U>
	Vector2<T> operator+(Vector2<T> const& p_1, Vector2<U> const& p_2);

	template<typename T, typename U>
	Vector2<T> operator-(Vector2<T> const& p_1, Vector2<U> const& p_2);

	template<typename T, typename U>
	Vector2<U> operator*(T const& p_1, Vector2<U> const& p_2);

	template<typename T, typename U>
	Vector2<T> operator*(Vector2<T> const& p_1, U const& p_2);

	template<typename T, typename U>
	Vector2<T> operator/(Vector2<T> const& p_1, U const& p_2);

	template <typename T, typename U>
	void operator+=(Vector2<T>& p_1, Vector2<U> const& p_2);
	
	template <typename T, typename U>
	void operator-=(Vector2<T>& p_1, Vector2<U> const& p_2);

	template <typename T, typename U>
	void operator*=(Vector2<T>& p_1, const U& p_2);

	template <typename T, typename U>
	void operator/=(Vector2<T>& p_1, const U& p_2);
}

using Vector2I = GPM::Vector2<int>;
using Vector2F = GPM::Vector2<float>;
using Vector2D = GPM::Vector2<double>;

#include <GPM/Vector/Vector2.inl>