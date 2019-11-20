#pragma once
// Make your .inl here in include folder.

#include <type_traits>

namespace GPM
{
	template<typename T>
	struct Vector4
	{
		static_assert(std::is_arithmetic<T>::value, "Vector4 should only be used with arithmetic types");
		
		T x;
		T y;
		T z;
		T w;

		/**
 * Default Constructor
 */
		constexpr Vector4();

		/**
		 * Constructor with parameters
		 * @param p_x
		 * @param p_y
		 * @param p_z
		 * @param p_w Set to 1 for vectors, 0 for points
		 */
		constexpr Vector4(T p_x, T p_y, T p_z, T p_w = 1.0f);

		/**
		* Constructor from vector3
		* @param p_other
		*/
		//explicit constexpr Vector4(const Vector3<T>& p_other);

		/**
		* Move Constructor from vector3
		* @param p_other
		*/
		//explicit constexpr Vector4(Vector3<T>&& p_other);

		/**
		 * Copy Constructor
		 * @param p_other
		 */
		constexpr Vector4(const Vector4<T>& p_other);

		/**
		 * Move Constructor
		 * @param p_other
		 */
		constexpr Vector4(Vector4<T>&& p_other) noexcept;

		/**
		 * Overload = operator by copy
		 * @param p_other
		 */
		constexpr Vector4<T>& operator=(const Vector4<T>& p_other);

		/**
		 * Overload = operator by move
		 * @param p_other
		 */
		constexpr Vector4<T>& operator=(Vector4<T>&& p_other) noexcept;
	};
}

#include "Vector4.inl"