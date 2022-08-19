/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneMain
*/

#include "SceneMain.hpp"
#include "SceneOption.hpp"
#include "SceneGame.hpp"
#include "SceneLoad.hpp"
#include "../Assets.hpp"

Indie::game::sceneHandler::SceneMain::SceneMain(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(MAIN_COIN)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(MAIN_CROWN)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(MAIN_BLACK_RECTANGLE)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_PLAY, encapsulation::raylib::Rectangle(1494, 927, 382, 113), encapsulation::raylib::Rectangle(0, 0, 382, 113), encapsulation::raylib::Rectangle(382, 0, 382, 113))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_OPTION, encapsulation::raylib::Rectangle(1804, 29, 88, 57), encapsulation::raylib::Rectangle(0, 0, 88, 57), encapsulation::raylib::Rectangle(88, 0, 88, 57))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_SAVE, encapsulation::raylib::Rectangle(1505, 813, 362, 113), encapsulation::raylib::Rectangle(0, 0, 362, 113), encapsulation::raylib::Rectangle(362, 0, 362, 113))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_ADD_PLAYERS, encapsulation::raylib::Rectangle(1178, 941, 131, 111), encapsulation::raylib::Rectangle(0, 0, 131, 111), encapsulation::raylib::Rectangle(131, 0, 131, 111))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_REMOVE_PLAYER, encapsulation::raylib::Rectangle(1331, 941, 131, 111), encapsulation::raylib::Rectangle(0, 0, 131, 111), encapsulation::raylib::Rectangle(131, 0, 131, 111))));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_HOME, encapsulation::raylib::Rectangle(761, 18, 80, 53), encapsulation::raylib::Rectangle(80, 0, 80, 53), encapsulation::raylib::Rectangle(80, 0, 80, 53))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_SKIN, encapsulation::raylib::Rectangle(852, 18, 80, 53), encapsulation::raylib::Rectangle(0, 0, 80, 53), encapsulation::raylib::Rectangle(80, 0, 80, 53))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_QUEST, encapsulation::raylib::Rectangle(944, 18, 80, 53), encapsulation::raylib::Rectangle(0, 0, 80, 53), encapsulation::raylib::Rectangle(80, 0, 80, 53))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(MAIN_SHOP, encapsulation::raylib::Rectangle(1035, 18, 80, 53), encapsulation::raylib::Rectangle(0, 0, 80, 53), encapsulation::raylib::Rectangle(80, 0, 80, 53))));

    this->_modelList.push_back(std::move(std::make_unique<ModelMenu>(BLACK_SKIN, CHARACTER_MODEL, RUN_ANIMATION, encapsulation::raylib::Vector3{2, 1, -4}))); // 3
    this->_modelList.push_back(std::move(std::make_unique<ModelMenu>(PURPLE_SKIN, CHARACTER_MODEL, RUN_ANIMATION, encapsulation::raylib::Vector3{0, 1, -1}))); // 1
    this->_modelList.push_back(std::move(std::make_unique<ModelMenu>(TRANSPARENT_DARK_SKIN, CHARACTER_MODEL, RUN_ANIMATION, encapsulation::raylib::Vector3{2, 1, 2})));  // 2
    this->_modelList.push_back(std::move(std::make_unique<ModelMenu>(TRANSPARENT_ORANGE_SKIN, CHARACTER_MODEL, RUN_ANIMATION, encapsulation::raylib::Vector3{4, 1, 5})));  // 4
}

Indie::game::sceneHandler::SceneMain::~SceneMain()
{
}

void Indie::game::sceneHandler::SceneMain::update()
{
    if (this->nbPlayer == 1) {
        this->_modelList[1]->setDisplay(true);
        this->_modelList[3]->setDisplay(false);
        this->_modelList[0]->setDisplay(false);
        this->_modelList[2]->setDisplay(false);
    } else if (this->nbPlayer == 2) {
        this->_modelList[1]->setDisplay(true);
        this->_modelList[3]->setDisplay(false);
        this->_modelList[0]->setDisplay(false);
        this->_modelList[2]->setDisplay(true);
    } else if (this->nbPlayer == 3) {
        this->_modelList[1]->setDisplay(true);
        this->_modelList[3]->setDisplay(false);
        this->_modelList[0]->setDisplay(true);
        this->_modelList[2]->setDisplay(true);
    } else if (this->nbPlayer == 4) {
        this->_modelList[1]->setDisplay(true);
        this->_modelList[3]->setDisplay(true);
        this->_modelList[0]->setDisplay(true);
        this->_modelList[2]->setDisplay(true);
    }

    for (std::size_t i = 0; i != this->_modelList.size(); i++) {
        this->_modelList[i]->updateModels();
        this->_modelList[i]->getAnimCounter() += 1;
    }
}

void Indie::game::sceneHandler::SceneMain::draw()
{
    encapsulation::raylib::Mouse mouse;

    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(1300, 30, WHITE);
        this->_texture[1]->drawTexture(1550, 30, WHITE);
        this->_texture[2]->drawTexture(681, 0, WHITE);

        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::ModelMenu>& model : this->_modelList) { model->drawModels(this->_camera); }

    this->_sceneHandler.getWindow().endDrawing();

    if (this->_buttonList[1]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneOption(this->_sceneHandler)));
    }
    if (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneGame(this->_sceneHandler, this->nbPlayer)));
    }
    if (this->_buttonList[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneLoad(this->_sceneHandler)));
    }
    if (this->_buttonList[3]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (this->nbPlayer < 4)
            this->nbPlayer++;
    }
    if (this->_buttonList[4]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (this->nbPlayer >= 2)
            this->nbPlayer--;
    }
}
