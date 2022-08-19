/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Ground.hpp
*/

#include "interface/AEntity.hpp"

#ifndef BOMBERMAN_GROUND_HPP
#define BOMBERMAN_GROUND_HPP

namespace Indie {
    namespace entity {
        class Ground : public AEntity {
        public:
            Ground(std::size_t game_id);
        };
    }
}

#endif //BOMBERMAN_GROUND_HPP
