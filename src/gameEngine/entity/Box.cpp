/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Box.cpp
*/

#include "Box.hpp"

Indie::entity::Box::Box(std::size_t game_engine) : AEntity(3, game_engine, 0) {
    this->health = 10;
}
