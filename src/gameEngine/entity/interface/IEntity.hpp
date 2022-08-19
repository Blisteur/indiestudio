/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** IEntity.hpp
*/

#pragma once

#include "iostream"
#include <memory>
#include "../../movement/MovementManager.hpp"

namespace Indie {
    class GameEngine;
    class IEntity {
    public:
        virtual ~IEntity() = default;

        virtual bool hasDisplayName() const = 0;
        virtual void isDisplayName(bool display) = 0;

        virtual std::size_t getEntityID() const = 0;
        virtual std::size_t getEntityGameID() const = 0;
        virtual std::string getEntityName() const = 0;
        virtual movement::Position &getEntityPosition() = 0;
        virtual int getHealth() const = 0;
        virtual float getSpeed() const = 0;
        virtual std::size_t getDamage() const = 0;
        virtual std::size_t getData() const = 0;
        virtual bool entityInteract(std::list<std::shared_ptr<Indie::IEntity>> &list) = 0;

        virtual void setName(std::string &name) = 0;
        virtual void setPosition(Indie::movement::Position &position) = 0;
        virtual void setHealth( int health) = 0;
        virtual void setDamage(std::size_t damage) = 0;
        virtual void setData(long long data) = 0;
        virtual void setSpeed(float speed) = 0;
    protected:
        std::size_t entityID;
        long unsigned entityGameID;
        std::string entityName;
        bool displayName;
        int health;
        float speed;
        std::size_t damage;
        long long data;
    };
}
