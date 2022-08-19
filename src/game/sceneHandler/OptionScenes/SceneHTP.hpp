/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneHTP
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneHTP : public AScene {
                public:
                    SceneHTP(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneHTP();
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
