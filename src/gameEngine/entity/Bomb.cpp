/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bomb.cpp
*/

#include "Bomb.hpp"
#include <cmath>

Indie::entity::Bomb::Bomb(std::size_t game_id, std::size_t damage, std::size_t x, std::size_t z)
: AEntity(4, game_id, 0) {
    this->damage = damage;
    this->getEntityPosition().setPosition(x, 0, z);
    this->data = time(nullptr) + 3;
    this->health = 1;
}

bool
Indie::entity::Bomb::entityInteract(std::list<std::shared_ptr<IEntity>> &list) {
    std::time_t actual = time(nullptr);

    if (actual >= this->data) {
        std::cout << "Explode " << std::endl;
        this->health = -1;
        bool finished = false;
        float x = this->getEntityPosition().getPositionX();
        float z = this->getEntityPosition().getPositionZ();

        /** check down **/
        for (std::size_t i = z; i >= z - damage; i--) {
            if (finished) break;
            for (auto &entity : list) {
                explodeBomb(list, finished, x, i, entity);
            }
        }
        /** check up **/
        finished = false;
        for (std::size_t i = z; i <= z + damage; i++) {
            if (finished) break;
            for (auto &entity : list) {
                explodeBomb(list, finished, x, i, entity);
            }
        }

        /** check left **/
        finished = false;
        for (std::size_t i = x; i <= x + damage; i++) {
            if (finished) break;
            for (auto &entity : list) {
                explodeBomb(list, finished, i, z, entity);
            }
        }

        /** check right **/
        finished = false;
        for (std::size_t i = x; i <= x - damage; i--) {
            if (finished) break;
            for (auto &entity : list) {
                explodeBomb(list, finished, i, z, entity);
            }
        }
    }
    return true;
}

void Indie::entity::Bomb::explodeBomb(std::list<std::shared_ptr<IEntity>> &list,
                                      bool &finished, float x, float z, const std::shared_ptr<IEntity>& entity) {
    if (finished) return;
    if (entity->getEntityID() == 7 || entity->getEntityID() == 8) {
        int a_x = (int) entity->getEntityPosition().getPositionX();
        int a_z = (int) entity->getEntityPosition().getPositionZ();

        float x_ = entity->getEntityPosition().getPositionX();
        float z_ = entity->getEntityPosition().getPositionZ();

        bool _x = (float(x_ - a_x)) >= 0.8f;
        bool _z = (float(z_ - a_z)) >= 0.8f;

        if ((_x ? std::ceil(x_) : std::floor(x_)) != x) return;
        if ((_z ? std::ceil(z_) : std::floor(z_)) != z) return;
    } else {
        if (std::floor(entity->getEntityPosition().getPositionX()) != x) return;
        if (std::floor(entity->getEntityPosition().getPositionZ()) != z) return;
    }
    if (entity->getEntityGameID() == this->entityGameID) return;
    switch (entity->getEntityID()) {
        case 2:
            finished = true;
            break;
        case 3:
            entity->setHealth(-1);
            break;
        case 4:
            entity->setData(9999999999);
            entity->entityInteract(list);
            break;
        case 7:
            entity->setHealth(entity->getHealth() - 1);
            std::cout << "EN" << std::endl;
            break;
        case 8:
            entity->setHealth(entity->getHealth() - 1);
            break;
        default:
            break;
    }
}
