#pragma once

#include <string>

namespace GPM
{
    template <typename Type>
    struct Matrix3
    {
        static_assert(std::is_arithmetic<Type>::value, "Matrix3 should only be used with arithmetic types");

        Type m_data[9] = { 1,0,0,
                           0,1,0,
                           0,0,1 };

        /**
         * @brief function used to debug values from the matrix
         */
        std::string ToString();
#pragma region Static Properties
        /**
         * @brief This is a const matrix that has 1 in the diagonal and 0 elsewhere
         */
        static Matrix3<Type> identity;
        /** 
         *  @brief This is a const matrix that has 0 everywhere
         */
        static Matrix3<Type> zero;
#pragma endregion 
        /*
        # Properties
        */

        float Determinant();
        constexpr Matrix3<Type> Inverse();
        bool IsIdentity();
        constexpr Matrix3<Type> Transpose();
    };

}

#include <GPM/Matrix/Matrix3.inl>