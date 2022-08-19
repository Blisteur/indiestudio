/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

Indie::entity::Wall::Wall(std::size_t game_id) : AEntity(2, game_id, 0){
    this->health = 100;
}
