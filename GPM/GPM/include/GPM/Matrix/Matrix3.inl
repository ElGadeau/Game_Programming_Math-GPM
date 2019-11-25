#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace GPM;

template<typename T>
Matrix3<T> Matrix3<T>::identity = { 1,0,0,
                                    0,1,0,
                                    0,0,1 };
template<typename T>
Matrix3<T> Matrix3<T>::zero = { 0,0,0,
                                0,0,0,
                                0,0,0 };

template <typename T>
std::string Matrix3<T>::ToString()
{
    std::stringstream stringStream;
    stringStream << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "]\n"
                 << '|' << m_data[3] << "  " << m_data[4] << "  " << m_data[5] << "|\n"
                 << '[' << m_data[6] << "  " << m_data[7] << "  " << m_data[8] << "]\n";
    return { stringStream.str() };
}

#pragma region Constructors & Assignment
template<typename T>
constexpr Matrix3<T>::Matrix3()
{
    memcpy(m_data, identity.m_data, 9 * sizeof(T));
}

template<typename T>
constexpr Matrix3<T>::Matrix3(const T p_i0, const T p_i1, const T p_i2,
                              const T p_i3, const T p_i4, const T p_i5, 
                              const T p_i6, const T p_i7, const T p_i8)
                              : m_data{ p_i0, p_i1, p_i2, p_i3, p_i4, p_i5, p_i6, p_i7, p_i8} {}

template<typename T>
constexpr Matrix3<T>::Matrix3(const T p_data[9])
{
    memcpy(m_data, p_data, 9 * sizeof(T));
}

template<typename T>
constexpr Matrix3<T>::Matrix3(const Matrix3& p_other)
{
    memcpy(m_data, p_other.m_data, 9 * sizeof(T));
}

template<typename T>
constexpr Matrix3<T>::Matrix3(Matrix3&& p_other) noexcept
{
    memcpy(m_data, p_other.m_data, 9 * sizeof(T));
}
#pragma endregion

#pragma region Arithmetic Operations
template<typename T>
template<typename U>
Matrix3<T>& Matrix3<T>::Add(const Matrix3<U>& p_other)
{
    for (unsigned int i = 0; i < 9; ++i)
        m_data[i] += p_other.m_data[i];

    return { *this };
}

template<typename T>
template<typename U>
constexpr Matrix3<T> Matrix3<T>::Add(const Matrix3<T>& p_left, const Matrix3<U>& p_right)
{
    return Matrix3<T>(p_left).Add(p_right);
}

template<typename T>
template<typename U>
constexpr Matrix3<T> Matrix3<T>::operator+(const Matrix3<U>& p_other) const
{
    return Add(this, p_other);
}

template<typename T>
template<typename U>
Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<U>& p_other)
{
    return Add(p_other);
}

template<typename T>
template<typename U>
Matrix3<T>& Matrix3<T>::Subtract(const Matrix3<U>& p_other)
{
    for (unsigned int i = 0; i < 9; ++i)
        m_data[i] -= p_other.m_data[i];

    return { *this };
}

template<typename T> 
template<typename U>
constexpr Matrix3<T> Matrix3<T>::Subtract(const Matrix3<T>& p_left, const Matrix3<U>& p_right)
{
    return Matrix3<T>(p_left).Subtract(p_right);
}

template<typename T> 
template<typename U>
constexpr Matrix3<T> Matrix3<T>::operator-(const Matrix3<U>& p_other) const
{
    return Subtract(this, p_other);
}



template<typename T>
template<typename U>
Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<U>& p_other)
{
    return Subtract(p_other);
}
template<typename T> 
template<typename U>
Matrix3<T>& Matrix3<T>::Multiply(U p_scalar)
{
    for (unsigned int i = 0; i < 9; ++i)
        m_data[i] *= p_scalar;

    return { *this };
}

template<typename T>
template<typename U>
Matrix3<T>& Matrix3<T>::Multiply(const Matrix3<U>& p_other)
{
    Matrix3<T> tmpMat(this->m_data);

    for (unsigned int i = 0; i < 9; i += 3)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            m_data[i + j] = (tmpMat.m_data[i] * p_other.m_data[j])
                          + (tmpMat.m_data[i + 1] * p_other.m_data[j + 3])
                          + (tmpMat.m_data[i + 2] * p_other.m_data[j + 6]);
        }
    }
    return { *this };
}

template<typename T> 
template<typename U> 
constexpr Matrix3<T> Matrix3<T>::Multiply(const Matrix3<T>& p_left, U p_scalar)
{
    return Matrix3<T>(p_left).Multiply(p_scalar);
}

template<typename T> 
template<typename U> 
constexpr Matrix3<T> Matrix3<T>::operator*(U p_scalar) const
{
    return Multiply(this, p_scalar);
}


template<typename T> 
template<typename U> 
Matrix3<T>& Matrix3<T>::operator*=(U p_scalar)
{
    return Multiply(p_scalar);
}

template<typename T> 
template<typename U> 
constexpr Matrix3<T> Matrix3<T>::operator*(const Matrix3<U>& p_other) const
{
    return Multiply(p_other);
}


template<typename T> 
template<typename U> 
Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<U>& p_other)
{
    return Multiply(p_other);
}

#pragma endregion 

#pragma region Outside Operators
template<typename T, typename U>
constexpr Matrix3<U> GPM::operator*(T p_scalar, const Matrix3<U>& p_matrix3)
{
    for (unsigned int i = 0; i < 9; ++i)
        p_matrix3.m_data[i] *= p_scalar;
    return p_matrix3;
}

template<typename T, typename U>
constexpr Matrix3<U>& GPM::operator*=(T p_scalar, Matrix3<U>& p_matrix3)
{
    for (unsigned int i = 0; i < 9; ++i)
        p_matrix3.m_data[i] *= p_scalar;
    return p_matrix3;
}
#pragma endregion