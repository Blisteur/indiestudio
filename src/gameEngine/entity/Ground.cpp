/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Ground.cpp
*/

#include "Ground.hpp"

Indie::entity::Ground::Ground(std::size_t game_id) : AEntity(1, game_id, 0) {
    this->damage = 0;
}
