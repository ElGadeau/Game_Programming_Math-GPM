#pragma once
// Make your .inl here in include folder.

namespace GPM
{

	template<typename T>
	struct Vector3
	{
        static_assert(std::is_arithmetic<T>::value, "Vector3 should only be used with arithmetic types");
		
        constexpr Vector3(const T p_x, const T p_y, const T p_z) : x{ p_x }, y{ p_y }, z{ p_z }{}
        constexpr Vector3(const Vector3<T>& p_other);
        constexpr Vector3(Vector3<T>&& p_other) noexcept;

        Vector3() = default;
		T x;
		T y;
		T z;

		Vector3<T> Add(const Vector3<T>& p_vector);
        constexpr Vector3<T> Add(const Vector3<T>& p_left, const Vector3<T>& p_right);
		void Substract(const Vector3<T>& p_vector);
		void Multiply(const Vector3<T>& p_vector);
		void Divide(const Vector3<T>& p_vector);
		void Set(T p_x, T p_y, T p_z);

		void Normalize();
		Vector3<T> Normalized();
        std::string ToString();

		T Dot(const Vector3<T>& p_vector);
		T Angle(const Vector3<T>& p_vector);

		T Magnitude();

		static Vector3<T> forward;
		static Vector3<T> right;
		static Vector3<T> up;
		static Vector3<T> zero;
		static Vector3<T> one;

        static Vector3<T> Cross(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        static Vector3<T> Lerp(Vector3<T>& p_vectorA, Vector3<T>& p_vectorB, const T p_factor);
		static T Distance(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        static bool Equals(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);


        /*T& operator *(Vector3<T>& p_scalar);*/

        Vector3<T>& operator +=(const Vector3<T> p_vector);
        Vector3<T>& operator -=(const Vector3<T> p_vector);
        Vector3<T>& operator *=(const Vector3<T> p_vector);
        Vector3<T>& operator /=(const Vector3<T> p_vector);

        constexpr Vector3<T> operator+(const Vector3<T>& p_other);
        constexpr Vector3<T> operator -(const Vector3<T>& p_vector);
        constexpr Vector3<T>& operator=(const Vector3<T>& p_other);
        constexpr Vector3<T> operator /(const Vector3<T>& p_vector);
        constexpr Vector3<T> operator *(const Vector3<T>& p_vector);
        constexpr Vector3<T> operator *(const T& p_scalar);
        bool operator==(const Vector3<T>& p_vector);
        bool operator!=(const Vector3<T>& p_vector);
	};

}

#include <GPM/Vector/Vector3.inl>
