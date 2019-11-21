#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>

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
constexpr Matrix3<T>::Matrix3(const Matrix3&& p_other) noexcept
{
    memcpy(m_data, p_other.m_data, 9 * sizeof(T));
}

template<typename T>
template<typename U>
void Matrix3<T>::Add(const Matrix3<U>& p_other)
{
    if (std::is_unsigned<T>::value && !std::is_unsigned<U>::value)
        std::cerr << "Can't Add to an Unsigned Matrix a right value that isn't of the same type\n"
                  << "Values will look completely wrong.\n";
    
        for (unsigned int i = 0; i < 9; ++i)
            m_data[i] += p_other.m_data[i];
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::Add(const Matrix3<T>& p_left, const Matrix3<T>& p_right)
{
    Matrix3<T> result;

    for (unsigned int i = 0; i < 9; ++i)
        result.m_data[i] = (p_left.m_data[i] + p_right.m_data[i]);

    return result;
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::operator+(const Matrix3<T>& p_other) const
{
    return Add(this, p_other);
}

template<typename T> 
Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& p_other)
{
    return Add(p_other);
}

template<typename T>
Matrix3<T>& Matrix3<T>::Subtract(const Matrix3<T>& p_other)
{
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::Subtract(const Matrix3<T>& p_left, const Matrix3<T>& p_right)
{
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::operator-(const Matrix3<T>& p_other) const
{
}

template<typename T> Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& p_other)
{
}

template<typename T> 
Matrix3<T>& Matrix3<T>::Multiply(const T p_scalar)
{
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::Multiply(const Matrix3<T>& p_left, T p_scalar)
{
}

template<typename T> 
constexpr Matrix3<T> Matrix3<T>::operator*(const T p_scalar) const
{
}

template<typename T> 
Matrix3<T>& Matrix3<T>::operator*=(const T p_scalar)
{
}

#pragma endregion 