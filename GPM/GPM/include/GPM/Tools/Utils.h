#pragma once

namespace GPM::Tools
{
	/**
	 * Utils class provides some simple mathematics tools, such as operations, pow, root, trigonometry stuffs...
	 */
	class Utils final
	{
	public:
		Utils() = delete;

		/**
		 * Convert the given angle to radians
		 * @param p_angle (In degrees)
		 */
		static float ToRadians(const float p_angle);

		/**
		 * Convert the given angle to degrees
		 * @param p_angle (In radians)
		 */
		static float ToDegrees(const float p_angle);

		/**
		 * Linearly interpolates between two values
		 * @param p_a
		 * @param p_b
		 * @param p_alpha
		 */
		static float Lerp(const float p_a, const float p_b, const float p_alpha);

		/**
		 * Return the pow of a numeric value with an integer exponent
		 * @param p_value
		 * @param p_exp
		 */
		template<typename T>
		static T Pow(const T p_value, const int p_exp);

		/**
		* Return the pow of a numeric value with a float exponent
		* @param p_value
		* @param p_exp
		*/
		template<typename T>
		static T Pow(const T p_value, const float p_exp);

		/**
		* Return the square root of a numeric value
		* @param p_value
		*/
		template<typename T>
		static T SquareRoot(const T p_value);

		/**
		* Return the square root of a numeric value with float precision
		* @param p_value
		*/
		template<typename T>
		static T SquareRootF(const T p_value);

		/**
		 * Return the root of a numeric value
		 * @param p_value
		 * @param p_nRoot
		 */
		template<typename T>
		static T Root(const T p_value, const float p_nRoot);

		/**
		 * Return the greatest common divider of the two given integers
		 * @param p_a
		 * @param p_b
		 */
		static int GreatestCommonDivider(const int p_a, const int p_b);

		/**
		 * Return the smallest common divider of the two given integers
		 * @param p_a
		 * @param p_b
		 */
		static int LeastCommonMultiple(const int p_a, const int p_b);

		/**
		 * Return the decimal part of a float as an integer
		 * @param p_value
		 */
		static float GetDecimalPart(const float p_value);

		/**
		 * Return the absolute value of a numeric value
		 * @param p_value
		 */
		template<typename T>
		static T Abs(const T p_value);

		/**
		 * Mathematics sinus implementation
		 * @param p_value
		 */
		static float Sin(const float p_value);

		/**
		* Mathematics sinus implementation with float precision
		* @param p_value
		*/
		static float SinF(const float p_value);

		/**
		 * Mathematics co-sinus implementation
		 * @param p_value
		 */
		static float Cos(const float p_value);

		/**
		* Mathematics co-sinus implementation with float precision
		* @param p_value
		*/
		static float CosF(const float p_value);

		/**
		 * Mathematics tangent implementation
		 * @param p_value
		 */
		static float Tan(const float p_value);

		/**
		 * Mathematics arc co-sinus implementation
		 * @param p_value
		 */
		static float Arccos(const float p_value);

		/**
		 * Mathematics arc sinus implementation
		 * @param p_value
		 */
		static float Arcsin(const float p_value);

		/**
		 * Mathematics arc tangent implementation
		 * @param p_value
		 */
		static float Arctan(const float p_value);

		/**
		* Mathematics arc tangent implementation
		* @param p_valueYx
		* @param p_valueXx
		*/
		static float Arctan2(const float p_valueYx, const float p_valueXx);
	};
}

#include "Utils.inl"