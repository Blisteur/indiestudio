/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneSplash
*/

#include "SceneSplash.hpp"
#include "SceneMain.hpp"

Indie::game::sceneHandler::SceneSplash::SceneSplash(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_count = 0;
}

Indie::game::sceneHandler::SceneSplash::~SceneSplash()
{
}

void Indie::game::sceneHandler::SceneSplash::update()
{
    this->getCount() += 1;
    if (this->_count == 80) {
        this->_sceneHandler._rect = encapsulation::raylib::Rectangle(0,0, BCK_WIDTH, BCK_HEIGHT);
        this->_sceneHandler._background = std::make_unique<encapsulation::raylib::Texture2D>(MAIN_MENU);
    }
    if (this->_count >= 200) {
        this->_sceneHandler._loaded = true;
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneMain(this->_sceneHandler)));
    }
}

void Indie::game::sceneHandler::SceneSplash::draw()
{
    this->_sceneHandler.getWindow().beginDrawing();
    this->_sceneHandler.getWindow().clearBackground(WHITE);

    DrawRectangle(40, 900, 1920 - 80, 40, BLACK);
    DrawRectangle(45, 905, (1920 - 80) * this->_count / 200, 30, GREEN);

    this->_sceneHandler.getWindow().endDrawing();
}

int& Indie::game::sceneHandler::SceneSplash::getCount()
{
    return this->_count;
}
