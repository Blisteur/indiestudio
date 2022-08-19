/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** InputHandler
*/

#include "InputHandler.hpp"

Indie::game::InputHandler::InputHandler()
{
}

Indie::game::InputHandler::InputHandler(const std::list<Indie::game::inputHandler::PlayersInputs> &playersInputs)
{
    _playersInputs = playersInputs;
}

Indie::game::InputHandler::~InputHandler()
{
}

std::list<std::tuple<int, int, int>> Indie::game::InputHandler::update()
{
    std::list<std::tuple<int, int, int>> allInputsList;
    int x = 0;

    for (auto &inputs : _playersInputs) {
        for (auto &playersInputsList : inputs.getInputs()) {
            allInputsList.push_back(std::make_tuple(x, playersInputsList.first, playersInputsList.second));
        }
        x += 1;
    }
    return (allInputsList);
}
