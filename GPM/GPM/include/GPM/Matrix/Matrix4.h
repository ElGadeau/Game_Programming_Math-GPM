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

        //constuctor
        Matrix4<T>();
        Matrix4<T>(const Matrix4<T>& p_matrix);
        Matrix4<T>(const Vector3<T>& p_vector);
        Matrix4<T>(const T* p_data);
        Matrix4<T>(const T p_00, const T p_01, const T p_02, const T p_03,
            const T p_10, const T p_11, const T p_12, const T p_13,
            const T p_20, const T p_21, const T p_22, const T p_23,
            const T p_30, const T p_31, const T p_32, const T p_33);

        //static
        static Matrix4<T> identity;
        static Matrix4<T> zero;

        static Matrix4<T> ScaleMatrix4(const Vector3<T>& p_scale);
        static Matrix4<T> RotationMatrix4(const Vector3<T>& p_rotation);
        static Matrix4<T> TranslateMatrix4(const Vector3<T>& p_translate);

        static Matrix4<T> Transpose(const Matrix4<T>& p_transpose);

        //methods
        constexpr void ToString() noexcept;
        constexpr void SetColumn(int p_column, const Vector4<T>& p_vector);
        constexpr void SetRow(int p_row, const Vector4<T>& p_vector);

        T Determinant();
        T GetMinor(Matrix3<T> p_minor);

        Matrix4<T> Inverse();

        void Scale(const Vector3<T>& p_scale);
        void Rotation(const Vector3<T>& p_rotation);
        void Translate(const Vector3<T>& p_translate);

#pragma region Arithmetic Operations

        static Matrix4<T> Add(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other);
        static Matrix4<T> Subtract(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other);
        static Matrix4<T> Multiply(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other);
        static Vector4<T> Multiply(const Matrix4<T>& p_matrix, const Vector4<T>& p_vector);
        static bool Equals(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other);
        static void Set(Matrix4<T>& p_matrix, const Matrix4<T>& p_other);

#pragma endregion 

#pragma region Operators

        //operators
        Matrix4<T> operator+(const Matrix4<T>& p_matrix);
        void operator+=(const Matrix4<T>& p_matrix);

        Matrix4<T> operator-(const Matrix4<T>& p_matrix);
        void operator-=(const Matrix4<T>& p_matrix);

        Matrix4<T> operator*(const Matrix4<T>& p_matrix);
        void operator*=(const Matrix4<T>& p_matrix);
        Vector4<T> operator*(const Vector4<T>& p_vector);

        bool operator==(const Matrix4<T>& p_matrix);
        bool operator!=(const Matrix4<T>& p_matrix);

        void operator=(const Matrix4<T>& p_matrix);

        T operator[](int p_position);

#pragma endregion

    };

    using Matrix4F = Matrix4<float>;
    using Matrix4L = Matrix4<long>;
    using Matrix4U = Matrix4<unsigned int>;
    using Matrix4I = Matrix4<int>;
    using Matrix4D = Matrix4<double>;
}

#include <GPM/Matrix/Matrix4.inl>