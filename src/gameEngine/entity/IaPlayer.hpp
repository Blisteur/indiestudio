/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** IaPlayer.hpp
*/

#include "interface/AEntity.hpp"
#include <ctime>
#include "Bomb.hpp"

#ifndef BOMBERMAN_IAPLAYER_HPP
#define BOMBERMAN_IAPLAYER_HPP

namespace Indie {
    namespace entity {
        class IAPlayer : public AEntity {
        public:
            IAPlayer(std::size_t game_id);
            bool entityInteract(std::list<std::shared_ptr<IEntity>> &list) override;
            ~IAPlayer() = default;
        private:
            std::time_t _bombCooldown;
        };
    }
}

#endif //BOMBERMAN_IAPLAYER_HPP
