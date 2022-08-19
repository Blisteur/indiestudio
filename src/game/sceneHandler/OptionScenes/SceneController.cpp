/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneController
*/

#include "SceneController.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneController::SceneController(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SETTINGS)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(CONTROLLER_CONTROLLER)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
}

Indie::game::sceneHandler::SceneController::~SceneController()
{

}

void Indie::game::sceneHandler::SceneController::update()
{

}

void Indie::game::sceneHandler::SceneController::draw()
{
    encapsulation::raylib::Keyboard kb;
    encapsulation::raylib::Mouse mouse;

    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(0, 0, WHITE);
        this->_texture[1]->drawTexture(50, 70, WHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
    this->_sceneHandler.getWindow().endDrawing();
    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)))
        this->_sceneHandler.popScene();
}