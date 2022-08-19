/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Font
*/

#include "Font.hpp"

encapsulation::raylib::Font::Font(std::string path)
{
    this->set(LoadFont(path.c_str()));

}

encapsulation::raylib::Font::~Font()
{
    UnloadFont(*this);
}

void encapsulation::raylib::Font::set(const ::Font &font)
{
    baseSize = font.baseSize;
    glyphCount = font.glyphCount;
    glyphPadding = font.glyphPadding;
    glyphs = font.glyphs;
    recs = font.recs;
    texture = font.texture;
}

void encapsulation::raylib::Font::drawText(std::string text, ::Vector2 position, float fontSize, float spacing, ::Color tint)
{
    DrawTextEx(*this, text.c_str(), position, fontSize, spacing, tint);
}

void encapsulation::raylib::Font::load(std::string path)
{
    this->set(LoadFont(path.c_str()));
}