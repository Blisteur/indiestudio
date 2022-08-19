/*
** EPITECH PROJECT, 2022
** Mouse.cpp
** File description:
** Mouse
*/

#include "Mouse.hpp"

encapsulation::raylib::Mouse::Mouse()
{
}

encapsulation::raylib::Mouse::~Mouse()
{
}

bool encapsulation::raylib::Mouse::isMouseButtonPressed(int button) const
{
    return (IsMouseButtonPressed(button));
}

bool encapsulation::raylib::Mouse::isMouseButtonDown(int button) const
{
    return (IsMouseButtonDown(button));
}

bool encapsulation::raylib::Mouse::isMouseButtonReleased(int button) const
{
    return (IsMouseButtonReleased(button));
}

bool encapsulation::raylib::Mouse::isMouseButtonUp(int button) const
{
    return (IsMouseButtonUp(button));
}

int encapsulation::raylib::Mouse::getMouseX() const
{
    return (GetMouseX());
}

int encapsulation::raylib::Mouse::getMouseY() const
{
    return (GetMouseY());
}

Vector2 encapsulation::raylib::Mouse::getMousePosition() const
{
    return (GetMousePosition());
}

int encapsulation::raylib::Mouse::getTouchX() const
{
    return (GetTouchX());
}

int encapsulation::raylib::Mouse::getTouchY() const
{
    return (GetTouchY());
}

Vector2 encapsulation::raylib::Mouse::getTouchPosition(int index) const
{
    return (GetTouchPosition(index));
}

float encapsulation::raylib::Mouse::getMouseWheelMove() const
{
    return (GetMouseWheelMove());
}
