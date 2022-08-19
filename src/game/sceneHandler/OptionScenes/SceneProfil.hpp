/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneProfil
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneProfil : public AScene {
                public:
                    SceneProfil(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneProfil();
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
