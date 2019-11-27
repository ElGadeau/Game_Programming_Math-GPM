#pragma once
#include <string>

namespace GPM
{
	struct Quaternion final
	{
		Vector3<float> axis;
		//m_w is the real value of quaternion, this will be used to check if the quaternion is pure/identity or not.
		float w;

		static Quaternion identity;

#pragma region Constructors & Assignment
		inline Quaternion();
		/**
		 * @brief Constructor using all values
		 * @param p_x Vector part of Quaternion
		 * @param p_y Vector part of Quaternion
		 * @param p_z Vector part of Quaternion
		 * @param p_w Real value of Quaternion
		 *
		 * @note In pure/applied Maths, we write W (or real), (Xi + Yj + Zk) (or Vector)
		 */
		inline Quaternion(const float p_x, const float p_y, const float p_z, const float p_w);

		/**
		 * @brief Constructor using a scalar and a vector
		 * @param p_scalar The scalar
		 * @param p_vector The vector
		 */
		inline Quaternion(const float p_scalar, const Vector3F& p_vector);

		/**
		 * @brief Copy Constructor
		 * @param p_other
		 */
		inline Quaternion(const Quaternion& p_other);

		/**
		 * @brief Move Constructor
		 * @param p_other
		 */
		inline Quaternion(Quaternion&& p_other) noexcept;
		
		/**
		 * @brief Construct from rotation matrix
		 * @param p_matrix Rotation matrix
		 */
		inline Quaternion(const Matrix3<float>& p_matrix);
		
		/**
		 * @brief Construct from rotation matrix
		 * @param p_matrix Rotation matrix
		 */
		inline Quaternion(const Matrix4<float>& p_matrix);

		/**
		 * @brief Constuct a quaternion from axis and angle in radian
		 * @param p_axis
		 * @param p_angleInRadians
		 */
		inline Quaternion(const Vector3<float>& p_axis, const float p_angleInRadians);

		~Quaternion() = default;
		
		/**
		 * @brief Construct from euler angles
		 */
		inline void MakeFromEuler(const Vector3<float>& p_euler);
		inline void MakeFromEuler(const float p_x, const float p_y, const float p_z);

		/**
		 * @brief Copy assignment
		 * @param p_other The quaternion
		 * @return The current quaternion modified
		 */
		inline Quaternion& operator=(const Quaternion& p_other) = default;

		/**
		 * @brief Move assigment
		 * @param p_other The quaternion
		 * @return The current quaternion modified 
		 */
		inline Quaternion& operator=(Quaternion&& p_other) noexcept;
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

		inline Quaternion operator*(const float p_scale) const;
		inline Quaternion& operator*=(const float p_scale);

		inline Quaternion operator*(const Quaternion& p_otherQuaternion) const;
		inline Quaternion& operator*=(const Quaternion& p_otherQuaternion);

		inline Quaternion operator*(const Vector3<float>& p_toMultiply) const;
		inline Quaternion& operator*=(const Vector3<float>& p_toMultiply);
		
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

		inline Quaternion Multiply(const Quaternion& p_quaternion) const;
		
		inline float Norm() const;
		constexpr inline float NormSquare() const;
		float GetAngle() const;

		Quaternion& Inverse();
		static Quaternion Inverse(const Quaternion& p_quaternion);

		Quaternion& Conjugate();
		static Quaternion Conjugate(const Quaternion& p_quaternion);

		Quaternion& ConvertToUnitNormQuaternion();

		static Vector3F RotateVectorAboutAngleAndAxis(const float p_angle, const Vector3F& p_axis, const Vector3F& p_vectorToRotate);

		Vector3F GetRotationAxis() const;

		float AngularDistance(const Quaternion& p_other) const;

		float GetXAxisValue() const;
		float GetYAxisValue() const;
		float GetZAxisValue() const;
		float GetRealValue() const;

		void SetXAxisValue(const float p_xValue);
		void SetYAxisValue(const float p_yValue);
		void SetZAxisValue(const float p_zValue);
		void SetRealValue(const float p_realValue);

		/**
		 * @param p_first
		 * @param p_second
		 * @param p_alpha
		 */
		static Quaternion Lerp(const Quaternion& p_first, const Quaternion& p_second, const float p_alpha);

		/**
		 * @param p_first
		 * @param p_second
		 * @param p_alpha
		 */
		static Quaternion Slerp(const Quaternion& p_first, const Quaternion& p_second, const float p_alpha);
		
		static Quaternion Nlerp(const Quaternion& p_first, const Quaternion& p_second, const float p_alpha);
		
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
		Quaternion ToUnitNormQuaternion();
		Vector3<float> ToEuler() const;
		static Quaternion ToQuaternion(const Vector3F& p_euler);
		static Quaternion ToQuaternion(const float p_yaw, const float p_pitch, const float p_roll);
		std::string ToString() const;
		static std::string ToString(const Quaternion& p_quaternion);
		Matrix3<float> ToMatrix3() const;
		Matrix4<float> ToMatrix4() const;
#pragma endregion
	};

	std::ostream& operator<<(std::ostream& p_stream, const Quaternion& p_quaternion);
}

#include <GPM/Quaternion/Quaternion.inl>