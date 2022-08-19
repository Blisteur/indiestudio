/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** InputHandler
*/

#pragma once

#include "PlayersInputs.hpp"
#include <list>
#include <tuple>

namespace Indie {
    namespace game {
        class InputHandler {
            public:
                InputHandler();
                InputHandler(const std::list<Indie::game::inputHandler::PlayersInputs> &playersInputs);
                ~InputHandler();
                std::list<std::tuple<int, int, int>> update();

            protected:
            private:
                std::list<Indie::game::inputHandler::PlayersInputs> _playersInputs;
        };
    }
}

