/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneSplash
*/

#pragma once

#include "AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneSplash : public AScene {
                public:
                    SceneSplash(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneSplash();
                    void update();
                    void draw();
                    int& getCount();
                protected:
                private:
                    int _count;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
            };
        }
    }
}