/*
** EPITECH PROJECT, 2022
** Button.cpp
** File description:
** Button
*/

#include "Button.hpp"
#include "../../raylib/mouse/Mouse.hpp"

Indie::game::Button::Button(const std::string& texture, const encapsulation::raylib::Rectangle& _pos, const encapsulation::raylib::Rectangle& _normal, const encapsulation::raylib::Rectangle& _hover)
{
    this->_texture = std::move(std::make_unique<encapsulation::raylib::Texture2D>(texture));
    this->_pos = _pos;
    this->_normal = _normal;
    this->_hover = _hover;
}

Indie::game::Button::~Button()
{
}

void Indie::game::Button::drawButton()
{
    encapsulation::raylib::Mouse mouse;

    if (this->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_texture->drawTextureRec({this->_hover.x, this->_hover.y, this->_hover.width, this->_hover.height}, {this->_pos.x, this->_pos.y}, WHITE);
    else
        this->_texture->drawTextureRec({this->_normal.x, this->_normal.y, this->_normal.width, this->_normal.height}, {this->_pos.x, this->_pos.y}, WHITE);
}
