/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** Player.hpp
*/

#include "interface/AEntity.hpp"
#include <ctime>

#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

namespace Indie {
    namespace entity {
        class Player : public AEntity {
        public:
            Player(std::size_t entity_game_id, std::string &name);
            bool entityInteract(std::list<std::shared_ptr<IEntity>> &list) override;
            ~Player() = default;
        private:
            std::time_t _bombCooldown;
            std::list<std::size_t> exclusion;
        };
    }
}


#endif //BOMBERMAN_PLAYER_HPP
