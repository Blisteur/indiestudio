/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** InputBox.cpp
*/

#include "InputBox.hpp"

Indie::graphic::position::Position2D::Position2D(float x, float z, float width, float height, float text_x,
                                                 float text_z) {
    this->x = x;
    this->z = z;
    this->text_x = text_x;
    this->text_z = text_z;
    this->width = width;
    this->height = height;
}

Indie::graphic::element::InputBox::InputBox(position::Position2D position,
                                            int key) : position(position) {
    this->key = key;
}

bool Indie::graphic::element::InputBox::isInside(int x, int z) const {
    int _x = position.x;
    int _z = position.z;
    int m_x = _x + position.width;
    int m_z = _z + position.height;

    if (x >= _x && x <= m_x)
        return (z >= _z && z <= m_z);
    return false;
}

void Indie::graphic::element::InputBox::mouseInteract(bool pressed) {
    encapsulation::raylib::Mouse mouse;

    if (isInside(mouse.getMouseX(), mouse.getMouseY())) {
        if (pressed) {
            if (!selected) selected = true;
        }
    } else if (selected && pressed) selected = !selected;
}

void Indie::graphic::element::InputBox::drawBox(bool hidden) {
    if (hidden) return;
    KeyDictionnary dictionnary;

    Rectangle rectangle = {position.x, position.z, position.width, position.height};
    if (!selected)
        DrawRectangleRec(rectangle, BLACK);
    else DrawRectangleRec(rectangle, LIGHTGRAY);
    DrawText(dictionnary.getStringFromKey(this->key).c_str(), position.text_x, position.text_z, 20, GRAY);
}

void Indie::graphic::element::InputBox::handleKeyPressed(int key) {
    encapsulation::raylib::Keyboard keyboard;

    if (!selected) return;
    if (keyboard.isKeyPressed(KEY_ESCAPE)) selected = !selected;
    if (key != 0) {
        if (key != this->key) {
            this->key = key;
        }
        selected = !selected;
    }
}

int Indie::graphic::element::InputBox::getKey() const {
    return this->key;
}


