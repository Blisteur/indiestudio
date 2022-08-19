/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** MovementManager.hpp
*/

#pragma once

#include <list>
#include <tuple>

#ifndef Indie_MOVEMENTMANAGER_HPP
#define Indie_MOVEMENTMANAGER_HPP

namespace Indie::movement {
        class Position {
        public:
            Position(float x, float y, float z);
            Position();
            ~Position();

            void setPosition(float x, float y, float z);
            std::tuple<float, float, float> getPosition();
            float getPositionX();
            float getPositionY();
            float getPositionZ();
            void setPositionX(float x);
            void setPositionY(float y);
            void setPositionZ(float z);
        private:
            std::tuple<float, float, float> _position;
        };
        enum InputDictionary {
            UP = 1,
            DOWN = 2,
            LEFT = 3,
            RIGHT = 4
        };
    }

#endif //Indie_MOVEMENTMANAGER_HPP