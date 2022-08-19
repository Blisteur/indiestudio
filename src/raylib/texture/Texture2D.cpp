/*
** EPITECH PROJECT, 2022
** Texture2D.cpp
** File description:
** Texture2D
*/

#include "Texture2D.hpp"

encapsulation::raylib::Texture2D::Texture2D(unsigned int id, int width, int height, int mipmaps, int format) : ::Texture2D{id, width, height, mipmaps, format}
{
}

encapsulation::raylib::Texture2D::Texture2D(const ::Texture& texture)
{
    this->set(texture);
}

encapsulation::raylib::Texture2D::Texture2D(const ::Image& image)
{
    if (!this->load(image)) {
        throw encapsulation::raylib::RaylibError("Failed to load texture from image", "Texture2D");
    }
}

encapsulation::raylib::Texture2D::Texture2D(const std::string& filepath)
{
    std::cout << "Texture loading from filepath: " << filepath << std::endl;
    if (!this->load(filepath)) {
        throw encapsulation::raylib::RaylibError("Failed to load texture from filepath", "Texture2D");
    }
}

encapsulation::raylib::Texture2D::~Texture2D()
{
    this->unload();
}

bool encapsulation::raylib::Texture2D::load(const ::Image& image)
{
    this->set(::LoadTextureFromImage(image));
    return (id == 0 ? false : true);
}

bool encapsulation::raylib::Texture2D::load(const std::string& filepath)
{
    this->set(::LoadTexture(filepath.c_str()));
    return (id == 0 ? false : true);
}

void encapsulation::raylib::Texture2D::unload()
{
    UnloadTexture(*this);
    std::cout << "Texture2D::unload()" << std::endl;
}

void encapsulation::raylib::Texture2D::set(const ::Texture2D& texture)
{
    id = texture.id;
    width = texture.width;
    height = texture.height;
    mipmaps = texture.mipmaps;
    format = texture.format;
}

void encapsulation::raylib::Texture2D::updateTexture(const void *pixels)
{
    UpdateTexture(*this, pixels);
}

void encapsulation::raylib::Texture2D::updateTextureRec(::Rectangle rectangle, const void *pixels)
{
    UpdateTextureRec(*this, rectangle, pixels);
}

void encapsulation::raylib::Texture2D::drawTexture(int x, int y, ::Color color) const
{
    DrawTexture(*this, x, y, color);
}

void encapsulation::raylib::Texture2D::drawTextureV(::Vector2 vector, ::Color color) const
{
    DrawTextureV(*this, vector, color);
}

void encapsulation::raylib::Texture2D::drawTextureRec(::Rectangle rectangle, ::Vector2 vector, ::Color color) const
{
    DrawTextureRec(*this, rectangle, vector, color);
}

void encapsulation::raylib::Texture2D::drawTextureEx(::Vector2 position, float rotation, float scale, ::Color tint) const
{
    DrawTextureEx(*this, position, rotation, scale, tint);
}

void encapsulation::raylib::Texture2D::drawTextureTiled(::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint) const
{
    DrawTextureTiled(*this, source, dest, origin, rotation, scale, tint);
}
