/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneCreate
*/

#pragma once

#include "AScene.hpp"
#include "../../gameEngine/GameEngine.hpp"
#include "../../gameEngine/Generator.hpp"
#include "../../raylib/camera/Camera3D.hpp"
#include "../../raylib/vector/Vector3.hpp"
#include "../../raylib/model/Model.hpp"
#include "../../raylib/model/ModelAnimation.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneGame : public AScene {
                public:
                    SceneGame(Indie::game::sceneHandler::SceneHandler &sceneHandler, int players);
                    SceneGame(Indie::game::sceneHandler::SceneHandler &sceneHandler, int players, std::string path);
                ~SceneGame();
                    void update();
                    void draw();
                protected:
                private:
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;

                    encapsulation::raylib::Camera3D camera = encapsulation::raylib::Camera3D((encapsulation::raylib::Vector3){16.0f, 23.0f, 22.0f}, (encapsulation::raylib::Vector3){16.0f, 0.0f, 8.0f}, (encapsulation::raylib::Vector3){0.0f, 1.0f, 0.0f}, 45.0f, CAMERA_PERSPECTIVE);
                    Indie::GameEngine gameEngine;

                    std::unique_ptr<encapsulation::raylib::Model> ground;
                    std::unique_ptr<encapsulation::raylib::Model> wall;
                    std::unique_ptr<encapsulation::raylib::Model> box;

                    int playerCount;
                    int frameCounter;
                    long long updateTimeIA;
                    std::string _savePath;
                    std::vector<std::pair<std::unique_ptr<encapsulation::raylib::Model>, std::unique_ptr<encapsulation::raylib::ModelAnimation>>> playersModel;
                    std::list<std::unique_ptr<encapsulation::raylib::Texture2D>> textureList;
                    float _scale_model;
            };
        }
    }
}