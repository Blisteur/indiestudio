/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** InputBox.hpp
*/

#include "../raylib/mouse/Mouse.hpp"
#include "../raylib/keyboard/Keyboard.hpp"
#include "KeyDictionnary.hpp"

#ifndef BOMBERMAN_INPUTBOX_HPP
#define BOMBERMAN_INPUTBOX_HPP

namespace Indie {
    namespace graphic {
        namespace position {
            class Position2D {
            public:
                Position2D(float x, float z, float width, float height, float text_x, float text_z);
                float x;
                float z;
                float width;
                float height;
                float text_x;
                float text_z;
            };
        }
        namespace element {
            class InputBox {
            public:

                InputBox(position::Position2D position, int key = 0);
                bool isInside(int x, int z) const;
                void mouseInteract(bool pressed);
                void drawBox(bool hidden);
                void handleKeyPressed(int key);
                int getKey() const;

            private:
                position::Position2D position;
                int key;
                bool selected;
            };
        }
    }
}

#endif //BOMBERMAN_INPUTBOX_HPP
