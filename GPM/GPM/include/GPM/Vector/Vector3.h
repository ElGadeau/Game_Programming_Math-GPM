#pragma once
// Make your .inl here in include folder.

namespace GPM
{
    struct Quaternion;

	template<typename T>
	struct Vector3
	{
        static_assert(std::is_arithmetic<T>::value, "Vector3 should only be used with arithmetic types");
		
        /**
         * @brief Construct the Vector with an X, Y and Z value
         * @param p_x : X value
         * @param p_y : Y value
         * @param p_z : Z value
         */
        constexpr Vector3(const T p_x, const T p_y, const T p_z) : x{ p_x }, y{ p_y }, z{ p_z }{}
        /**
         * @brief Construct the Vector with a copy of an Other
         * @param p_other : Other vector you want to copy the data from
         */
        template<typename U>
        constexpr Vector3(const Vector3<U>& p_other);
        /**
         * @brief Construct the Vector with a move Constructor
         * @param p_other : Other vector you want to get the data from
         */
        template<typename U>
        constexpr Vector3(Vector3<U>&& p_other) noexcept;

        /**
        * @brief Default constructor of the Vector
        */
        Vector3() = default;
		T x;
		T y;
		T z;

        /**
         * @brief Add other vector to the current vector
         * @param p_vector : The other vector you want to add to the current one
         * @return The current vector modified
         */
        template<typename U>
        constexpr Vector3<T> Add(const Vector3<U>& p_vector);

        /**
         * @brief Add left vector to the right vector
         * @param p_left : The first vector you want to add
         * @param p_right : The second vector to be added to the first one
         * @return The copy of the vector operation result
         */
        template<typename U>
        constexpr Vector3<T> Add(const Vector3<T>& p_left, const Vector3<U>& p_right);
        /**
         * @brief Substract other vector to the current vector
         * @param p_vector : The other vector you want to substract to the current one
         * @return The current vector modified
         */
        template<typename U>
        constexpr void Substract(const Vector3<U>& p_vector);
        /**
         * @brief Multiply other vector to the current vector
         * @param p_vector : The other vector you want to Multiply to the current one
         * @return The current vector modified
         */
        template<typename U>
        constexpr void Multiply(const Vector3<U>& p_vector);
        /**
         * @brief Divide other vector to the current vector
         * @param p_vector : The other vector you want to Divide to the current one
         * @return The current vector modified
         */
        template<typename U>
        constexpr void Divide(const Vector3<U>& p_vector);
        /**
         * @brief Set current vector
         * @param p_x : The x value
         * @param p_y : The y value
         * @param p_z : The z value
         * @return The current vector modified
         */
        constexpr void Set(T p_x, T p_y, T p_z);
        /**
         * @brief Scale current vector by factor
         * @param p_factor : The factor you want to scale the vector to
         * @return The current vector modified
         */
        constexpr void Scale(T p_factor);
        /**
         * @brief Normalize current vector
         * @return The current vector modified
         */
        constexpr void Normalize();
        /**
         * @brief Normalized 
         * @return the copy of Normalized vector
         */
        constexpr Vector3<T> Normalized() const;
        /**
         * @brief ToString
         * @return string format of the vector
         */
        constexpr std::string ToString();

        /**
         * @brief DotProduct other vector to the current vector
         * @param p_vector : The other vector you want calculate the Dot with
         * @return The dot result
         */
        template<typename U>
        constexpr T Dot(const Vector3<U>& p_vector) const;

        /**
         * @brief Calculate the Angle between other vector and the current vector
         * @param p_vector : The other vector you want calculate the Angle with
         * @return The angle result
         */
        template<typename U>
        constexpr T Angle(const Vector3<U>& p_vector) const;

        /**
         * @brief Calculate the Magnitude of the current vector
         * @return The Magnitude
         */
        constexpr T Magnitude() const;

        /**
         * @brief forward unit vector
         * @return copy of unit vector forward
         */
        static Vector3<T> forward;
        /**
         * @brief right unit vector
         * @return copy of unit vector right
         */
        static Vector3<T> right;
        /**
         * @brief up unit vector
         * @return copy of unit vector up
         */
        static Vector3<T> up;
        /**
         * @brief zero unit vector
         * @return copy of unit vector zero
         */
        static Vector3<T> zero;
        /**
         * @brief one unit vector
         * @return copy of unit vector one
         */
        static Vector3<T> one;

        /**
         * @brief Cross other vector to the current vector
         * @param p_vector : The other vector you want to calculate the Cross with
         * @return The copy of Cross result
         */
        template<typename U>
		constexpr inline Vector3<T> Cross(const Vector3<U>& p_other) const;
        /**
         * @brief Cross VectorA to the VectorB
         * @param p_vectorA : first vector you want to calculate cross with
         * @param p_vectorB : The other vector you want to calculate the Cross with
         * @return The copy of Cross result
         */
        template<typename U>
        constexpr static Vector3<T> Cross(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB);
        /**
         * @brief Lerp VectorA to the VectorB with a factor
         * @param p_vectorA : first vector you want to calculate Lerp with
         * @param p_vectorB : The other vector you want to calculate the Lerp with
         * @param p_factor : factor of Lerping used
         * @return The copy of Lerp result
         */
        template<typename U>
        constexpr static Vector3<T> Lerp(Vector3<T>& p_vectorA, Vector3<U>& p_vectorB, const T p_factor);
        /**
         * @brief Slerp VectorA to the VectorB with a factor
         * @param p_vectorA : first vector you want to calculate Slerp with
         * @param p_vectorB : The other vector you want to calculate the Slerp with
         * @param p_factor : factor of Lerping used
         * @return The copy of Lerp result
         */
        template<typename U>
        constexpr static Vector3<T> Slerp(Vector3<T>& p_vectorA, Vector3<U>& p_vectorB, const T p_factor);
        /**
         * @brief Calculate Distance between VectorA and the VectorB
         * @param p_vectorA : first vector you want to calculate the Distance with
         * @param p_vectorB : The other vector you want to calculate the Distance with
         * @return the Distance result
         */
        template<typename U>
        constexpr static T Distance(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB);
        /**
         * @brief Check if VectorA is equal to the VectorB
         * @param p_vectorA : first vector you want to calculate the equality with
         * @param p_vectorB : The other vector you want to calculate the equality with
         * @return if the vector is equal or not to the other
         */
        template<typename U>
        constexpr static bool Equals(const Vector3<T>& p_vectorA, const Vector3<U>& p_vectorB);

        template<typename U>
        constexpr inline Vector3<T>& operator +=(const Vector3<U> p_vector);
        template<typename U>
        constexpr inline Vector3<T>& operator -=(const Vector3<U> p_vector);
        template<typename U>
        constexpr inline Vector3<T>& operator *=(const Vector3<U> p_vector);
		constexpr inline Vector3<T>& operator *=(const T p_scalar);
        template<typename U>
        constexpr inline Vector3<T>& operator /=(const Vector3<U> p_vector);

        template<typename U>
        constexpr inline Vector3<T> operator+(const Vector3<U>& p_other) const;
        template<typename U>
        constexpr inline Vector3<T> operator-(const Vector3<U>& p_vector) const;
        template<typename U>
        constexpr inline Vector3<T>& operator=(const Vector3<U>& p_other);
        template<typename U>
        constexpr inline Vector3<T> operator/(const Vector3<U>& p_vector) const;
        template<typename U>
        constexpr inline Vector3<T> operator *(const Vector3<U>& p_vector) const;
        constexpr inline Vector3<T> operator *(const T& p_scalar) const;

        template<typename U>
        constexpr inline bool operator==(const Vector3<U>& p_vector) const;
        template<typename U>
        constexpr inline bool operator!=(const Vector3<U>& p_vector) const;

	};

    template <typename T>
    constexpr std::ostream& operator<<(std::ostream & p_stream, const Vector3<T> & p_vector);

    using Vector3F = GPM::Vector3<float>;
    using Vector3L = GPM::Vector3<long>;
    using Vector3U = GPM::Vector3<unsigned int>;
    using Vector3I = GPM::Vector3<int>;
    using Vector3D = GPM::Vector3<double>;
}

#include <GPM/Vector/Vector3.inl>
