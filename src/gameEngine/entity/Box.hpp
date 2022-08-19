/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Box.hpp
*/

#include "interface/AEntity.hpp"

#ifndef BOMBERMAN_BOX_HPP
#define BOMBERMAN_BOX_HPP

namespace Indie {
    namespace entity {
        class Box : public AEntity{
        public:
            Box(std::size_t game_engine);
        };
    }
}

#endif //BOMBERMAN_BOX_HPP
