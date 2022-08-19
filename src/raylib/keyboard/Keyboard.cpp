/*
** EPITECH PROJECT, 2022
** Keyboard.cpp
** File description:
** Keyboard
*/

#include "Keyboard.hpp"

encapsulation::raylib::Keyboard::Keyboard()
{
}

encapsulation::raylib::Keyboard::~Keyboard()
{
}

bool encapsulation::raylib::Keyboard::isKeyPressed(::KeyboardKey key) const
{
    return (IsKeyPressed(key));
}

bool encapsulation::raylib::Keyboard::isKeyDown(::KeyboardKey key) const
{
    return (IsKeyDown(key));
}

bool encapsulation::raylib::Keyboard::isKeyReleased(::KeyboardKey key) const
{
    return (IsKeyReleased(key));
}

bool encapsulation::raylib::Keyboard::isKeyUp(::KeyboardKey key) const
{
    return (IsKeyUp(key));
}

int encapsulation::raylib::Keyboard::getKeyPressed() const
{
    return (GetKeyPressed());
}

int encapsulation::raylib::Keyboard::getCharPressed() const
{
    return (GetCharPressed());
}
