/*
** EPITECH PROJECT, 2022
** Rectangle.cpp
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

encapsulation::raylib::Rectangle::Rectangle(): ::Rectangle{0, 0, 0, 0}
{

}

encapsulation::raylib::Rectangle::Rectangle(float x, float y, float width, float height): ::Rectangle{x, y, width, height}
{
}

encapsulation::raylib::Rectangle::~Rectangle()
{
}

void encapsulation::raylib::Rectangle::set(float x, float y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void encapsulation::raylib::Rectangle::set(const ::Rectangle& rect)
{
    x = rect.x;
    y = rect.y;
    width = rect.width;
    height = rect.height;
}

bool encapsulation::raylib::Rectangle::coordInRect(float x, float y)
{
    if ((x >= this->x && x <= (this->x + this->width)) && (y >= this->y && y <= (this->y + this->height)))
        return true;
    if ((x >= (this->x + this->width) && x <= this->x) && (y >= (this->y + this->height) && y <= this->y))
        return true;
    return false;
}

encapsulation::raylib::Rectangle& encapsulation::raylib::Rectangle::operator=(const ::Rectangle& rect)
{
    this->set(rect);
    return (*this);
}