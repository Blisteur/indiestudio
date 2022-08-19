/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneController
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneController : public AScene {
                public:
                    SceneController(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneController();
                    void update();
                    void draw();
                protected:
                private:
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
            };
        }
    }
}
