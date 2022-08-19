/*
** EPITECH PROJECT, 2022
**Indie
** File description:
** GameEngine.cpp
*/

#include "GameEngine.hpp"
#include "entity/Player.hpp"
#include "entity/Ground.hpp"
#include "entity/Wall.hpp"
#include "entity/Box.hpp"
#include "entity/IaPlayer.hpp"
#include <cmath>
#include <chrono>
#include <thread>

std::shared_ptr<Indie::IEntity>Indie::GameEngine::getEntityByGameID(unsigned long entityGameID) {
    for (auto &value : this->registeredEntity) {
        if (value->getEntityGameID() == entityGameID) {
            return value;
        }
    }
    return nullptr;
}

bool Indie::GameEngine::registerNewEntity(int entityID, std::size_t gameID) {
    std::string name = "_need_username_";
    for (const auto &value : registeredEntity) {
        if (value->getEntityGameID() == gameID) return false;
    }
    switch (entityID) {
        case 1:
            registeredEntity.push_back(std::make_unique<entity::Ground>(entity::Ground(gameID)));
            break;
        case 2:
            registeredEntity.push_back(std::make_unique<entity::Wall>(entity::Wall(gameID)));
            break;
        case 3:
            registeredEntity.push_back(std::make_unique<entity::Box>(entity::Box(gameID)));
            break;
        case 7:
            registeredEntity.push_back(std::make_unique<entity::Player>(entity::Player(gameID, name)));
            break;
        case 8:
            registeredEntity.push_back(std::make_unique<entity::IAPlayer>(entity::IAPlayer(gameID)));
            break;
        default:
            break;

    }
    return true;
}

void Indie::GameEngine::updatePosition(Indie::movement::InputDictionary input, std::shared_ptr<IEntity> entity) {
    std::tuple<float, float, float> position = entity->getEntityPosition().getPosition();
    float x = std::get<0>(position);
    float y = std::get<1>(position);
    float z = std::get<2>(position);

    float ox = x;
    float oz = z;

    switch (input) {
        case movement::UP:
            z -= entity->getSpeed();
            break;
        case movement::DOWN:
            z += entity->getSpeed();
            break;
        case movement::LEFT:
            x -= entity->getSpeed();
            break;
        case movement::RIGHT:
            x += entity->getSpeed();
            break;
    }
    std::shared_ptr<IEntity> tmp = getEntityAtLocation((x >= ox ? std::ceil(x) : std::floor(x)), y, (z >= oz ? std::ceil(z) : std::floor(z)), entity);
    if (tmp != nullptr) {
        return;
    }
    entity->getEntityPosition().setPosition(x, y, z);
}

std::shared_ptr<Indie::IEntity> Indie::GameEngine::getEntityAtLocation(int _x, int _y, int _z, const std::shared_ptr<IEntity>& origin){
    (void)_y;
    for (auto &value : registeredEntity) {
        if (value->getEntityID() == 1 || value->getHealth() == -1) continue;
        if (value->getEntityGameID() == origin->getEntityGameID()) continue;
        if (origin->getData() != 789654123 && value->getEntityGameID() != origin->getData()) origin->setData(789654123);
        std::tuple<float, float, float> position = value->getEntityPosition().getPosition();
        int x = std::get<0>(position);
        int z = std::get<2>(position);
        if (_x == x && z == _z) return value;
    }
    return nullptr;
}

Indie::GameEngine::GameEngine() {
}

std::list<std::shared_ptr<Indie::IEntity>> &Indie::GameEngine::getEntityList() {
    return this->registeredEntity;
}

void Indie::GameEngine::convertMapToEntity(std::vector<std::vector<Indie::engine::Map>> map) {
    int line = 0;
    int column;
    for (const std::vector<Indie::engine::Map>& first : map) {
        column = 0;
        for (const Indie::engine::Map& cell : first) {
            int size = registeredEntity.size();
            if (cell.getType() == "EMPTY") {
                registerNewEntity(1, size);
            } else if (cell.getType() == "WALL") {
                registerNewEntity(2, size);
            } else if (cell.getType() == "BOX") {
                registerNewEntity(3, size);
            }
            getEntityByGameID(size)->getEntityPosition().setPosition(column, 0, line);
            column++;
        }
        line ++;
    }
}

void Indie::GameEngine::updateAI() {
    std::vector<std::vector<char>> map;
    std::list<std::tuple<float, float, float>> bomb;
    for (int i = 0; i != 17; i++) {
        std::vector<char> vector;
        for (int j = 0; j != 33; j++)
            vector.push_back('.');
        map.push_back(vector);
    }
    for (auto &ia: registeredEntity) {
        if (ia->getEntityID() != 8)
            continue;
        for (auto &entity: registeredEntity) {
            int identifier = entity->getEntityID();
            int x = std::floor(entity->getEntityPosition().getPositionX());
            int z = std::floor(entity->getEntityPosition().getPositionZ());
            switch (identifier) {
                case 1:
                    map[z][x] = '.';
                    break;
                case 2:
                    map[z][x] = 'I';
                    break;
                case 3:
                    if (entity->getHealth() == -1)
                        map[z][x] = '.';
                    else
                        map[z][x] = 'X';
                    break;
                case 4:
                    if (entity->getHealth() == -1)
                        break;
                    map[z][x] = 'B';
                    bomb.push_back(std::make_tuple(x, z, entity->getDamage()));
                    break;
                case 7:
                    if (entity->getHealth() == -1)
                        break;
                    map[z][x] = 'E';
                    break;
                case 8:
                    if (entity->getHealth() == -1)
                        break;
                    if (entity->getEntityGameID() == ia->getEntityGameID())
                        map[z][x] = 'P';
                    else
                        map[z][x] = 'E';
                    break;
                default:
                    break;
            }
        }
        Indie::gameEngine::Ia ia_player(std::make_pair(ia->getEntityPosition().getPositionX(), ia->getEntityPosition().getPositionZ()), map, bomb);
        if (ia_player.getWillBombBePlaced()) {
            ia->entityInteract(getEntityList());
            ia->getEntityPosition().setPosition(
                std::get<0>(ia_player.getPlayerPos()), 0,
                std::get<1>(ia_player.getPlayerPos()));
            return;
        }
        ia->getEntityPosition().setPosition(
            std::get<0>(ia_player.getGoalPos()), 0,
            std::get<1>(ia_player.getGoalPos()));
    }
}

void Indie::GameEngine::updateBomb() {
    for (const auto &entity : registeredEntity) {
        if (entity->getEntityGameID() == 4) {
            entity->entityInteract(registeredEntity);
        }
    }
}

bool Indie::GameEngine::containBomb() {
    for (const auto &entity : registeredEntity) {
        if (entity->getEntityID() == 4) if (entity->getHealth() >= 0) return true;
    }
    return false;
}

void Indie::GameEngine::flushEntity() {
    std::shared_ptr<IEntity> rm = nullptr;
    for (auto &entity : registeredEntity) {
        if (entity->getHealth() <= -1) {
            rm = entity;
            break;
        }
    }
    rm.reset();
    if (rm != nullptr) {
        flushEntity();
    }
}

bool Indie::GameEngine::registerNewEntity(std::size_t entityID, std::size_t gameID, int health, float speed, std::size_t damage, std::size_t data, float x, float y, float z) {
    if (!registerNewEntity(entityID, gameID)) return false;
    std::shared_ptr<Indie::IEntity> entity = getEntityByGameID(gameID);
    if (entity == nullptr) return false;
    entity->setHealth(health);
    entity->setSpeed(speed);
    entity->setDamage(damage);
    entity->getEntityPosition().setPosition(x, y, z);
    entity->setData(data);
    return true;
}
