#pragma once
// Make your .inl here in include folder.

namespace GPM
{

	template<typename T>
	struct Vector3
	{
        static_assert(std::is_arithmetic<T>::value, "Vector3 should only be used with arithmetic types");
		
        Vector3(const T px, const T py, const T pz);
        Vector3() = default;
		T x;
		T y;
		T z;

		void Add(const Vector3<T>& p_vector);
		void Substract(const Vector3<T>& p_vector);
		void Multiply(const Vector3<T>& p_vector);
		void Divide(const Vector3<T>& p_vector);
		void Set(T px, T py, T pz);

		void Normalize();
		Vector3<T> normalized();

		T Dot(const Vector3<T>& p_vector);
		T Angle(const Vector3<T>& p_vector);

		T magnitude();

		static Vector3<T> forward;
		static Vector3<T> right;
		static Vector3<T> up;
		static Vector3<T> zero;
		static Vector3<T> one;

        static Vector3<T> Cross(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        static Vector3<T> Lerp(Vector3<T>& p_vectorA, Vector3<T>& p_vectorB, const T factor);
		static T Distance(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);
        static bool Equals(const Vector3<T>& p_vectorA, const Vector3<T>& p_vectorB);

        Vector3<T>& operator +(const Vector3<T>& p_vector);
        Vector3<T>& operator *(const Vector3<T>& p_vector);
        Vector3<T>& operator /(const Vector3<T>& p_vector);
        Vector3<T>& operator =(const Vector3<T>& p_vector);

        Vector3<T>& operator *(const T& p_scalar);
        /*T& operator *(Vector3<T>& p_scalar);*/

        Vector3<T>& operator +=(const Vector3<T> p_vector);
        Vector3<T>& operator -=(const Vector3<T> p_vector);
        Vector3<T>& operator *=(const Vector3<T> p_vector);
        Vector3<T>& operator /=(const Vector3<T> p_vector);

        Vector3<T> operator -(const Vector3<T>& p_vector);
        bool operator==(const Vector3<T>& p_vector);
        bool operator!=(const Vector3<T>& p_vector);
	};

}

#include <GPM/Vector/Vector3.inl>
