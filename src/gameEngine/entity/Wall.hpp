/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Wall.hpp
*/

#include "interface/AEntity.hpp"

#ifndef BOMBERMAN_WALL_HPP
#define BOMBERMAN_WALL_HPP

namespace Indie {
    namespace entity {
        class Wall : public AEntity {
        public:
            Wall(std::size_t game_id);
        };
    }
}

#endif //BOMBERMAN_WALL_HPP
