/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneHTP
*/

#include "SceneHTP.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneHTP::SceneHTP(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
}

Indie::game::sceneHandler::SceneHTP::~SceneHTP()
{
}

void Indie::game::sceneHandler::SceneHTP::update()
{
}

void Indie::game::sceneHandler::SceneHTP::draw()
{
    encapsulation::raylib::Keyboard kb;
     encapsulation::raylib::Mouse mouse;

    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
    this->_sceneHandler.getWindow().endDrawing();
    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)))
        this->_sceneHandler.popScene();
}
