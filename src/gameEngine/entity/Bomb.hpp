/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Bomb.hpp
*/

#include "interface/AEntity.hpp"
#include <ctime>

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

namespace Indie {
    namespace entity {
        class Bomb : public AEntity{
        public:
            Bomb(std::size_t game_id, std::size_t damage, std::size_t x, std::size_t z);
            bool entityInteract(std::list<std::shared_ptr<IEntity>> &list) override;
            void explodeBomb(std::list<std::shared_ptr<IEntity>> &list, bool &finished, float x, float z, const std::shared_ptr<IEntity>& entity);
        private:
            std::time_t explode;
        };
    }
}

#endif //BOMBERMAN_BOMB_HPP
