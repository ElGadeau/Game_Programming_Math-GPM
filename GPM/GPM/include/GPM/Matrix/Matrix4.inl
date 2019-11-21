#pragma once

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::identity = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
};

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::zero = {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
};

template<typename T>
constexpr void GPM::Matrix4<T>::ToString() noexcept
{
    std::cout << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "  " << m_data[3] << "]\n"
              << '[' << m_data[4] << "  " << m_data[5] << "  " << m_data[6] << "  " << m_data[7] << "]\n"
              << '[' << m_data[8] << "  " << m_data[9] << "  " << m_data[10] << "  " << m_data[11] << "]\n"
              << '[' << m_data[12] << "  " << m_data[13] << "  " << m_data[14] << "  " << m_data[15] << "]\n";
}

template<typename T>
constexpr void GPM::Matrix4<T>::SetColumn(int p_column, Vector4<T>& p_vector)
{
    int columnStart = p_column;
    m_data[columnStart] = p_vector.x;
    m_data[columnStart + 4] = p_vector.y;
    m_data[columnStart + 8] = p_vector.z;
    m_data[columnStart + 12] = p_vector.w;
}

template<typename T>
constexpr void GPM::Matrix4<T>::SetRow(int p_row, Vector4<T>& p_vector)
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
}

template<typename T>
T GPM::Matrix4<T>::GetMinor()
{
    //TODO
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Inverse()
{
    //TODO need determinant to complete
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Scale(Vector3<T>& p_scale)
{
    //TODO
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Rotation(Vector3<T>& p_rotation)
{
    //TODO
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Translate(Vector3<T>& p_translate)
{
    //TODO
}

#pragma region Arithmetic Operations

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Add(Matrix4<T>& p_matrix, Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = p_matrix.m_data[i] + p_other.m_data[i];
    }

    return tmpMat;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Subtract(Matrix4<T>& p_matrix, Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = p_matrix.m_data[i] - p_other.m_data[i];
    }

    return tmpMat;
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::Multiply(Matrix4<T>& p_matrix, Matrix4<T>& p_other)
{
    Matrix4<T> tmpMat = zero;

    for (int i = 0; i <= 12; i += 4)
    {
        for (int j = 0; j < 4; j++)
        {
            tmpMat.m_data[i + j] = (p_matrix[i] * p_other[j])
                                 + (p_matrix[i + 1] * p_other[j + 4])
                                 + (p_matrix[i + 2] * p_other[j + 8])
                                 + (p_matrix[i + 3] * p_other[j + 12]);
        }
    }

    return tmpMat;
}

template<typename T>
bool GPM::Matrix4<T>::Equals(Matrix4<T>& p_matrix, Matrix4<T>& p_other)
{
    for (int i = 0; i < 16; i++)
    {
        if (p_matrix.m_data[i] != p_other.m_data[i])
            return false;
    }
    return true;
}

#pragma endregion 

#pragma region Operators
//operators

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator+(Matrix4<T>& p_matrix)
{
    return Add(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator+=(Matrix4<T>& p_matrix)
{
    *this = Add(*this, p_matrix);
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator-(Matrix4<T>& p_matrix)
{
    return Subtract(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator-=(Matrix4<T>& p_matrix)
{
    *this = Subtract(*this, p_matrix);
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator*(Matrix4<T>& p_matrix)
{
    return Multiply(*this, p_matrix);
}

template<typename T>
void GPM::Matrix4<T>::operator*=(Matrix4<T>& p_matrix)
{
    *this = Multiply(*this, p_matrix);
}

template<typename T>
GPM::Matrix4<T> GPM::Matrix4<T>::operator*(Vector4<T>& p_vector)
{
    //TODO
}

template<typename T>
void GPM::Matrix4<T>::operator*=(Vector4<T>& p_vector)
{
    //TODO
}

template<typename T>
bool GPM::Matrix4<T>::operator==(Matrix4<T>& p_matrix)
{
    return Equals(*this, p_matrix);
}

template<typename T>
bool GPM::Matrix4<T>::operator!=(Matrix4<T>& p_matrix)
{
    return !Equals(*this, p_matrix);
}

template<typename T>
T GPM::Matrix4<T>::operator[](int p_position)
{
    return this->m_data[p_position];
}

#pragma endregion