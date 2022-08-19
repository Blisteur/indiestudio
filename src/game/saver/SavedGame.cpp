/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SavedGame
*/

#include "SavedGame.hpp"

std::list<std::shared_ptr<SavedEntity>>& Indie::SavedGame::getEntityList()
{
    return this->_entityList;
}

void Indie::SavedGame::transformEntity(std::list<std::shared_ptr<IEntity>> &entityList)
{
    for (auto &entity : entityList) {
        this->_entityList.push_back(std::make_unique<SavedEntity>(SavedEntity(entity)));
    }
}