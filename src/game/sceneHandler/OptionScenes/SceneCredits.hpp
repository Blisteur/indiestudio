/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneCredits
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneCredits : public AScene {
                public:
                    SceneCredits(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneCredits();
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
