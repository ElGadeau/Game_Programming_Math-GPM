#pragma once

#include <utility>
#include <math.h>
#include "Vector2.h"

//using namespace GPM;

template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::Zero = Vector2<T>{ 0, 0 };
template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::Up = Vector2<T>{0, 1};
template <typename T>
const GPM::Vector2<T> GPM::Vector2<T>::Right = Vector2<T>{ 1, 0 };

template<typename T>
T GPM::Vector2<T>::Magnitude() const
{
	return std::sqrt(std::pow(X, 2) + std::pow(Y, 2));
}

template<typename T>
inline bool GPM::Vector2<T>::operator==(Vector2<T> const& p_1)
{
	if (X == p_1.X && Y == p_1.Y)
		return true;
	
	return false;
}

template<typename T>
inline bool GPM::Vector2<T>::operator!=(Vector2<T> const& p_1)
{
	if (X == p_1.X && Y == p_1.Y)
		return false;

	return true;
}

template<typename T>
inline void GPM::Vector2<T>::Normalize()
{
	T magn = Magnitude();
	X /= magn;
	Y /= magn;
}

template <typename T, typename U>
void GPM::operator-=(GPM::Vector2<T>& p_1, GPM::Vector2<U> const& p_2)
{
	p_1.X -= p_2.X;
	p_1.Y -= p_2.Y;
}

template<typename T, typename U>
void GPM::operator*=(Vector2<T>& p_1, const U& p_2)
{
	p_1.X *= p_2;
	p_1.Y *= p_2;
}

template<typename T, typename U>
void GPM::operator/=(Vector2<T>& p_1, const U& p_2)
{
	p_1.X /= p_2;
	p_1.Y /= p_2;
}

template<typename T>
std::string GPM::Vector2<T>::ToString() const
{
	std::stringstream stringStream;
	stringStream << "( " << X << ", " << Y << " )";
	return { stringStream.str() };
}

template<typename T>
GPM::Vector2<T> GPM::Vector2<T>::Normalized(const Vector2<T>& p_1)
{
	T magn = p_1.Magnitude();
	
	return Vector2<T>({p_1.X / magn, p_1.Y / magn});
}

template<typename T>
inline T GPM::Vector2<T>::Dot(Vector2<T>& p_1, Vector2<T>& p_2)
{
	return std::move((p_1.X * p_2.X) + (p_1.Y * p_2.Y));
}

template<typename T>
inline T GPM::Vector2<T>::Angle(Vector2<T>& p_1, Vector2<T>& p_2)
{
	T magn1 = p_1.Magnitude();
	T magn2 = p_2.Magnitude();

	T dot = p_1.Dot(p_2);
	return std::move(acos(dot / (magn1 * magn2)));
}

template<typename T>
inline T GPM::Vector2<T>::Distance(Vector2<T>& p_1, Vector2<T>& p_2)
{
	return std::move(std::sqrt(std::pow(p_1.X - p_2.X, 2) + std::pow(p_1.Y - p_2.Y, 2)));
}

template<typename T>
inline T GPM::Vector2<T>::Dot(Vector2<T>& p_other)
{
	return std::move((X * p_other.X) + (Y * p_other.Y));
}

template<typename T>
inline T GPM::Vector2<T>::Distance(Vector2<T>& p_other)
{
	T deltaX = X - p_other.X;
	T deltaY = Y - p_other.Y;
	
	return std::sqrt(std::pow(deltaX, 2) + (deltaY, 2));
}

template<typename T, typename U>
GPM::Vector2<T> GPM::operator+(Vector2<T> const& p_1, Vector2<U> const& p_2)
{
	
	return GPM::Vector2<T>{p_1.X + static_cast<T>(p_2.X), p_1.Y + static_cast<T>(p_2.Y)};
}

template<typename T, typename U>
void GPM::operator+=(Vector2<T>& p_1, Vector2<U> const& p_2)
{
	p_1.X += p_2.X;
	p_1.Y += p_2.Y;
}

template<typename T, typename U>
GPM::Vector2<T> GPM::operator-(Vector2<T> const& p_1, Vector2<U> const& p_2)
{
	return GPM::Vector2<T>{ p_1.X - p_2.X, p_1.Y - p_2.Y };
}

template<typename T, typename U>
GPM::Vector2<U> GPM::operator*(T const& p_1, Vector2<U> const& p_2)
{
	return Vector2<T>({p_1 * p_2.X, p_1 * p_2.Y});
}

template<typename T, typename U>
GPM::Vector2<T> GPM::operator*(Vector2<T> const& p_1, U const& p_2)
{
	return Vector2<T>({p_1.X * static_cast<T>(p_2), p_1.Y * static_cast<T>(p_2)});
}

template<typename T, typename U>
GPM::Vector2<T> GPM::operator/(Vector2<T> const& p_1, U const& p_2)
{
	return Vector2<T>({ p_1.X / static_cast<T>(p_2), p_1.Y / static_cast<T>(p_2)});
}

