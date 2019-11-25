#pragma once

#include <string>

namespace GPM
{
    /**
     * A standard 3 by 3 Matrix. Default value is an identity matrix.
     */
    template <typename T>
    struct Matrix3
    {
        static_assert(std::is_arithmetic<T>::value, "Matrix3 should only be used with arithmetic types");
        
        constexpr Matrix3();
        ~Matrix3() = default;


        constexpr Matrix3(const T i0, const T i1, const T i2, const T i3, const T i4, const T i5, 
            const T i6, const T i7, const T i8);

        constexpr Matrix3(const T p_data[9]);
        constexpr Matrix3(const Matrix3& p_other);
        constexpr Matrix3(Matrix3&& p_other) noexcept;


        T m_data[9] = { 1,0,0,
                        0,1,0,
                        0,0,1 };

        /**
         * @brief function used to debug values from the matrix
         */
        std::string ToString();

#pragma region Static Properties
        /**
         * @brief This is a const matrix that has 1 in the diagonal and 0 elsewhere
         */
        static Matrix3<T> identity;

        /** 
         *  @brief This is a const matrix that has 0 everywhere
         */
        static Matrix3<T> zero;
#pragma endregion 

#pragma region Properties
         
#pragma endregion

#pragma region Arithmetic Operations

#pragma region Add

        /**
         * Add other matrix to the current matrix
         * @param p_other
         */
        template<typename U>
        Matrix3<T>& Add(const Matrix3<U>& p_other);

        /**
         * Add left matrix to the right matrix
         * @param p_left
         * @param p_right
         */
        template<typename U>
        constexpr static Matrix3<T> Add(const Matrix3<T>& p_left, const Matrix3<U>& p_right);

        /**
         * Return the summation of other matrix and current matrix
         * @param p_other
         */
        template<typename U>
        constexpr Matrix3<T> operator+(const Matrix3<U>& p_other) const;

        /**
         * Add other matrix to the current matrix
         * @param p_other
         */
        template<typename U>
        Matrix3<T>& operator+=(const Matrix3<U>& p_other);

#pragma endregion
#pragma region Subtract

        /**
         * Subtract other vector to the current matrix
         * @param p_other
         */
        template<typename U>
        Matrix3<T>& Subtract(const Matrix3<U>& p_other);

        /**
         * Subtract left matrix to the right matrix
         * @param p_left
         * @param p_right
         */
        template<typename U>
        constexpr static Matrix3<T> Subtract(const Matrix3<T>& p_left, const Matrix3<U>& p_right);

        /**
         * Return the subtraction of other matrix and current matrix
         * @param p_other
         */
        template<typename U>
        constexpr Matrix3<T> operator-(const Matrix3<U>& p_other) const;

        /**
         * Subtract other matrix to the current matrix
         * @param p_other
         */
        template<typename U>
        Matrix3<T>& operator -=(const Matrix3<U>& p_other);

#pragma endregion
#pragma region Multiply

        /**
         * Multiply scalar to x, y and z
         * @param p_scalar
         */
        template<typename U>
        Matrix3<T>& Multiply(U p_scalar);

        /**
         * Multiply scalar to matrix left
         * @param p_left
         * @param p_scalar
         */
        template<typename U>
        constexpr static Matrix3<T> Multiply(const Matrix3<T>& p_left, U p_scalar);

        /**
         * Return the multiplication of scalar and current matrix
         * @param p_scalar
         */
        template<typename U>
        constexpr Matrix3<T> operator*(U p_scalar) const;

        /**
         * Multiply scalar to the current matrix
         * @param p_scalar
         */
        template<typename U>
        Matrix3<T>& operator*=(U p_scalar);

#pragma endregion

#pragma endregion
    };

    
#pragma region Outside Operators

    template <typename T>
    constexpr std::ostream& operator<<(std::ostream& p_stream, const Matrix3<T>& p_matrix3);

    template <typename T>
    constexpr Matrix3<T> operator+(const T p_scalar, const Matrix3<T>& p_matrix3);

    template <typename T>
    constexpr Matrix3<T>& operator+=(const T p_scalar, Matrix3<T>& p_matrix3);

    template <typename T>
    constexpr Matrix3<T> operator-(const T p_scalar, const Matrix3<T>& p_matrix3);

    template <typename T>
    constexpr Matrix3<T>& operator-=(const T p_scalar, Matrix3<T>& p_matrix3);

    template <typename T>
    template <typename U>
    constexpr Matrix3<T> operator*(const U p_scalar, const Matrix3<T>& p_matrix3);

    template <typename T>
    template <typename U>
    constexpr Matrix3<T>& operator*=(const U p_scalar, Matrix3<T>& p_matrix3);

#pragma endregion

    using Matrix3F = Matrix3<float>;
    using Matrix3L = Matrix3<long>;
    using Matrix3I = Matrix3<int>;
    using Matrix3D = Matrix3<double>;


}

#include <GPM/Matrix/Matrix3.inl>