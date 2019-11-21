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

        constexpr Vector3<T> Add(const Vector3<T>& p_vector);
        constexpr Vector3<T> Add(const Vector3<T>& p_left, const Vector3<T>& p_right);
        constexpr void Substract(const Vector3<T>& p_vector);
        constexpr void Multiply(const Vector3<T>& p_vector);
        constexpr void Divide(const Vector3<T>& p_vector);
        constexpr void Set(T p_x, T p_y, T p_z);
        constexpr void Scale(T p_factor);
        constexpr void Normalize();
        constexpr Vector3<T> Normalized();
        constexpr std::string ToString();

        constexpr T Dot(const Vector3<T>& p_vector);
        constexpr T Angle(const Vector3<T>& p_vector);

        constexpr T Magnitude();

        static Vector3<T> forward;
        static Vector3<T> right;
        static Vector3<T> up;
        static Vector3<T> zero;
        static Vector3<T> one;

        constexpr static Vector3<T> Cross(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        constexpr static Vector3<T> Lerp(Vector3<T>& p_vectorA, Vector3<T>& p_vectorB, const T p_factor);
        constexpr static T Distance(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        constexpr static bool Equals(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);

        constexpr inline Vector3<T>& operator +=(const Vector3<T> p_vector);
        constexpr inline Vector3<T>& operator -=(const Vector3<T> p_vector);
        constexpr inline Vector3<T>& operator *=(const Vector3<T> p_vector);
        constexpr inline Vector3<T>& operator /=(const Vector3<T> p_vector);

        constexpr inline Vector3<T> operator+(const Vector3<T>& p_other);
        constexpr inline Vector3<T> operator -(const Vector3<T>& p_vector);
        constexpr inline Vector3<T>& operator=(const Vector3<T>& p_other);
        constexpr inline Vector3<T> operator /(const Vector3<T>& p_vector);
        constexpr inline Vector3<T> operator *(const Vector3<T>& p_vector);
        constexpr inline Vector3<T> operator *(const T& p_scalar);

        constexpr inline bool operator==(const Vector3<T>& p_vector);
        constexpr inline bool operator!=(const Vector3<T>& p_vector);
	};

    using Vector3F = GPM::Vector3<float>;
    using Vector3L = GPM::Vector3<long>;
    using Vector3U = GPM::Vector3<unsigned int>;
    using Vector3I = GPM::Vector3<int>;
    using Vector3D = GPM::Vector3<double>;
}

#include <GPM/Vector/Vector3.inl>
