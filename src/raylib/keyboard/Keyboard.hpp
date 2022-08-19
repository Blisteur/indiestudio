/*
** EPITECH PROJECT, 2022
** Keyboard.hpp
** File description:
** Keyboard
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Keyboard {
            public:
                Keyboard();
                ~Keyboard();

                bool isKeyPressed(const KeyboardKey) const;
                bool isKeyDown(const KeyboardKey) const;
                bool isKeyReleased(const KeyboardKey) const;
                bool isKeyUp(const KeyboardKey) const;
                int getKeyPressed() const;
                int getCharPressed() const;
            protected:
            private:
        };
    }
}
