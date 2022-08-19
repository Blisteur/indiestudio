/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneOption
*/

#pragma once

#include "AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneOption : public AScene {
                public:
                    SceneOption(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneOption();
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