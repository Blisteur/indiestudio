/*
** EPITECH PROJECT, 2022
** Color.hpp
** File description:
** Color
*/

#pragma once

#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Color: ::Color {
            public:
                Color();
                Color(const ::Color&);
                ~Color();

                Color& operator=(const ::Color&);
        };
    }
}
