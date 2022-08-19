/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneSettings
*/

#include "SceneSettings.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneSettings::SceneSettings(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_font.load("assets/settings/font.ttf");
    this->_texte_fps = this->_sceneHandler._config._texte_fps;
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SETTINGS)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_ROUAGE)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OPTIONS_WINDOW)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(OPTIONS_FPS, encapsulation::raylib::Rectangle(860, 200, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(OPTIONS_FULL_SCREEN, encapsulation::raylib::Rectangle(855, 270, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(OPTIONS_RESOLUTION, encapsulation::raylib::Rectangle(860, 340, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(OTHER_LEFT_ARROW, encapsulation::raylib::Rectangle(1450, 215, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(OTHER_RIGHT_ARROW, encapsulation::raylib::Rectangle(1590, 215, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
}

Indie::game::sceneHandler::SceneSettings::~SceneSettings()
{

}

void Indie::game::sceneHandler::SceneSettings::update()
{
    encapsulation::raylib::Keyboard kb;
    encapsulation::raylib::Mouse mouse;

    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler.popScene();
        return;
    }

    if (this->_buttonList[4]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (this->_texte_fps == 60) {
            this->_texte_fps = 30;
            this->_sceneHandler._config._texte_fps = 30;
            this->_sceneHandler.getWindow().setTargetFPS(30);
        }
        if (this->_texte_fps == 120) {
            this->_texte_fps = 60;
            this->_sceneHandler._config._texte_fps = 60;
            this->_sceneHandler.getWindow().setTargetFPS(60);
        }
    }
    if (this->_buttonList[5]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (this->_texte_fps == 60) {
            this->_texte_fps = 120;
            this->_sceneHandler._config._texte_fps = 120;
            this->_sceneHandler.getWindow().setTargetFPS(120);
        }
        if (this->_texte_fps == 30) {
            this->_texte_fps = 60;
            this->_sceneHandler._config._texte_fps = 60;
            this->_sceneHandler.getWindow().setTargetFPS(60);
        }
    }
    if (this->_buttonList[1]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorFps = BLACK;
    else
        this->_colorFps = WHITE;
    if (this->_buttonList[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorFull = BLACK;
    else
        this->_colorFull = WHITE;
    if (this->_buttonList[3]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorEfRes = BLACK;
    else
        this->_colorEfRes = WHITE;
}

void Indie::game::sceneHandler::SceneSettings::draw()
{
    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(0, 0, WHITE);
        this->_texture[1]->drawTexture(150, 330, WHITE);
        this->_texture[2]->drawTexture(850, 100, WHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
        this->_font.drawText(std::to_string(this->_texte_fps).c_str(), (Vector2){ 1510.0f, 214.0f }, 30, 10, this->_colorFps);
        this->_font.drawText("On", (Vector2){ 1510.0f, 284.0f }, 30, 10, this->_colorFull);
        this->_font.drawText("1920x1080", (Vector2){ 1430.0f, 353.0f }, 30, 10, this->_colorEfRes);
    this->_sceneHandler.getWindow().endDrawing();
}
