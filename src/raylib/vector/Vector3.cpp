/*
** EPITECH PROJECT, 2022
** Vector3.cpp
** File description:
** Vector3
*/

#include "Vector3.hpp"

encapsulation::raylib::Vector3::Vector3(): ::Vector3{0, 0, 0}
{
}

encapsulation::raylib::Vector3::Vector3(const ::Vector3& vector): ::Vector3{vector.x, vector.y, vector.z}
{
}

encapsulation::raylib::Vector3::Vector3(float x, float y, float z): ::Vector3{x, y, z}
{
}

encapsulation::raylib::Vector3::~Vector3()
{
}

void encapsulation::raylib::Vector3::Set(const ::Vector3& vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

bool encapsulation::raylib::Vector3::operator==(const ::Vector3& vector) const
{
    return (x == vector.x ? y == vector.x ? z == vector.z : false : false);
}

bool encapsulation::raylib::Vector3::operator!=(const ::Vector3& vector) const
{
    return (!(x == vector.x ? y == vector.x : false ));
}

encapsulation::raylib::Vector3& encapsulation::raylib::Vector3::operator=(const ::Vector3& vector)
{
    Set(vector);
    return *this;
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::operator+(const ::Vector3& vector)
{
    return (::Vector3Add(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::operator-(const ::Vector3& vector)
{
    return (::Vector3Subtract(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::operator*(const ::Vector3& vector)
{
    return (::Vector3Multiply(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::operator/(const ::Vector3& vector)
{
    return (::Vector3Divide(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::vector3Add(const ::Vector3& vector)
{
    return (::Vector3Add(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::vector3Subtract(const ::Vector3& vector)
{
    return (::Vector3Subtract(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::vector3Multiply(const ::Vector3& vector)
{
    return (::Vector3Multiply(*this, vector));
}

encapsulation::raylib::Vector3 encapsulation::raylib::Vector3::vector3Divide(const ::Vector3& vector)
{
    return (::Vector3Divide(*this, vector));
}

encapsulation::raylib::Vector3& encapsulation::raylib::Vector3::operator+=(const ::Vector3& vector)
{
    Set(::Vector3Add(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector3& encapsulation::raylib::Vector3::operator-=(const ::Vector3& vector)
{
    Set(::Vector3Subtract(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector3& encapsulation::raylib::Vector3::operator*=(const ::Vector3& vector)
{
    Set(::Vector3Multiply(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector3& encapsulation::raylib::Vector3::operator/=(const ::Vector3& vector)
{
    Set(::Vector3Divide(*this, vector));
    return (*this);
}
