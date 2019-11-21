#pragma once
// Make your .inl here in include folder.

namespace GPM
{
    template<typename T>
    struct Matrix4
    {
        static_assert(std::is_arithmetic<T>::value, "Matrix4 should only be used with arithmetic types");
    	
        //data
        T m_data[16] = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        //static
        static Matrix4<T> identity;
        static Matrix4<T> zero;

        //methods
        constexpr void ToString() noexcept;
        constexpr void SetColumn(int p_column, Vector4<T>& p_vector);
        constexpr void SetRow(int p_row, Vector4<T>& p_vector);

        T Determinant();
        T GetMinor();

        Matrix4<T> Inverse();

        Matrix4<T> Scale(Vector3<T>& p_scale);
        Matrix4<T> Rotation(Vector3<T>& p_rotation);
        Matrix4<T> Translate(Vector3<T>& p_translate);

#pragma region Arithmetic Operations

        static Matrix4<T> Add(Matrix4<T>& p_matrix, Matrix4<T>& p_other);
        static Matrix4<T> Subtract(Matrix4<T>& p_matrix, Matrix4<T>& p_other);
        static Matrix4<T> Multiply(Matrix4<T>& p_matrix, Matrix4<T>& p_other);
        static bool Equals(Matrix4<T>& p_matrix, Matrix4<T>& p_other);

#pragma endregion 

#pragma region Operators
        //operators
        Matrix4<T> operator+(Matrix4<T>& p_matrix);
        void operator+=(Matrix4<T>& p_matrix);

        Matrix4<T> operator-(Matrix4<T>& p_matrix);
        void operator-=(Matrix4<T>& p_matrix);

        Matrix4<T> operator*(Matrix4<T>& p_matrix);
        void operator*=(Matrix4<T>& p_matrix);
        Matrix4<T> operator*(Vector4<T>& p_vector);
        void operator*=(Vector4<T>& p_vector);

        bool operator==(Matrix4<T>& p_matrix);
        bool operator!=(Matrix4<T>& p_matrix);

        T operator[](int p_position);
#pragma endregion

    };

    using Matrix4F = Matrix4<float>;
    using Matrix4L = Matrix4<long>;
    using Matrix4U = Matrix4<unsigned int>;
    using Matrix4I = Matrix4<int>;
    using Matrix4D = Matrix4<double>;
}

#include "GPM/Matrix/Matrix4.inl"