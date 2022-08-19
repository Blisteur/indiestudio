/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneCredits
*/

#include "SceneCredits.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneCredits::SceneCredits(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(CREDITS_CREDITS)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SETTINGS)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_ANTOINE, encapsulation::raylib::Rectangle(350, 200, 305, 240), encapsulation::raylib::Rectangle(17, 26, 305, 240), encapsulation::raylib::Rectangle(354, 26, 305, 240))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_LUCAS, encapsulation::raylib::Rectangle(800, 200, 305, 240), encapsulation::raylib::Rectangle(17, 26, 305, 240), encapsulation::raylib::Rectangle(354, 26, 305, 240))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_NATHAN, encapsulation::raylib::Rectangle(1265, 200, 305, 240), encapsulation::raylib::Rectangle(17, 26, 305, 240), encapsulation::raylib::Rectangle(354, 26, 305, 240))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_THEO, encapsulation::raylib::Rectangle(350, 600, 305, 250), encapsulation::raylib::Rectangle(17, 26, 305, 250), encapsulation::raylib::Rectangle(354, 26, 305, 250))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_THOMAS, encapsulation::raylib::Rectangle(800, 600, 315, 240), encapsulation::raylib::Rectangle(14, 26, 325, 240), encapsulation::raylib::Rectangle(345, 26, 325, 240))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(CREDITS_PIERRICK, encapsulation::raylib::Rectangle(1265, 600, 315, 240), encapsulation::raylib::Rectangle(14, 26, 320, 240), encapsulation::raylib::Rectangle(345, 26, 320, 240))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
}

Indie::game::sceneHandler::SceneCredits::~SceneCredits()
{
}

void Indie::game::sceneHandler::SceneCredits::update()
{
    encapsulation::raylib::Keyboard kb;
    encapsulation::raylib::Mouse mouse;

    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[6]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler.popScene();
        return;
    }
}

void Indie::game::sceneHandler::SceneCredits::draw()
{
    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(0, 0, WHITE);
        this->_texture[1]->drawTexture(0, 0, WHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
    this->_sceneHandler.getWindow().endDrawing();
}