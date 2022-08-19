/*
** EPITECH PROJECT, 2022
** Gamepad.hpp
** File description:
** Gamepad
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Gamepad {
            public:
                Gamepad(int gamepadId);
                ~Gamepad();

                bool isGamepadAvailable() const;
                const std::string getGamepadName() const;
                bool isGamepadButtonPressed(::KeyboardKey) const;
                bool isGamepadButtonDown(::KeyboardKey) const;
                bool isGamepadButtonReleased(::KeyboardKey) const;
                bool isGamepadButtonUp(::KeyboardKey) const;
                int getGamepadButtonPressed() const;
                int getGamepadAxisCount() const;
                float getGamepadAxisMovement(int axis) const;
                int setGamepadMappings(const std::string mappings) const;
            protected:
            private:
                int _gamepadId;
        };
    }
}
