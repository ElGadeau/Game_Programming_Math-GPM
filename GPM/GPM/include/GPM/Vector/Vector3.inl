#include <GPM/Vector/Vector3.h>
#include <cmath>

template<typename T>
void Vector3<T>::Add(Vector3<T>& p_vec)
{
    x += p_vec.x;
    y += p_vec.y;
    z += p_vec.z;
}

template<typename T>
void Vector3<T>::Substract(Vector3<T>& p_vec)
{
    x -= p_vec.x;
    y -= p_vec.y;
    z -= p_vec.z;
}

template<typename T>
void Vector3<T>::Multiply(Vector3<T>& p_vec)
{
    x *= p_vec.x;
    y *= p_vec.y;
    z *= p_vec.z;
}

template<typename T>
void Vector3<T>::Divide(Vector3<T>& p_vec)
{
    x /= p_vec.x;
    y /= p_vec.y;
    z /= p_vec.z;
}

template<typename T>
void Vector3<T>::Set(T px, T py, T pz)
{
    x = px;
    y = py;
    z = pz;
}

template<typename T>
Vector3<T> Vector3<T>::Forward()
{
    Vector3<T> tmp;
    tmp.x = 0;
    tmp.y = 0;
    tmp.z = 1;

    return tmp;
}

template<typename T>
Vector3<T> Vector3<T>::Right()
{
    Vector3<T> tmp;
    tmp.x = 1;
    tmp.y = 0;
    tmp.z = 0;

    return tmp;
}

template<typename T>
Vector3<T> Vector3<T>::Up()
{
    Vector3<T> tmp;
    tmp.x = 0;
    tmp.y = 1;
    tmp.z = 0;

    return tmp;
}

template<typename T>
Vector3<T> Vector3<T>::Zero()
{
    Vector3<T> tmp;
    tmp.x = 0;
    tmp.y = 0;
    tmp.z = 0;

    return tmp;
}

template<typename T>
Vector3<T> Vector3<T>::One()
{
    Vector3<T> tmp;
    tmp.x = 1;
    tmp.y = 1;
    tmp.z = 1;

    return tmp;
}

template<typename T>
T Vector3<T>::GetMagnitude()
{
    T magnitude = sqrt((x * x) + (y * y) + (z * z));
    return magnitude;
}
