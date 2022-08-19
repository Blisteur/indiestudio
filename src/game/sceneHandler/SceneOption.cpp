/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneOption
*/

#include "SceneOption.hpp"
#include "./OptionScenes/SceneAudio.hpp"
#include "./OptionScenes/SceneController.hpp"
#include "./OptionScenes/SceneCredits.hpp"
#include "./OptionScenes/SceneHTP.hpp"
#include "./OptionScenes/SceneKeyboard.hpp"
#include "./OptionScenes/SceneProfil.hpp"
#include "./OptionScenes/SceneSettings.hpp"
#include "../Assets.hpp"

Indie::game::sceneHandler::SceneOption::SceneOption(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_AUDIO, encapsulation::raylib::Rectangle(200, 200, 332, 301), encapsulation::raylib::Rectangle(4, 6, 332, 301), encapsulation::raylib::Rectangle(344, 0, 341, 311))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_OPTIONS, encapsulation::raylib::Rectangle(600, 200, 332, 301), encapsulation::raylib::Rectangle(4, 6, 332, 301), encapsulation::raylib::Rectangle(344, 0, 341, 311))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_CONTROLLER, encapsulation::raylib::Rectangle(1000, 200, 332, 301), encapsulation::raylib::Rectangle(4, 6, 332, 301), encapsulation::raylib::Rectangle(344, 0, 341, 311))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_KEYBOARD, encapsulation::raylib::Rectangle(1400, 200, 332, 301), encapsulation::raylib::Rectangle(4, 6, 332, 301), encapsulation::raylib::Rectangle(344, 0, 341, 311))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_PROFIL, encapsulation::raylib::Rectangle(100, 600, 299, 270), encapsulation::raylib::Rectangle(4, 6, 299, 270), encapsulation::raylib::Rectangle(312, 0, 310, 280))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_HTP, encapsulation::raylib::Rectangle(450, 600, 299, 270), encapsulation::raylib::Rectangle(4, 6, 299, 270), encapsulation::raylib::Rectangle(312, 0, 310, 280))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_ASSISTANCE, encapsulation::raylib::Rectangle(800, 600, 299, 270), encapsulation::raylib::Rectangle(4, 6, 299, 270), encapsulation::raylib::Rectangle(312, 0, 310, 280))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_CREDITS, encapsulation::raylib::Rectangle(1150, 600, 299, 270), encapsulation::raylib::Rectangle(4, 6, 299, 270), encapsulation::raylib::Rectangle(312, 0, 310, 280))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(BUTTONS_EXIT, encapsulation::raylib::Rectangle(1500, 600, 299, 270), encapsulation::raylib::Rectangle(4, 6, 299, 270), encapsulation::raylib::Rectangle(312, 0, 310, 280))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
}

Indie::game::sceneHandler::SceneOption::~SceneOption()
{
}

void Indie::game::sceneHandler::SceneOption::update()
{

}

void Indie::game::sceneHandler::SceneOption::draw()
{
    encapsulation::raylib::Mouse mouse;
    encapsulation::raylib::Keyboard kb;

    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
    this->_sceneHandler.getWindow().endDrawing();

    if (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneAudio(this->_sceneHandler)));
        }
    if (this->_buttonList[1]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneSettings(this->_sceneHandler)));
    }
    if (this->_buttonList[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneController(this->_sceneHandler)));
    }
    if (this->_buttonList[3]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneKeyboard(this->_sceneHandler)));
    }
    if (this->_buttonList[4]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneProfil(this->_sceneHandler)));
    }
    if (this->_buttonList[5]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneHTP(this->_sceneHandler)));
    }
    if (this->_buttonList[6]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (system("chrome https://github.com/AntoineGsr/Indie-Studio-Epitech") != 0)
            system("firefox https://github.com/AntoineGsr/Indie-Studio-Epitech");
    }
    if (this->_buttonList[7]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneCredits(this->_sceneHandler)));
    }
    if (this->_buttonList[8]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.stopSceneLoop();
    }
    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[9]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler.popScene();
    }
}
