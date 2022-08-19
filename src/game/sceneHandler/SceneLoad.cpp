/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneLoad
*/

#include "SceneLoad.hpp"
#include "SceneGame.hpp"
#include "../saver/SavedGame.hpp"
#include <filesystem>

Indie::game::sceneHandler::SceneLoad::SceneLoad(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(LOAD_LAYER)));
    this->_font.load("assets/settings/font.ttf");
    if(std::filesystem::is_directory("saves"))
        this->_empty = std::filesystem::is_empty("saves");
    if (!this->_empty) {
        for (const auto & entry : std::filesystem::directory_iterator("saves/"))
            this->_pathList.push_back(entry.path());
        std::reverse(this->_pathList.begin(), this->_pathList.end());
        this->_nbSave = std::distance(std::filesystem::directory_iterator("saves"), std::filesystem::directory_iterator{});
        if (this->_nbSave > 14)
            this->_nbPage = this->_nbSave / 14;
        for (int i = 0, j = 1; i != this->_nbSave; i++) {
            encapsulation::raylib::Rectangle rect = {0, (float)(250 + j * 90), 300, 70};
            if (i % 2 == 0) {
                rect.x = 1920 / 2 - 20 - 300;
            } else {
                rect.x = 1920 / 2 + 20;
                j++;
                if (j == 7) j = 0;
            }
            this->_buttonList.push_back(std::move(std::make_unique<Button>(LOAD_BUTTON, rect, encapsulation::raylib::Rectangle(300, 0, 300, 70), encapsulation::raylib::Rectangle(0, 0, 300, 70))));
        }
    }
}

Indie::game::sceneHandler::SceneLoad::~SceneLoad()
{
}

void Indie::game::sceneHandler::SceneLoad::update()
{
    encapsulation::raylib::Mouse mouse;
    encapsulation::raylib::Keyboard kb;

    for (std::size_t i = 1; i != this->_buttonList.size(); i++) {
        if ((this->_buttonList[i]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
            this->_sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneGame(this->_sceneHandler, 4, this->_pathList[i - 1])));
        }
    }
    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler.popScene();
    }
}

void Indie::game::sceneHandler::SceneLoad::draw()
{
    this->_sceneHandler.getWindow().beginDrawing();
    this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
    this->_texture[0]->drawTexture(1920 / 2 - 860 / 2, 1080 / 2 - 785 / 2, WHITE);
    for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
    for (int i = 0, j = 1; i != this->_nbSave; i++) {
        encapsulation::raylib::Vector2 vec = {0, (float)(255 + j * 90)};
        if (i % 2 == 0) {
            vec.x = 1920 / 2 - 20 - 300 + 20;
        } else {
            vec.x = 1920 / 2 + 20 + 20;
            j++;
            if (j == 7) j = 0;
        }
        std::string tmpString("Game ");
        tmpString += std::to_string(i + 1);
        this->_font.drawText(tmpString.c_str(), vec, 50, 2, WHITE);
    }
    if (this->_empty) this->_font.drawText("No save found :(", {1920 / 2 - 150, 1080 / 2}, 50, 2, BLACK);
    this->_sceneHandler.getWindow().endDrawing();
}
