/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SavedEntity
*/

#include "SavedEntity.hpp"

SavedEntity::SavedEntity(std::shared_ptr<Indie::IEntity> &entity)
{
    this->_entityID = entity.get()->getEntityID();
    this->_entityGameID = entity.get()->getEntityGameID();
    this->_health = entity.get()->getHealth();
    this->_speed = entity.get()->getSpeed();
    this->_damage = entity.get()->getDamage();
    this->_data = entity.get()->getData();
    this->_x = entity.get()->getEntityPosition().getPositionX();
    this->_y = entity.get()->getEntityPosition().getPositionY();
    this->_z = entity.get()->getEntityPosition().getPositionZ();
}