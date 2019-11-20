#pragma once

namespace GPM
{
#pragma region Constructors & Assignment

	template <typename T>
	constexpr Vector4<T>::Vector4()
		: x(0), y(0), z(0), w(1) {}

	template <typename T>
	constexpr Vector4<T>::Vector4(T p_x, T p_y, T p_z, T p_w)
		: x(p_x), y(p_y), z(p_z), w(p_w) {}

	template <typename T>
	constexpr Vector4<T>::Vector4(const Vector4<T>& p_other)
	{
		*this = p_other;
	}

	template <typename T>
	constexpr Vector4<T>::Vector4(Vector4<T>&& p_other) noexcept
	{
		*this = p_other;
	}

	template <typename T>
	constexpr Vector4<T>& Vector4<T>::operator=(const Vector4<T>& p_other)
	{
		x = p_other.x;
		y = p_other.y;
		z = p_other.z;
		w = p_other.w;

		return *this;
	}

	template <typename T>
	constexpr Vector4<T>& Vector4<T>::operator=(Vector4<T>&& p_other) noexcept
	{
		x = p_other.x;
		y = p_other.y;
		z = p_other.z;
		w = p_other.w;

		return *this;
	}

#pragma endregion
}