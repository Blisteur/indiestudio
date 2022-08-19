/*
** EPITECH PROJECT, 2022
** Gamepad.cpp
** File description:
** Gamepad
*/

#include "Gamepad.hpp"

encapsulation::raylib::Gamepad::Gamepad(int gamepadId)
{
    _gamepadId = gamepadId;
}

encapsulation::raylib::Gamepad::~Gamepad()
{
}

bool encapsulation::raylib::Gamepad::isGamepadAvailable() const
{
    return (IsGamepadAvailable(_gamepadId));
}

const std::string encapsulation::raylib::Gamepad::getGamepadName() const
{
    return (GetGamepadName(_gamepadId));
}

bool encapsulation::raylib::Gamepad::isGamepadButtonPressed(::KeyboardKey key) const
{
    return (IsGamepadButtonPressed(_gamepadId, key));
}

bool encapsulation::raylib::Gamepad::isGamepadButtonDown(::KeyboardKey key) const
{
    return (IsGamepadButtonDown(_gamepadId, key));
}

bool encapsulation::raylib::Gamepad::isGamepadButtonReleased(::KeyboardKey key) const
{
    return (IsGamepadButtonReleased(_gamepadId, key));
}

bool encapsulation::raylib::Gamepad::isGamepadButtonUp(::KeyboardKey key) const
{
    return (IsGamepadButtonUp(_gamepadId, key));
}

int encapsulation::raylib::Gamepad::getGamepadButtonPressed() const
{
    return (GetGamepadButtonPressed());
}

int encapsulation::raylib::Gamepad::getGamepadAxisCount() const
{
    return (GetGamepadAxisCount(_gamepadId));
}

float encapsulation::raylib::Gamepad::getGamepadAxisMovement(int axis) const
{
    return (GetGamepadAxisMovement(_gamepadId, axis));
}

int encapsulation::raylib::Gamepad::setGamepadMappings(const std::string mappings) const
{
    return (SetGamepadMappings(mappings.c_str()));
}