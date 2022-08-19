/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GameEngine.hpp
*/

#pragma once

#include "map"
#include "movement/MovementManager.hpp"
#include "entity/interface/IEntity.hpp"
#include "movement/MovementManager.hpp"
#include "memory"
#include "Generator.hpp"
#include "ia/Ia.hpp"

namespace Indie {
    namespace EntityDictionary {
        enum Entity {
            PLAYER = 7,
            IAPlayer = 8
        };
    }
    class GameEngine {
    public:
        GameEngine();
        void updatePosition(movement::InputDictionary input, std::shared_ptr<IEntity> entity);
        std::shared_ptr<IEntity> getEntityAtLocation(int x, int y, int z, const std::shared_ptr<IEntity>& origin);
        void convertMapToEntity(std::vector<std::vector<Indie::engine::Map>> map);
        void updateAI();
        void updateBomb();
        bool containBomb();
        bool registerNewEntity(int entityID, std::size_t gameID);
        bool registerNewEntity(std::size_t entityID, std::size_t gameID, int health, float speed, std::size_t damage, std::size_t data,
                               float x, float y, float z);
        void flushEntity();
        std::shared_ptr<IEntity> getEntityByGameID(long unsigned entityGameID);
        std::list<std::shared_ptr<Indie::IEntity>> &getEntityList();
        ~GameEngine() = default;
    private:
        std::list<std::shared_ptr<IEntity>> registeredEntity;
    };
}
