/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneHandler
*/

#pragma once

#include "IScene.hpp"
#include <list>
#include <memory>
#include "../../raylib/window/Window.hpp"
#include "../../raylib/rectangle/Rectangle.hpp"
#include "../../raylib/texture/Texture2D.hpp"
#include "../../raylib/vector/Vector2.hpp"
#include "../inputHandler/InputHandler.hpp"
#include "../inputHandler/KeyBoardKeys.hpp"
#include "../Assets.hpp"
#include "../saver/Config.hpp"
#include <chrono>

#define BCK_MAX_WIDTH 2400
#define BCK_MAX_HEIGHT 6480
#define BCK_WIDTH 480
#define BCK_HEIGHT 270

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneHandler {
                public:
                    SceneHandler();
                    ~SceneHandler();
                    void gameLoop();
                    void pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene> scene);
                    void popScene();
                    void stopSceneLoop();
                    bool getStatus() const;
                    encapsulation::raylib::Window& getWindow();
                    void setWindow(encapsulation::raylib::Window& window);
                    std::unique_ptr<encapsulation::raylib::Texture2D> _background;
                    encapsulation::raylib::Rectangle _rect;
                    bool _loaded;
                    Indie::Config _config;

                protected:
                private:
                    void updateBackground();
                    void setBckRect(encapsulation::raylib::Rectangle);
                    bool _isRunning;
                    encapsulation::raylib::Window _window;
                    std::list<std::unique_ptr<Indie::game::sceneHandler::IScene>> _scenes;
                    std::uint64_t _deltaTime;
                    std::uint64_t _lastTime;
            };
        }
    }
}
