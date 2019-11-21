#pragma once

template<typename type>
constexpr GPM::Matrix4<type> GPM::Matrix4<type>::GetIdentity() noexcept
{
    Matrix4<type> identity{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
            };

    return identity;
}

template<typename type>
constexpr GPM::Matrix4<type> GPM::Matrix4<type>::GetZero() noexcept
{
    Matrix4<type> zero{
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
            };

    return zero;
}

template<typename type>
constexpr void GPM::Matrix4<type>::ToString() noexcept
{
    std::cout << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "  " << m_data[3] << "]\n"
              << '[' << m_data[4] << "  " << m_data[5] << "  " << m_data[6] << "  " << m_data[7] << "]\n"
              << '[' << m_data[8] << "  " << m_data[9] << "  " << m_data[10] << "  " << m_data[11] << "]\n"
              << '[' << m_data[12] << "  " << m_data[13] << "  " << m_data[14] << "  " << m_data[15] << "]\n";
}

template<typename type>
constexpr void GPM::Matrix4<type>::SetColumn(int p_column, Vector4<type>& p_vector) noexcept
{
    int columnStart = p_column;
    m_data[columnStart] = p_vector.x;
    m_data[columnStart + 4] = p_vector.y;
    m_data[columnStart + 8] = p_vector.z;
    m_data[columnStart + 12] = p_vector.w;
}

template<typename type>
constexpr void GPM::Matrix4<type>::SetRow(int p_row, Vector4<type>& p_vector) noexcept
{
    int rowStart = (4 * p_row);
    m_data[rowStart] = p_vector.x;
    m_data[rowStart + 1] = p_vector.y;
    m_data[rowStart + 2] = p_vector.z;
    m_data[rowStart + 3] = p_vector.w;
}

template<typename type>
type GPM::Matrix4<type>::Determinant()
{
    //TODO need GetMinor to complete
}

template<typename type>
type GPM::Matrix4<type>::GetMinor()
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Inverse()
{
    //TODO need determinant to complete
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Scale(Vector3<type>& p_scale)
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Rotation(Vector3<type>& p_rotation)
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Translate(Vector3<type>& p_translate)
{
    //TODO
}


#pragma region Operators
//operators

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::operator+(Matrix4<type>& p_matrix)
{
    Matrix4<type> tmpMat = Matrix4<type>::GetZero();

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = this->m_data[i] + p_matrix.m_data[i];
    }

    return tmpMat;
}

template<typename type>
void GPM::Matrix4<type>::operator+=(Matrix4<type>& p_matrix)
{
    for (int i = 0; i < 16; i++)
    {
       this->m_data[i] = this->m_data[i] + p_matrix.m_data[i];
    }
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::operator-(Matrix4<type>& p_matrix)
{
    Matrix4<type> tmpMat = Matrix4<type>::GetZero();

    for (int i = 0; i < 16; i++)
    {
        tmpMat.m_data[i] = this->m_data[i] - p_matrix.m_data[i];
    }

    return tmpMat;
}

template<typename type>
void GPM::Matrix4<type>::operator-=(Matrix4<type>& p_matrix)
{
    for (int i = 0; i < 16; i++)
    {
        this->m_data[i] = this->m_data[i] - p_matrix.m_data[i];
    }
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::operator*(Matrix4<type>& p_matrix)
{
    //TODO
}

template<typename type>
void GPM::Matrix4<type>::operator*=(Matrix4<type>& p_matrix)
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::operator*(Vector4<type>& p_vector)
{
    //TODO
}

template<typename type>
void GPM::Matrix4<type>::operator*=(Vector4<type>& p_vector)
{
    //TODO
}

template<typename type>
bool GPM::Matrix4<type>::operator==(Matrix4<type>& p_matrix)
{
    for (int i = 0; i < 16; i++)
    {
        if (this->m_data[i] != p_matrix.m_data[i])
            return false;
    }
    return true;
}

template<typename type>
bool GPM::Matrix4<type>::operator!=(Matrix4<type>& p_matrix)
{
    for (int i = 0; i < 16; i++)
    {
        if (this->m_data[i] == p_matrix.m_data[i])
            return false;
    }
    return true;
}

template<typename type>
type GPM::Matrix4<type>::operator[](int p_position)
{
    return this->m_data[p_position];
}

#pragma endregion