/*
** EPITECH PROJECT, 2022
** Button.hpp
** File description:
** Button
*/

#pragma once

#include "raylib.h"
#include <memory>
#include <string>
#include "../../raylib/texture/Texture2D.hpp"
#include "../../raylib/rectangle/Rectangle.hpp"

namespace Indie {
    namespace game {
        class Button {
            public:
                Button(const std::string&, const encapsulation::raylib::Rectangle&, const encapsulation::raylib::Rectangle&, const encapsulation::raylib::Rectangle&);
                ~Button();

                void drawButton();

                encapsulation::raylib::Rectangle _pos;
                encapsulation::raylib::Rectangle _normal;
                encapsulation::raylib::Rectangle _hover;

                std::unique_ptr<encapsulation::raylib::Texture2D> _texture;
            protected:
            private:
        };
    }
}