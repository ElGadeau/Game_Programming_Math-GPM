#include <iostream>
#include <string>
#include <sstream>

template<typename myType>
GPM::Matrix3<myType> GPM::Matrix3<myType>::identity = { 1,0,0,
                                                        0,1,0,
                                                        0,0,1 };
template<typename myType>
GPM::Matrix3<myType> GPM::Matrix3<myType>::zero = { 0,0,0,
                                                    0,0,0,
                                                    0,0,0 };

template <typename myType>
std::string GPM::Matrix3<myType>::ToString()
{
    std::stringstream stringStream;
    stringStream << '[' << m_data[0] << "  " << m_data[1] << "  " << m_data[2] << "]\n"
              << '|' << m_data[3] << "  " << m_data[4] << "  " << m_data[5] << "|\n"
              << '[' << m_data[6] << "  " << m_data[7] << "  " << m_data[8] << "]\n";
    return { stringStream.str() };
}
