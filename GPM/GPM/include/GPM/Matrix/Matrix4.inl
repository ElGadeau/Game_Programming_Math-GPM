#pragma once

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::GetIdentity()
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
GPM::Matrix4<type> GPM::Matrix4<type>::GetZero()
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
void GPM::Matrix4<type>::ToString()
{
    std::cout << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "  " << m_data[3] << "]\n"
        << '[' << m_data[4] << "  " << m_data[5] << "  " << m_data[6] << "  " << m_data[7] << "]\n"
        << '[' << m_data[8] << "  " << m_data[9] << "  " << m_data[10] << "  " << m_data[11] << "]\n"
        << '[' << m_data[12] << "  " << m_data[13] << "  " << m_data[14] << "  " << m_data[15] << "]\n";
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
GPM::Matrix4<type> GPM::Matrix4<type>::Scale(Vector3<type> p_scale)
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Rotation(Vector3<type> p_rotation)
{
    //TODO
}

template<typename type>
GPM::Matrix4<type> GPM::Matrix4<type>::Translate(Vector3<type> p_translate)
{
    //TODO
}