#pragma once
// Make your .inl here in include folder.

namespace GPM
{
    template<typename type>
    struct Matrix4
    {
        static_assert(std::is_arithmetic<type>::value, "Matrix4 should only be used with arithmetic types");
    	
        //data
        type m_data[16];

        //statics
        constexpr static Matrix4<type> GetZero() noexcept;
        constexpr static Matrix4<type> GetIdentity() noexcept;

        //methods
        constexpr void ToString() noexcept;
        constexpr void SetColumn(int p_column, Vector4<type>& p_vector) noexcept;
        constexpr void SetRow(int p_row, Vector4<type>& p_vector) noexcept;

        type Determinant();
        type GetMinor();

        Matrix4<type> Inverse();

        Matrix4<type> Scale(Vector3<type>& p_scale);
        Matrix4<type> Rotation(Vector3<type>& p_rotation);
        Matrix4<type> Translate(Vector3<type>& p_translate);

#pragma region Operators
        //operators
        Matrix4<type> operator+(Matrix4<type>& p_matrix);
        void operator+=(Matrix4<type>& p_matrix);

        Matrix4<type> operator-(Matrix4<type>& p_matrix);
        void operator-=(Matrix4<type>& p_matrix);

        Matrix4<type> operator*(Matrix4<type>& p_matrix);
        void operator*=(Matrix4<type>& p_matrix);
        Matrix4<type> operator*(Vector4<type>& p_vector);
        void operator*=(Vector4<type>& p_vector);

        bool operator==(Matrix4<type>& p_matrix);
        bool operator!=(Matrix4<type>& p_matrix);

        type operator[](int p_position);
#pragma endregion

    };

    using Matrix4F = Matrix4<float>;
    using Matrix4I = Matrix4<int>;
}

#include "GPM/Matrix/Matrix4.inl"