/*
** EPITECH PROJECT, 2022
**Indie
** File description:
** MovementManager.cpp
*/

#include "MovementManager.hpp"

Indie::movement::Position::Position(float x, float y, float z)
{
    this->_position = std::make_tuple(x, y, z);
}

Indie::movement::Position::Position()
{
    this->_position = std::make_tuple(0,0,0);
}

std::tuple<float, float, float> Indie::movement::Position::getPosition()
{
    return (this->_position);
}

void Indie::movement::Position::setPosition(float x, float y, float z) {
    this->_position = std::make_tuple(x, y, z);
}

Indie::movement::Position::~Position() {
}

float Indie::movement::Position::getPositionX() {
    return std::get<0>(this->_position);
}

float Indie::movement::Position::getPositionY() {
    return std::get<1>(this->_position);
}

float Indie::movement::Position::getPositionZ() {
    return std::get<2>(this->_position);
}

void Indie::movement::Position::setPositionX(float x) {
    this->_position = std::make_tuple(x, std::get<1>(this->_position),std::get<2>(this->_position));
}

void Indie::movement::Position::setPositionY(float y) {
    this->_position = std::make_tuple(std::get<0>(this->_position), y, std::get<2>(this->_position));
}

void Indie::movement::Position::setPositionZ(float z) {
    this->_position = std::make_tuple(std::get<0>(this->_position), std::get<1>(this->_position),z);
}

