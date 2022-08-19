/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Bomb.hpp"
#include <cmath>



Indie::entity::Player::Player(std::size_t entity_game_id, std::string &name) : AEntity(7, entity_game_id, 0.1f) {
    this->entityName = name;
    this->displayName = true;
    this->damage = 1;
    this->health = 2;
    this->_bombCooldown = -1;
}

bool Indie::entity::Player::entityInteract(std::list<std::shared_ptr<IEntity>> &list) {
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
    this->data = list.size() - 1;
    return true;
}

