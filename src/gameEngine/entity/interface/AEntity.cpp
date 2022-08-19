/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

Indie::AEntity::AEntity(std::size_t entityID, std::size_t entityGameID,
float speed) : entityPosition() {
    this->entityID = entityID;
    this->entityGameID = entityGameID;
    this->displayName = false;
    this->entityName = "_default_name";
    this->health = 0;
    this->speed = speed;
    this->damage = 0;
    this->data = 0;
}

std::size_t Indie::AEntity::getEntityID() const
{
    return (this->entityID);
}

std::size_t Indie::AEntity::getEntityGameID() const
{
    return (this->entityGameID);
}

std::string Indie::AEntity::getEntityName() const
{
    return (this->entityName);
}

Indie::movement::Position &Indie::AEntity::getEntityPosition()
{
    return (this->entityPosition);
}

bool Indie::AEntity::hasDisplayName() const
{
    return (this->displayName);
}

int Indie::AEntity::getHealth() const
{
    return (this->health);
}

float Indie::AEntity::getSpeed() const
{
    return this->speed;
}

void Indie::AEntity::setName(std::string &name)
{
    this->entityName = name;
}

void Indie::AEntity::setPosition(Indie::movement::Position &position)
{
    this->entityPosition = position;
}

void Indie::AEntity::isDisplayName(bool display)
{
    this->displayName = display;
}

void Indie::AEntity::setHealth(int health)
{
    this->health = health;
}

size_t Indie::AEntity::getDamage() const {
    return this->damage;
}

size_t Indie::AEntity::getData() const {
    return this->data;
}

void Indie::AEntity::setDamage(std::size_t damage) {
    this->damage = damage;
}

bool Indie::AEntity::entityInteract(std::list<std::shared_ptr<IEntity>> &list) {
    (void)list;
    return true;
}

void Indie::AEntity::setData(long long data) {
    this->data = data;
}

void Indie::AEntity::setSpeed(float speed) {
    this->speed = speed;
}
