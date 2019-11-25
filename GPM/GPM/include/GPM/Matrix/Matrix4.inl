#pragma once

#pragma region Constuctor

template<typename T> GPM::Matrix4<T>::Matrix4()
{
    m_data = identity;
}

template<typename T> GPM::Matrix4<T>::Matrix4(const Matrix4<T>& p_matrix)
{
    memcpy(m_data, p_matrix.m_data, 16 * sizeof(T));
}

template<typename T> GPM::Matrix4<T>::Matrix4(const Vector3<T>& p_vector)
{
    m_data[0] = p_vector.x;
    m_data[5] = p_vector.y;
    m_data[10] = p_vector.z;
}

template<typename T> GPM::Matrix4<T>::Matrix4(const T* p_data)
{
    if (p_data == nullptr)
        return;

    memcpy(m_data, p_data, 16 * sizeof(T));
}

template<typename T> GPM::Matrix4<T>::Matrix4(const T p_00, const T p_01, const T p_02, const T p_03,
    const T p_10, const T p_11, const T p_12, const T p_13,
    const T p_20, const T p_21, const T p_22, const T p_23,
    const T p_30, const T p_31, const T p_32, const T p_33) : m_data{p_00, p_01, p_02, p_03, p_10, p_11, p_12, p_13, p_20, p_21, p_22, p_23, p_30, p_31, p_32, p_33}
{
}

#pragma endregion 

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::identity({
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
});

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::zero({
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
});

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::ScaleMatrix4(const Vector3<T>& p_scale)
{
    Matrix4<T> tmpScale = identity;
    tmpScale.m_data[0] = p_scale.x;
    tmpScale.m_data[5] = p_scale.y;
    tmpScale.m_data[10] = p_scale.z;
    return tmpScale;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::RotationMatrix4(const Vector3<T>& p_rotation)
{
    //stuck angle in radians
    float xAngle = Tools::Utils::ToRadians(p_rotation.x);
    float yAngle = Tools::Utils::ToRadians(p_rotation.y);
    float zAngle = Tools::Utils::ToRadians(p_rotation.z);

    //stuck cos and sin of angle
    float xAngleCos = Tools::Utils::CosF(xAngle);
    float xAngleSin = Tools::Utils::SinF(xAngle);

    float yAngleCos = Tools::Utils::CosF(yAngle);
    float yAngleSin = Tools::Utils::SinF(yAngle);

    float zAngleCos = Tools::Utils::CosF(zAngle);
    float zAngleSin = Tools::Utils::SinF(zAngle);


    //X
    Matrix4<T> tmpX = identity;
    tmpX.m_data[5] = xAngleCos;
    tmpX.m_data[6] = xAngleSin;
    tmpX.m_data[9] = -xAngleSin;
    tmpX.m_data[10] = xAngleCos;

    //Y
    Matrix4<T> tmpY = identity;

    tmpY.m_data[0] = yAngleCos;
    tmpY.m_data[2] = yAngleSin;
    tmpY.m_data[8] = -yAngleSin;
    tmpY.m_data[10] = yAngleCos;

    //Z
    Matrix4<T> tmpZ = identity;

    tmpZ.m_data[0] = zAngleCos;
    tmpZ.m_data[1] = -zAngleSin;
    tmpZ.m_data[4] = zAngleSin;
    tmpZ.m_data[5] = zAngleCos;

    return tmpZ * tmpY * tmpX;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::TranslateMatrix4(const Vector3<T>& p_translate)
{
    Matrix4<T> tmpTrans = identity;
    tmpTrans.m_data[3] = p_translate.x;
    tmpTrans.m_data[7] = p_translate.y;
    tmpTrans.m_data[11] = p_translate.z;
    return tmpTrans;
}

template<typename T>
constexpr void GPM::Matrix4<T>::ToString() noexcept
{
    std::cout << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "  " << m_data[3] << "]\n"
              << '[' << m_data[4] << "  " << m_data[5] << "  " << m_data[6] << "  " << m_data[7] << "]\n"
              << '[' << m_data[8] << "  " << m_data[9] << "  " << m_data[10] << "  " << m_data[11] << "]\n"
              << '[' << m_data[12] << "  " << m_data[13] << "  " << m_data[14] << "  " << m_data[15] << "]\n";
}

template<typename T>
constexpr void GPM::Matrix4<T>::SetColumn(int p_column, const Vector4<T>& p_vector)
{
    int columnStart = p_column;
    m_data[columnStart] = p_vector.x;
    m_data[columnStart + 4] = p_vector.y;
    m_data[columnStart + 8] = p_vector.z;
    m_data[columnStart + 12] = p_vector.w;
}

template<typename T>
constexpr void GPM::Matrix4<T>::SetRow(int p_row, const Vector4<T>& p_vector)
{
    int rowStart = (4 * p_row);
    m_data[rowStart] = p_vector.x;
    m_data[rowStart + 1] = p_vector.y;
    m_data[rowStart + 2] = p_vector.z;
    m_data[rowStart + 3] = p_vector.w;
}

template<typename T>
T GPM::Matrix4<T>::Determinant()
{
    //TODO need GetMinor to complete
    return ((m_data[0] * GetMinor({ m_data[5], m_data[6], m_data[7], m_data[9], m_data[10], m_data[11], m_data[13], m_data[14], m_data[15] }))
          - (m_data[1] * GetMinor({ m_data[4], m_data[6], m_data[7], m_data[8], m_data[10], m_data[11], m_data[12], m_data[14], m_data[15] }))
          + (m_data[2] * GetMinor({ m_data[4], m_data[5], m_data[7], m_data[8], m_data[9], m_data[11], m_data[12], m_data[13], m_data[15] }))
          - (m_data[3] * GetMinor({ m_data[4], m_data[5], m_data[6], m_data[8], m_data[9], m_data[10], m_data[12], m_data[13], m_data[14] })));

}

template<typename T>
T GPM::Matrix4<T>::GetMinor(Matrix3<T> p_minor)
{
    return ((p_minor.m_data[0] * ((p_minor.m_data[4] * p_minor.m_data[8]) - (p_minor.m_data[5] * p_minor.m_data[7])))
          - (p_minor.m_data[1] * ((p_minor.m_data[3] * p_minor.m_data[8]) - (p_minor.m_data[5] * p_minor.m_data[6])))
          + (p_minor.m_data[2] * ((p_minor.m_data[3] * p_minor.m_data[7]) - (p_minor.m_data[4] * p_minor.m_data[6]))));
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Inverse()
{
    //TODO need determinant to complete
}

template<typename T>
void GPM::Matrix4<T>::Scale(const Vector3<T>& p_scale)
{
    Matrix4<T> tmpScale = Matrix4<T>::ScaleMatrix4(p_scale);
    *this *= tmpScale;
}

template<typename T>
void GPM::Matrix4<T>::Rotation(const Vector3<T>& p_rotation)
{
    //TODO
    Matrix4<T> tmpRot = Matrix4<T>::RotationMatrix4(p_rotation);
    *this *= tmpRot;
}

template<typename T>
void GPM::Matrix4<T>::Translate(const Vector3<T>& p_translate)
{
    Matrix4<T> tmpTrans = Matrix4<T>::TranslateMatrix4(p_translate);
    *this *= tmpTrans;
}

#pragma region Arithmetic Operations

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Add(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = p_matrix.m_data[i] + p_other.m_data[i];
    }

    return tmpMat;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Subtract(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = p_matrix.m_data[i] - p_other.m_data[i];
    }

    return tmpMat;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Multiply(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i <= 12; i += 4)
    {
        for (int j = 0; j < 4; j++)
        {
            tmpMat.m_data[i + j] = (p_matrix.m_data[i] * p_other.m_data[j])
                                 + (p_matrix.m_data[i + 1] * p_other.m_data[j + 4])
                                 + (p_matrix.m_data[i + 2] * p_other.m_data[j + 8])
                                 + (p_matrix.m_data[i + 3] * p_other.m_data[j + 12]);
        }
    }

    return tmpMat;
}

template<typename T>
GPM::Vector4<T> GPM::Matrix4<T>::Multiply(const Matrix4<T>& p_matrix, const Vector4<T>& p_vector)
{
    Vector4<T> tmpVec = Vector4F::zero;

    tmpVec.x = (p_matrix[0] * p_vector.x)
        + (p_matrix[1] * p_vector.y)
        + (p_matrix[2] * p_vector.z)
        + (p_matrix[3] * p_vector.w);

    tmpVec.y = (p_matrix[4] * p_vector.x)
        + (p_matrix[5] * p_vector.y)
        + (p_matrix[6] * p_vector.z)
        + (p_matrix[7] * p_vector.w);

    tmpVec.z = (p_matrix[8] * p_vector.x)
        + (p_matrix[9] * p_vector.y)
        + (p_matrix[10] * p_vector.z)
        + (p_matrix[11] * p_vector.w);

    tmpVec.w = (p_matrix[12] * p_vector.x)
        + (p_matrix[13] * p_vector.y)
        + (p_matrix[14] * p_vector.z)
        + (p_matrix[15] * p_vector.w);

    return tmpVec;
}

template<typename T>
bool GPM::Matrix4<T>::Equals(const Matrix4<T>& p_matrix, const Matrix4<T>& p_other)
{
    for (int i = 0; i < 16; i++)
    {
        if (p_matrix.m_data[i] != p_other.m_data[i])
            return false;
    }
    return true;
}

template<typename T>
void GPM::Matrix4<T>::Set(Matrix4<T>& p_matrix, const Matrix4<T>& p_other)
{
    memcpy(p_matrix.m_data, p_other.m_data, sizeof(T) * 16);
}

#pragma endregion 

#pragma region Operators
//operators

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator+(const Matrix4<T>& p_matrix)
{
    return Add(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator+=(const Matrix4<T>& p_matrix)
{
    *this = Add(*this, p_matrix);
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator-(const Matrix4<T>& p_matrix)
{
    return Subtract(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator-=(const Matrix4<T>& p_matrix)
{
    *this = Subtract(*this, p_matrix);
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator*(const Matrix4<T>& p_matrix)
{
    return Multiply(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator*=(const Matrix4<T>& p_matrix)
{
    *this = Multiply(*this, p_matrix);
}

template<typename T>
GPM::Vector4<T> GPM::Matrix4<T>::operator*(const Vector4<T>& p_vector)
{
    return Multiply(*this, p_vector);
}

template<typename T>
bool GPM::Matrix4<T>::operator==(const Matrix4<T>& p_matrix)
{
    return Equals(*this, p_matrix);
}

template<typename T>
bool GPM::Matrix4<T>::operator!=(const Matrix4<T>& p_matrix)
{
    return !Equals(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator=(const Matrix4<T>& p_matrix)
{
    Set(*this, p_matrix);
}

template<typename T>
T GPM::Matrix4<T>::operator[](int p_position)
{
    return m_data[p_position];
}

#pragma endregion