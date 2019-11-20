#pragma once
// Make your .inl here in include folder.

namespace GPM
{
    template<typename type>
    struct Matrix4
    {
        //data
        type m_data[16];

        //statics
        static Matrix4<type> GetZero();
        static Matrix4<type> GetIdentity();

        //methods
        void ToString();

        type Determinant();
        type GetMinor();

        Matrix4<type> Inverse();
        Matrix4<type> Scale(Vector3<type> p_scale);
        Matrix4<type> Rotation(Vector3<type> p_rotation);
        Matrix4<type> Translate(Vector3<type> p_translate);

        Matrix4<type>* operator(Vector4<type> p_vector);
    };

    using Matrix4F = Matrix4<float>;
    using Matrix4I = Matrix4<int>;
}

#include "GPM/Matrix/Matrix4.inl"