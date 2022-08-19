/*
** EPITECH PROJECT, 2022
** Mouse.hpp
** File description:
** Mouse
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Mouse {
            public:
                Mouse();
                ~Mouse();

                bool isMouseButtonPressed(int) const;
                bool isMouseButtonDown(int) const;
                bool isMouseButtonReleased(int) const;
                bool isMouseButtonUp(int) const;
                int getMouseX() const;
                int getMouseY() const;
                Vector2 getMousePosition() const;
                int getTouchX() const;
                int getTouchY() const;
                Vector2 getTouchPosition(int) const;
                float getMouseWheelMove() const;

            protected:
            private:
        };
    }
}
