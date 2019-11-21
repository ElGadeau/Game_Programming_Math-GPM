#pragma once
#include <string>
#include <GPM/Vector/Vector3.h>
#include <GPM/Matrix/Matrix3.h>
#include <GPM/Matrix/Matrix4.h>

namespace GPM
{
	struct Quaternion final
	{
		Vector3<float> axis;
		//m_w is the real value of quaternion, this will be used to check if the quaternion is pure/identity or not.
		float w;

		static Quaternion Identity();

#pragma region Constructors & Assignment
		inline Quaternion();
		/**
		 * @param p_x Vector part of Quaternion
		 * @param p_y Vector part of Quaternion
		 * @param p_z Vector part of Quaternion
		 * @param p_w Real value of Quaternion
		 *
		 * In pure/applied Maths, we write W (or real), (Xi + Yj + Zk) (or Vector)
		 */
		inline Quaternion(const float p_x, const float p_y, const float p_z, const float p_w);
		/**
		 * Copy Constructor
		 * @param p_other
		 */
		inline Quaternion(const Quaternion& p_other);

		/**
		 * Move Constructor
		 * @param p_other
		 */
		inline Quaternion(Quaternion&& p_other) noexcept;
		
		/**
		 * Construct from rotation matrix
		 * @param p_matrix Rotation matrix
		 */
		inline Quaternion(const Matrix3<float>& p_matrix);
		/**
		 * Construct from rotation matrix
		 * @param p_matrix Rotation matrix
		 */
		inline Quaternion(const Matrix4<float>& p_matrix);

		/**
		 * Constuct a quaternion from axis and angle in radian
		 * @param p_axis
		 * @param p_angleInRadians
		 */
		inline Quaternion(const Vector3<float>& p_axis, const float p_angleInRadians);

		~Quaternion() = default;
		
		/**
		 * Construct from euler angles
		 */
		inline void MakeFromEuler(const Vector3<float>& p_euler);
#pragma endregion

#pragma region Tests & Comparisons

		/**
		 * Check If the quaternion is Identity
		 * if the quaternion has no rotation(meaning x,y,z axis values = 0), it's Identity
		 */
		bool IsIdentity() const;

		/*
		 * Check if the quaternion is pure
		 * if the quaternion has no real value(meaning real part = 0), it's pure
		 */
		bool IsPure() const;
		bool IsNormalized() const;
		bool operator==(const Quaternion& p_otherQuaternion) const;
		bool operator!=(const Quaternion& p_otherQuaternion) const;

#pragma endregion
#pragma region Arithmetic Operations

#pragma region Add
		Quaternion operator+(const Quaternion& p_otherQuaternion) const;
		Quaternion& operator+=(const Quaternion& p_otherQuaternion);

#pragma endregion
#pragma region Substract
		Quaternion operator-(const Quaternion& p_otherQuaternion) const;
		Quaternion& operator-=(const Quaternion& p_otherQuaternion);

#pragma endregion
#pragma region Multiply
		float DotProduct(const Quaternion& p_otherQuaternion) const;
		static float DotProduct(const Quaternion& p_left, const Quaternion& p_right);
		float operator|(const Quaternion& p_otherQuaternion) const;

		Quaternion& operator*=(const float p_scale);
		Quaternion operator*(const float p_scale) const;

		Quaternion operator*(const Quaternion& p_otherQuaternion) const;
		Quaternion& operator*=(const Quaternion& p_otherQuaternion);

		Vector3<float> operator*(const Vector3<float>& p_toMultiply) const;
		Matrix3<float> operator*(const Matrix3<float>& p_multiply) const;

#pragma endregion
#pragma region Divide
		Quaternion& operator/=(const float p_scale);
		Quaternion operator/(const float p_scale) const;

#pragma endregion
#pragma endregion

#pragma region Quaternion Operations
		Quaternion& Normalize();
		static Quaternion Normalize(const Quaternion& p_quaternion);

		float Length() const;
		float LengthSquare() const;
		float GetAngle() const;

		Quaternion& Inverse();
		static Quaternion Inverse(const Quaternion& p_quaternion);

		Quaternion& Conjugate();
		static Quaternion Conjugate(const Quaternion& p_quaternion);

		Quaternion& Square();
		static Quaternion Square(const Quaternion& p_quaternion);

		/**
		* @param p_axis
		* @param p_angle
		*/
		void GetAxisAndAngle(Vector3<float>& p_axis, float& p_angle) const;

		Vector3<float> GetAxisZ() const;
		Vector3<float> GetAxisY() const;
		Vector3<float> GetAxisX() const;

		Vector3<float> GetForwardVector() const;
		Vector3<float> GetRightVector() const;
		Vector3<float> GetUpVector() const;
		Vector3<float> GetRotationAxis() const;

		float AngularDistance(const Quaternion& p_other) const;

		float GetXAxisValue() const;
		float GetYAxisValue() const;
		float GetZAxisValue() const;
		float GetRealValue() const;

		void SetXAxisValue(float p_xValue);
		void SetYAxisValue(float p_yValue);
		void SetZAxisValue(float p_zValue);
		void SetRealValue(float p_realValue);

		/**
		 * @param p_first
		 * @param p_second
		 * @param p_alpha
		 */
		static Quaternion Lerp(Quaternion& p_first, Quaternion& p_second, const float p_alpha);

		/**
		 * @param p_first
		 * @param p_second
		 * @param p_alpha
		 */
		static Quaternion Slerp(Quaternion& p_first, Quaternion& p_second, const float p_alpha);
		static Quaternion Nlerp(Quaternion& p_first, Quaternion& p_second, const float p_alpha);
		/**
		 * @param p_position
		 * @param p_pivot
		 */
		Vector3<float> RotateRelativeToPivot(const Vector3<float>& p_position, const Vector3<float>& p_pivot) const;
		/**
		 * @param p_position
		 * @param p_pivot
		 * @param p_eulerAngles
		 */
		static Vector3<float> RotateRelativeToPivot(const Vector3<float>& p_position, const Vector3<float>& p_pivot,
			const Vector3<float>& p_eulerAngles);
		/**
		* @param p_position
		* @param p_pivot
		* @param p_quaternion
		*/
		static Vector3<float> RotateRelativeToPivot(const Vector3<float>& p_position, const Vector3<float>& p_pivot,
			Quaternion& p_quaternion);

		/**
		 * @param p_toRotate
		 */
		Vector3<float> RotateVector(const Vector3<float>& p_toRotate) const;

#pragma endregion
#pragma region Conversions

		Vector3<float> ToEuler();
		std::string ToString() const;
		static std::string ToString(const Quaternion& p_quaternion);
		Matrix3<float> ToMatrix3();

		Matrix4<float> ToMatrix4();
#pragma endregion
	};

	std::ostream& operator<<(std::ostream& p_stream, const Quaternion& p_quaternion);
}

#include <GPM/Quaternion/Quaternion.inl>