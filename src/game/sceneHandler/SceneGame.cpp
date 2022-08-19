/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneGame
*/

#include "SceneGame.hpp"
#include "../../gameEngine/Generator.hpp"
#include "../../raylib/keyboard/Keyboard.hpp"
#include "../saver/Saver.hpp"
#include "../saver/SavedGame.hpp"
#include <filesystem>

Indie::game::sceneHandler::SceneGame::SceneGame(Indie::game::sceneHandler::SceneHandler &sceneHandler, int players, std::string path): AScene(sceneHandler), gameEngine()
{
    Indie::Saver saver;
    Indie::SavedGame savedGame;

    this->_savePath = path;
    this->frameCounter = 0;

    saver.loadConfig<Indie::SavedGame>(savedGame, path);

    for (std::shared_ptr<SavedEntity> &entity : savedGame.getEntityList()) {
        gameEngine.registerNewEntity(entity.get()->_entityID, entity.get()->_entityGameID, entity.get()->_health, entity.get()->_speed, entity.get()->_damage, entity.get()->_data, entity.get()->_x, entity.get()->_y, entity.get()->_z);
    }

    this->playerCount = players;
    std::string rand_floor_model = BLOCK_FLOOR_MODEL;
    std::string rand_floor_texture = BLOCK_FLOOR_TEXTURE;
    this->_scale_model = 1.0f;
    if (rand() % 2) {
        rand_floor_model = BLOCK_FLOOR2_MODEL;
        rand_floor_texture = BLOCK_FLOOR2_TEXTURE;
        this->_scale_model = 0.005f;
    }
    this->ground = std::make_unique<encapsulation::raylib::Model>(rand_floor_model);
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>(rand_floor_texture));
    this->ground->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->wall = std::make_unique<encapsulation::raylib::Model>("assets/models/solidBlock/block.obj");
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/models/solidBlock/brick.png"));
    this->wall->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->box = std::make_unique<encapsulation::raylib::Model>("assets/models/solidBlock/block.obj");
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/models/woodBlock/wood.png"));
    this->box->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->updateTimeIA = 0;

    for (auto &entity : gameEngine.getEntityList()) {
        if (entity->getEntityID() != 7) continue;
        this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/textures/characters/purple.png"));
        this->playersModel.push_back(std::make_pair(std::make_unique<encapsulation::raylib::Model>("bl.iqm"), std::make_unique<encapsulation::raylib::ModelAnimation>()));
        playersModel.back().second->loadModelAnimations("bl.iqm", 0);
        playersModel.back().second->updateModelAnimation(*playersModel.back().first, this->frameCounter);
        playersModel.back().first->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());
        playersModel.back().first->transform = MatrixRotateXYZ({DEG2RAD * 90, DEG2RAD * 90, 0});
    }
}

Indie::game::sceneHandler::SceneGame::SceneGame(Indie::game::sceneHandler::SceneHandler &sceneHandler, int players): AScene(sceneHandler), gameEngine()
{
    this->playerCount = players;
    this->frameCounter = 0;

    std::string rand_floor_model = BLOCK_FLOOR_MODEL;
    std::string rand_floor_texture = BLOCK_FLOOR_TEXTURE;
    this->_scale_model = 1.0f;
    if (rand() % 2) {
        rand_floor_model = BLOCK_FLOOR2_MODEL;
        rand_floor_texture = BLOCK_FLOOR2_TEXTURE;
        this->_scale_model = 0.005f;
    }
    this->ground = std::make_unique<encapsulation::raylib::Model>(rand_floor_model);
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>(rand_floor_texture));
    this->ground->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->wall = std::make_unique<encapsulation::raylib::Model>("assets/models/solidBlock/block.obj");
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/models/solidBlock/brick.png"));
    this->wall->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->box = std::make_unique<encapsulation::raylib::Model>("assets/models/solidBlock/block.obj");
    this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/models/woodBlock/wood.png"));
    this->box->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());

    this->updateTimeIA = 0;

    Indie::Generator generator;
    this->gameEngine.convertMapToEntity(generator.getMap());

    for (int i = 0; i < players; i++) {
        this->textureList.push_front(std::make_unique<encapsulation::raylib::Texture2D>("assets/textures/characters/purple.png"));
        this->playersModel.push_back(std::make_pair(std::make_unique<encapsulation::raylib::Model>("bl.iqm"), std::make_unique<encapsulation::raylib::ModelAnimation>()));
        playersModel.back().second->loadModelAnimations("bl.iqm", 0);
        playersModel.back().second->updateModelAnimation(*playersModel.back().first, this->frameCounter);
        playersModel.back().first->setMaterial(MATERIAL_MAP_DIFFUSE, *this->textureList.front());
        playersModel.back().first->transform = MatrixRotateXYZ({DEG2RAD * 90, DEG2RAD * 90, 0});
        this->gameEngine.registerNewEntity(7, 8000 + i);
        std::shared_ptr<IEntity> player = this->gameEngine.getEntityByGameID(8000 + i);
        switch (i) {
            case 0:
                player->getEntityPosition().setPosition(1, 0, 1);
                break;
            default:
                break;
        }
    }
}

Indie::game::sceneHandler::SceneGame::~SceneGame()
{
    Indie::Saver saver;
    Indie::SavedGame savedGame;

    if(std::filesystem::is_directory("saves") == false)
        std::filesystem::create_directories("saves");
    std::string tmpPath = "saves/";
    int nbSave = std::distance(std::filesystem::directory_iterator("saves"), std::filesystem::directory_iterator{});

    savedGame.transformEntity(this->gameEngine.getEntityList());
    if (this->_savePath.size() != 0) {
        tmpPath += std::to_string(std::atoi(this->_savePath.c_str()));
        std::filesystem::remove(tmpPath);
    } else
        tmpPath += std::to_string(nbSave);
    saver.saveConfig<Indie::SavedGame>(savedGame, tmpPath);
}

void Indie::game::sceneHandler::SceneGame::update()
{
    encapsulation::raylib::Keyboard kb;
    Indie::game::inputHandler::PlayersInputs player0(std::list<int>({
        this->_sceneHandler._config.entity0_up,
        this->_sceneHandler._config.entity0_down,
        this->_sceneHandler._config.entity0_left,
        this->_sceneHandler._config.entity0_right,
        this->_sceneHandler._config.entity0_place,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    Indie::game::inputHandler::PlayersInputs player1(std::list<int>({
        this->_sceneHandler._config.entity1_up,
        this->_sceneHandler._config.entity1_down,
        this->_sceneHandler._config.entity1_left,
        this->_sceneHandler._config.entity1_right,
        this->_sceneHandler._config.entity1_place,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    Indie::game::inputHandler::PlayersInputs player2(std::list<int>({
        this->_sceneHandler._config.entity2_up,
        this->_sceneHandler._config.entity2_down,
        this->_sceneHandler._config.entity2_left,
        this->_sceneHandler._config.entity2_right,
        this->_sceneHandler._config.entity2_place,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    Indie::game::inputHandler::PlayersInputs player3(std::list<int>({
        this->_sceneHandler._config.entity3_up,
        this->_sceneHandler._config.entity3_down,
        this->_sceneHandler._config.entity3_left,
        this->_sceneHandler._config.entity3_right,
        this->_sceneHandler._config.entity3_place,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    std::list<Indie::game::inputHandler::PlayersInputs> playerInputList;
    playerInputList.push_front(player3);
    playerInputList.push_front(player2);
    playerInputList.push_front(player1);
    playerInputList.push_front(player0);
    std::list<std::pair<int, int>> engineInputsConvert;
    Indie::game::InputHandler inputsPlayers(playerInputList);
    std::list<std::tuple<int, int, int>> tmpInputs = inputsPlayers.update();
    std::list<std::tuple<int, int, int>>::iterator itr;

    for (itr = tmpInputs.begin(); itr != tmpInputs.end(); ++itr) {
        if (std::get<2>(*itr) == Indie::game::inputHandler::PlayersInputs::KeyMode::KEY_DOWN) {
            if (std::get<0>(*itr) == 0) {
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity0_up)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::UP, this->gameEngine.getEntityByGameID(8000));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity0_down)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::DOWN, this->gameEngine.getEntityByGameID(8000));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity0_left)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::LEFT, this->gameEngine.getEntityByGameID(8000));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity0_right)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::RIGHT, this->gameEngine.getEntityByGameID(8000));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity0_place)
                    this->gameEngine.getEntityByGameID(8000).get()->entityInteract(this->gameEngine.getEntityList());
            }
            if (std::get<0>(*itr) == 1 && this->playerCount >= 2) {
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity1_up)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::UP, this->gameEngine.getEntityByGameID(8001));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity1_down)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::DOWN, this->gameEngine.getEntityByGameID(8001));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity1_left)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::LEFT, this->gameEngine.getEntityByGameID(8001));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity1_right)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::RIGHT, this->gameEngine.getEntityByGameID(8001));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity1_place)
                    this->gameEngine.getEntityByGameID(8001).get()->entityInteract(this->gameEngine.getEntityList());
            }
            if (std::get<0>(*itr) == 2 && this->playerCount >= 3) {
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity2_up)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::UP, this->gameEngine.getEntityByGameID(8002));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity2_down)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::DOWN, this->gameEngine.getEntityByGameID(8002));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity2_left)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::LEFT, this->gameEngine.getEntityByGameID(8002));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity2_right)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::RIGHT, this->gameEngine.getEntityByGameID(8002));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity2_place)
                    this->gameEngine.getEntityByGameID(8002).get()->entityInteract(this->gameEngine.getEntityList());
            }
            if (std::get<0>(*itr) == 3 && this->playerCount >= 4) {
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity3_up)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::UP, this->gameEngine.getEntityByGameID(8003));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity3_down)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::DOWN, this->gameEngine.getEntityByGameID(8003));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity3_left)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::LEFT, this->gameEngine.getEntityByGameID(8003));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity3_right)
                    this->gameEngine.updatePosition(Indie::movement::InputDictionary::RIGHT, this->gameEngine.getEntityByGameID(8003));
                if (std::get<1>(*itr) == this->_sceneHandler._config.entity3_place)
                    this->gameEngine.getEntityByGameID(8003).get()->entityInteract(this->gameEngine.getEntityList());
            }
        }
    }
    for (auto &pl : this->playersModel) {
        pl.second->updateModelAnimation(*pl.first, this->frameCounter);
    }
    this->frameCounter += 1;
    if ((int)this->frameCounter >= this->playersModel.front().second.get()[this->playersModel.front().second->getModelAnimation()].frameCount)
        this->frameCounter = 0;
    if (kb.isKeyPressed(KEY_ESCAPE)) {
        this->_sceneHandler.popScene();
    }
}

void Indie::game::sceneHandler::SceneGame::draw()
{
    this->camera.update();
    this->_sceneHandler.getWindow().beginDrawing();

    this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
    this->gameEngine.flushEntity();
    camera.beginMode3D();
    long long actual = time(nullptr);
    if (this->updateTimeIA == 0 || this->updateTimeIA <= actual) {
        this->updateTimeIA = time(nullptr);
        gameEngine.updateAI();
    }
    for (float i = 0.0f; i != 17.0f; i += 1.0f) {
        for (float j = 0.0f; j != 33.0f; j += 1.0f) {
            this->ground->drawModel(Vector3{j, 0, i}, this->_scale_model, WHITE);
        }
    }
    for (const auto &entity: this->gameEngine.getEntityList()) {
        if (entity->getHealth() == -1) {
            continue;
        }
        Vector3 pos_entity = {
            entity->getEntityPosition().getPositionX(), 1.0f,
            entity->getEntityPosition().getPositionZ()};
        if (entity->getEntityID() == 1) {
            continue;
        } else if (entity->getEntityID() == 2) {
            this->wall->drawModel(pos_entity, 1.2f, WHITE);
        } else if (entity->getEntityID() == 3) {
            this->box->drawModel(pos_entity, 1.1f, WHITE);
        } else if (entity->getEntityID() == 4) {
            //                    DrawModel(block_box, pos_entity, 1, WHITE);
            entity->entityInteract(this->gameEngine.getEntityList());
        } else if (entity->getEntityID() == 7) {
            playersModel[0].first->drawModel(pos_entity, 1, WHITE);
        } else if (entity->getEntityID() == 8) {
            playersModel[0].first->drawModel(pos_entity, 1, WHITE);
        }
    }
    camera.endMode3D();
    this->_sceneHandler.getWindow().endDrawing();
}
