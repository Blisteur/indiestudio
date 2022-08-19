/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneHandler
*/

#include "SceneHandler.hpp"

Indie::game::sceneHandler::SceneHandler::SceneHandler()
{
    
    _deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    _lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    _loaded = false;
}

Indie::game::sceneHandler::SceneHandler::~SceneHandler()
{
    this->_scenes.clear();
    this->_background.reset();
}

void Indie::game::sceneHandler::SceneHandler::pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene> scene)
{
    this->_isRunning = true;
    this->_scenes.push_front(std::move(scene));
}

void Indie::game::sceneHandler::SceneHandler::gameLoop()
{
    _deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (; _deltaTime >= _lastTime + 33; _lastTime += 33) {
        this->_scenes.front()->update();
        if (this->_loaded)
            this->updateBackground();
        this->_scenes.front()->draw();
    }
}

void Indie::game::sceneHandler::SceneHandler::popScene()
{
    this->_scenes.pop_front();
    if (this->_scenes.empty())
        this->_isRunning = false;
}

void Indie::game::sceneHandler::SceneHandler::stopSceneLoop()
{
    this->_isRunning = false;
}

bool Indie::game::sceneHandler::SceneHandler::getStatus() const
{
    return this->_isRunning;
}

encapsulation::raylib::Window& Indie::game::sceneHandler::SceneHandler::getWindow()
{
    return this->_window;
}

void Indie::game::sceneHandler::SceneHandler::setWindow(encapsulation::raylib::Window& window)
{
    this->_window = window;
}

void Indie::game::sceneHandler::SceneHandler::setBckRect(encapsulation::raylib::Rectangle rect)
{
    _rect = rect;
}

void Indie::game::sceneHandler::SceneHandler::updateBackground()
{
    this->_background->drawTextureRec(this->_rect, {0, 0}, WHITE);
    this->_background->drawTextureTiled(this->_rect, {0, 0, 2400, 6480}, {0, 0}, 0, 4, WHITE);

    encapsulation::raylib::Rectangle rect(_rect.x + BCK_WIDTH, _rect.y, _rect.width, _rect.height);

    if (rect.x > (BCK_MAX_WIDTH - BCK_WIDTH)) {
        rect.y += BCK_HEIGHT;
        rect.x = 0;
    }
    if (rect.y > (BCK_MAX_HEIGHT - BCK_HEIGHT)) {
        rect.x = 0;
        rect.y = 0;
    }
    setBckRect(rect);
}
