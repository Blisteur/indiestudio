/*
** EPITECH PROJECT, 2022
** Rectangle.hpp
** File description:
** Rectangle
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Rectangle : public ::Rectangle {
            public:
                Rectangle(float, float, float, float);
                Rectangle();
                ~Rectangle();

                void set(float, float, float, float);
                void set(const ::Rectangle&);
                bool coordInRect(float, float);

                Rectangle& operator=(const ::Rectangle&);
            protected:
            private:
        };
    }
}
