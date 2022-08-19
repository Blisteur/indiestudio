/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SavedGame
*/


#pragma once

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "../../gameEngine/GameEngine.hpp"
#include <boost/serialization/list.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "SavedEntity.hpp"

namespace Indie {
    class SavedGame {
        public :
            SavedGame() = default;
            ~SavedGame() = default;

            void transformEntity(std::list<std::shared_ptr<IEntity>> &entityList);
            std::list<std::shared_ptr<SavedEntity>>& getEntityList();
        private :
            std::list<std::shared_ptr<SavedEntity>> _entityList;
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive &ar, const unsigned int version)
            {
                (void)version;
                ar & _entityList;
            }
        protected :
    };
};