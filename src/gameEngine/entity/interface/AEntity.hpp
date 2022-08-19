/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** AEntity.hpp
*/

#pragma once

#include "IEntity.hpp"

namespace Indie {
    class AEntity : public IEntity {

    public:
        AEntity(std::size_t entityID, std::size_t entityGameID,
                float speed);
        ~AEntity() override = default;

        bool hasDisplayName() const override;
        void isDisplayName(bool display) override;

        size_t getDamage() const override;
        void setDamage(std::size_t damage) override;

        size_t getData() const override;
        std::size_t getEntityID() const override;
        size_t getEntityGameID() const override;
        std::string getEntityName() const override;
        Indie::movement::Position &getEntityPosition() override;
        int getHealth() const override;
        float getSpeed() const override;

                /* All setters */
        void setName(std::string &name) override;
        void setPosition(movement::Position &position) override;
        void setHealth(int health) override;
        void setData(long long data) override;
        bool entityInteract(std::list<std::shared_ptr<IEntity>> &list) override;

        void setSpeed(float speed) override;

    protected:
        movement::Position entityPosition;
    };
};
