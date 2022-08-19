/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** IaPlayer.cpp
*/

#include "IaPlayer.hpp"
#include <cmath>

Indie::entity::IAPlayer::IAPlayer(std::size_t game_id) : AEntity(8, game_id, 1.0f) {
    this->entityName = "_IA_PLAYER";
    this->displayName = false;
    this->damage = 2;
    this->health = 0;
    this->_bombCooldown = -1;
}

bool Indie::entity::IAPlayer::entityInteract(std::list<std::shared_ptr<IEntity>> &list) {
    if (this->_bombCooldown != -1) {
        std::time_t actual = std::time(nullptr);
        if (_bombCooldown <= actual) _bombCooldown = -1;
        else return false;
    }
    this->_bombCooldown = std::time(nullptr) + 5;
    int a_x = (int) getEntityPosition().getPositionX();
    int a_z = (int) getEntityPosition().getPositionZ();

    float x = getEntityPosition().getPositionX();
    float z = getEntityPosition().getPositionZ();

    bool _x = (float(x - a_x)) >= 0.5f;
    bool _z = (float(z - a_z)) >= 0.5f;

    list.push_back(std::make_unique<entity::Bomb>(entity::Bomb(list.size(), this->damage,
                                                               (_x ? std::ceil(x) : std::floor(x)),
                                                               (_z ? std::ceil(z) : std::floor(z)))));
    return true;
}
