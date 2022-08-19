/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** AScene
*/

#pragma once

#include "IScene.hpp"
#include "SceneHandler.hpp"
#include "../Button/Button.hpp"
#include "../../raylib/mouse/Mouse.hpp"
#include "../../raylib/window/Window.hpp"
#include "../../raylib/keyboard/Keyboard.hpp"
#include "../../raylib/text/Font.hpp"
#include <vector>

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class AScene : public IScene {
                public:
                    AScene(Indie::game::sceneHandler::SceneHandler &sceneHandler): _sceneHandler(sceneHandler) {};
                    virtual ~AScene() = default;
                    virtual void update() = 0;
                    virtual void draw() = 0;
                protected:
                    Indie::game::sceneHandler::SceneHandler &_sceneHandler;
                private:
            };
        }
    }
}
