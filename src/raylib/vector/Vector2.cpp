/*
** EPITECH PROJECT, 2022
** Vector2.cpp
** File description:
** Vector2
*/

#include "Vector2.hpp"

encapsulation::raylib::Vector2::Vector2(): ::Vector2{0, 0}
{
}

encapsulation::raylib::Vector2::Vector2(const ::Vector2& vector): ::Vector2{vector.x, vector.y}
{
}

encapsulation::raylib::Vector2::Vector2(float x, float y): ::Vector2{x, y}
{
}

encapsulation::raylib::Vector2::~Vector2()
{
}

void encapsulation::raylib::Vector2::Set(const ::Vector2& vector)
{
    x = vector.x;
    y = vector.y;
}

bool encapsulation::raylib::Vector2::operator==(const ::Vector2& vector) const
{
    return (x == vector.x ? y == vector.x : false);
}

bool encapsulation::raylib::Vector2::operator!=(const ::Vector2& vector) const
{
    return (!(x == vector.x ? y == vector.x : false));
}

encapsulation::raylib::Vector2& encapsulation::raylib::Vector2::operator=(const ::Vector2& vector)
{
    Set(vector);
    return *this;
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::operator+(const ::Vector2& vector)
{
    return (::Vector2Add(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::operator-(const ::Vector2& vector)
{
    return (::Vector2Subtract(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::operator*(const ::Vector2& vector)
{
    return (::Vector2Multiply(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::operator/(const ::Vector2& vector)
{
    return (::Vector2Divide(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::vector2Add(const ::Vector2& vector)
{
    return (::Vector2Add(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::vector2Subtract(const ::Vector2& vector)
{
    return (::Vector2Subtract(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::vector2Multiply(const ::Vector2& vector)
{
    return (::Vector2Multiply(*this, vector));
}

encapsulation::raylib::Vector2 encapsulation::raylib::Vector2::vector2Divide(const ::Vector2& vector)
{
    return (::Vector2Divide(*this, vector));
}

encapsulation::raylib::Vector2& encapsulation::raylib::Vector2::operator+=(const ::Vector2& vector)
{
    Set(::Vector2Add(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector2& encapsulation::raylib::Vector2::operator-=(const ::Vector2& vector)
{
    Set(::Vector2Subtract(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector2& encapsulation::raylib::Vector2::operator*=(const ::Vector2& vector)
{
    Set(::Vector2Multiply(*this, vector));
    return (*this);
}

encapsulation::raylib::Vector2& encapsulation::raylib::Vector2::operator/=(const ::Vector2& vector)
{
    Set(::Vector2Divide(*this, vector));
    return (*this);
}
