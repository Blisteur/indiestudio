/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Font
*/

#pragma once

#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Font : public ::Font {
            public:
                Font() = default;
                Font(std::string path);
                ~Font();

                void drawText(std::string text, ::Vector2 position, float fontSize, float spacing, ::Color tint);
                void load(std::string path);
                void set(const ::Font&);
                Font& operator=(const ::Font&) = delete;
        };
    }
}