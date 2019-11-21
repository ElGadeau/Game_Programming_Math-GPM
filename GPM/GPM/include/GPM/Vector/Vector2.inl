#pragma once

#include <utility>
#include <math.h>
#include "Vector2.h"

//using namespace GPM;

template<typename T>
inline constexpr GPM::Vector2<T>::Vector2() : x{ 0 }, y{ 0 } {}

template<typename T>
inline constexpr GPM::Vector2<T>::Vector2(const T p_x, const T p_y): x{p_x}, y{p_y} {}

template<typename T>
inline constexpr GPM::Vector2<T>::Vector2(const Vector2& p_other): x{ p_other.x }, y{ p_other.y } {}

template<typename T>
inline constexpr void GPM::Vector2<T>::Set(T p_x, T p_y)
{
	x = p_x;
	y = p_y;
}

template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::zero = Vector2<T>{ 0, 0 };
template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::up = Vector2<T>{0, 1};
template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::right = Vector2<T>{ 1, 0 };

#pragma region Member Operator Overloads
template<typename T>
inline constexpr bool GPM::Vector2<T>::operator==(Vector2<T> const& p_other)
{
	if (x == p_other.x && y == p_other.y)
		return true;
	
	return false;
}

template<typename T>
inline constexpr bool GPM::Vector2<T>::operator!=(Vector2<T> const& p_other)
{
	if (x == p_other.x && y == p_other.y)
		return false;

	return true;
}

template<typename T>
inline constexpr GPM::Vector2<T>& GPM::Vector2<T>::operator=(const Vector2<T>& p_other)
{
	x = p_other.x;
	y = p_other.y;
	
	return *this;
}

#pragma endregion

#pragma region Vector Operations

#pragma region Non-Static

template<typename T>
inline constexpr void GPM::Vector2<T>::Normalize()
{
	T magn = Magnitude();
	
	if (magn == 0)
		throw std::logic_error("Vector2::Normalize() got a vector2 magnitude of 0");

	Divide(magn);
}

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::normalized() const
{
	T magn = Magnitude();
	
	if (magn == 0)
		throw std::logic_error("Vector2::Normalize() got a vector2 magnitude of 0");
	
	return { x / magn, y / magn };
}

template<typename T>
constexpr T GPM::Vector2<T>::Magnitude() const
{
	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

#pragma endregion

#pragma region Static
template<typename T>
constexpr GPM::Vector2<T> GPM::Vector2<T>::normalized(const Vector2<T>& p_vector2)
{
	T magn = p_vector2.Magnitude();
	return Vector2<T>{ p_vector2.x / magn, p_vector2.y / magn };
}

template<typename T>
inline constexpr void GPM::Vector2<T>::Normalize(Vector2<T>& p_vector2)
{
	T magn = p_vector2.Magnitude();
	p_vector2.x /= magn;
	p_vector2.y /= magn;
}

template<typename T>
inline constexpr T GPM::Vector2<T>::Dot(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right)
{
	return (p_vector2Left.x * p_vector2Right.x) + (p_vector2Left.y * p_vector2Right.y);
}

template<typename T>
inline constexpr T GPM::Vector2<T>::Angle(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right)
{
	T magn1 = p_vector2Left.Magnitude();
	T magn2 = p_vector2Right.Magnitude();

	T dot = p_vector2Left.Dot(p_vector2Right);
	return std::move(acos(dot / (magn1 * magn2)));
}

template<typename T>
inline constexpr T GPM::Vector2<T>::Distance(const Vector2<T>& p_vector2Left, const Vector2<T>& p_vector2Right)
{
	return std::move(std::sqrt(std::pow(p_vector2Left.x - p_vector2Right.x, 2) + std::pow(p_vector2Left.y - p_vector2Right.y, 2)));
}

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::Lerp(const Vector2<T>& p_vector2Start, const Vector2<T>& p_vector2End, const float p_alpha)
{
	if (p_alpha >= 0 && p_alpha <= 1)
	{
		return { p_vector2Start + (p_vector2End - p_vector2Start) * p_alpha };
	}
	
	if (p_alpha > 1)
		return p_vector2End;
	
	return { p_vector2Start };
}

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::Perpendicular(const Vector2<T>& p_vector2)
{
	return { p_vector2.y, -p_vector2.x };
}

template<typename T>
inline constexpr T GPM::Vector2<T>::Dot(const Vector2<T>& p_other) const
{
	return std::move((x * p_other.x) + (y * p_other.y));
}

template<typename T>
inline constexpr T GPM::Vector2<T>::Distance(const Vector2<T>& p_other) const
{
	T deltaX = x - p_other.x;
	T deltaY = y - p_other.y;

	return std::sqrt(std::pow(deltaX, 2) + (deltaY, 2));
}

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::Perpendicular() const
{
	return { y, -x };
}

template<typename T>
inline constexpr void GPM::Vector2<T>::Scale(T p_scalar)
{
	Multiply(3);
}

#pragma endregion
#pragma endregion

#pragma region Non-Member Operator Overloads
template <typename T, typename U>
constexpr void GPM::operator-=(GPM::Vector2<T>& p_vector2Left, GPM::Vector2<U> const& p_vector2Right)
{
	p_vector2Left.x -= p_vector2Right.x;
	p_vector2Left.y -= p_vector2Right.y;
}

template<typename T, typename U>
constexpr void GPM::operator*=(Vector2<T>& p_vector2Left, const U& p_scalar)
{
	p_vector2Left.x *= p_scalar;
	p_vector2Left.y *= p_scalar;
}

template<typename T, typename U>
constexpr void GPM::operator/=(Vector2<T>& p_vector2Left, const U& p_scalar)
{
	if (p_scalar == 0)	
		throw std::logic_error("Vector2::Normalize() got a vector2 magnitude of 0");
	
	p_vector2Left.x /= p_scalar;
	p_vector2Left.y /= p_scalar;
}


template<typename T>
constexpr std::string GPM::Vector2<T>::ToString() const
{
	std::stringstream stringStream;
	stringStream << "( " << x << ", " << y << " )";
	return { stringStream.str() };
}

template<typename T, typename U>
constexpr GPM::Vector2<T> GPM::operator+(Vector2<T> const& p_vector2Left, Vector2<U> const& p_vector2Right)
{
	
	return GPM::Vector2<T>{p_vector2Left.x + p_vector2Right.x, p_vector2Left.y + p_vector2Right.y};
}

template<typename T, typename U>
constexpr void GPM::operator+=(Vector2<T>& p_vector2Left, Vector2<U> const& p_vector2Right)
{
	p_vector2Left.x += p_vector2Right.x;
	p_vector2Left.y += p_vector2Right.y;
}

template<typename T, typename U>
constexpr GPM::Vector2<T> GPM::operator-(Vector2<T> const& p_vector2Left, Vector2<U> const& p_vector2Right)
{
	return GPM::Vector2<T>::Subtract(p_vector2Left, p_vector2Right);
}

template<typename T, typename U>
constexpr GPM::Vector2<U> GPM::operator*(T const& p_scalar, Vector2<U> const& p_vector2)
{
	return Vector2<T>::Multiply(p_vector2, p_scalar);
}

template<typename T, typename U>
constexpr GPM::Vector2<T> GPM::operator*(Vector2<T> const& p_vector2, U const& p_scalar)
{
	return GPM::Vector2<T>::Multiply(p_vector2, p_scalar);
}

template<typename T, typename U>
constexpr GPM::Vector2<T> GPM::operator*(const Vector2<T>& p_vector2Left, const Vector2<U>& p_vector2Right)
{
	return {p_vector2Left.x * p_vector2Right.x, p_vector2Left.y * p_vector2Right.y };
}

template<typename T, typename U>
constexpr GPM::Vector2<T> GPM::operator/(Vector2<T> const& p_vector2, const U& p_scalar)
{
	if (p_scalar == 0)
		throw std::logic_error("Vector2::operator/ attempted division by zero");
	
	return GPM::Vector2<T>::Divide(p_vector2, p_scalar);
}

#pragma region Arithmetic Operations
#pragma region Non-Static

template<typename T>
inline constexpr void GPM::Vector2<T>::Add(const GPM::Vector2<T>& p_otherVector2)
{
	x += p_otherVector2.x;
	y += p_otherVector2.y;
}
template<typename T>
inline constexpr void GPM::Vector2<T>::Subtract(const GPM::Vector2<T>& p_otherVector2)
{
	*this -= p_otherVector2;
}
template<typename T>
inline constexpr void GPM::Vector2<T>::Divide(const T& p_scalar)
{
	x /= p_scalar;
	y /= p_scalar;
}
template<typename T>
inline constexpr void GPM::Vector2<T>::Multiply(const T& p_scalar)
{
	x *= p_scalar;
	y *= p_scalar;
}
template<typename T>
inline constexpr bool GPM::Vector2<T>::Equals(const GPM::Vector2<T>& p_otherVector2) const
{
	if (GPM::Vector2<T>{ x, y } == p_otherVector2)
		return true;

	return false;
}
template<typename T>
constexpr GPM::Vector2<T> GPM::Vector2<T>::Add(const GPM::Vector2<T>& p_vector2Left, const GPM::Vector2<T>& p_vector2Right)
{
	return GPM::Vector2<T>{p_vector2Right.x + p_vector2Left.x, p_vector2Right.y + p_vector2Left.y};
}

#pragma endregion
#pragma region Static

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::Add(const GPM::Vector2<T>& p_vector2, const T& p_scalar)
{
	return GPM::Vector2<T>{ p_vector2.x + p_scalar, p_vector2.y + p_scalar };
}

template<typename T>
constexpr GPM::Vector2<T> GPM::Vector2<T>::Subtract(const GPM::Vector2<T>& p_vector2Left, const GPM::Vector2<T>& p_vector2Right)
{
	return GPM::Vector2<T>{p_vector2Right.x - p_vector2Left.x, p_vector2Right.y - p_vector2Left.y};
}

template<typename T>
inline constexpr GPM::Vector2<T> GPM::Vector2<T>::Subtract(const GPM::Vector2<T>& p_vector2, const T& p_scalar)
{
	return GPM::Vector2<T>{ p_vector2.x - p_scalar, p_vector2.y - p_scalar };
}

template<typename T>
constexpr GPM::Vector2<T> GPM::Vector2<T>::Multiply(const GPM::Vector2<T>& p_vector2, const T& p_scalar)
{
	return Vector2<T>({ p_vector2.x * p_scalar, p_vector2.y * p_scalar });
}

template<typename T>
constexpr GPM::Vector2<T> GPM::Vector2<T>::Divide(const GPM::Vector2<T>& p_vector2, const T& p_scalar)
{
	return Vector2<T>({ p_vector2.x / p_scalar, p_vector2.y / p_scalar });
}

#pragma endregion 

#pragma endregion