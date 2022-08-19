/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneMain
*/

#pragma once

#include "AScene.hpp"
#include "../../raylib/camera/Camera3D.hpp"
#include "../Models/ModelMenu.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneMain : public AScene {
                public:
                    SceneMain(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneMain();
                    void update();
                    void draw();
                protected:
                private:
                    encapsulation::raylib::Camera3D _camera = encapsulation::raylib::Camera3D({-7, 5, 0}, {0, 2, 0}, {0, 2, 0}, 45, CAMERA_PERSPECTIVE);
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<Indie::game::ModelMenu>> _modelList;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
                    int nbPlayer = 1;
            };
        }
    }
}