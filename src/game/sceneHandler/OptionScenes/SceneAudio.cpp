/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneAudio
*/

#include "SceneAudio.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneAudio::SceneAudio(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_font.load("assets/settings/font.ttf");
    this->_btnMa = this->_sceneHandler._config.master_btn;
    this->_soundMa = this->_sceneHandler._config.master_volume;
    this->_btnMu = this->_sceneHandler._config.music_btn;
    this->_soundMu = this->_sceneHandler._config.music_volume;
    this->_btnEf = this->_sceneHandler._config.sound_btn;
    this->_soundEf = this->_sceneHandler._config.sound_volume;

    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SETTINGS)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_ROUAGE)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(AUDIO_WINDOW)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SCROLL_BUTTON)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(AUDIO_MASTER, encapsulation::raylib::Rectangle(860, 200, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(AUDIO_MUSIC, encapsulation::raylib::Rectangle(860, 270, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonList.push_back(std::move(std::make_unique<Button>(AUDIO_EFFECTS, encapsulation::raylib::Rectangle(860, 340, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));

    this->_buttonListMaster.push_back(std::move(std::make_unique<Button>(OTHER_LEFT_ARROW, encapsulation::raylib::Rectangle(1350, 215, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListMaster.push_back(std::move(std::make_unique<Button>(OTHER_RIGHT_ARROW, encapsulation::raylib::Rectangle(1610, 215, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListMaster.push_back(std::move(std::make_unique<Button>(OTHER_SCROLL_BAR, encapsulation::raylib::Rectangle(1385, 228, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5))));

    this->_buttonListMusic.push_back(std::move(std::make_unique<Button>(OTHER_LEFT_ARROW, encapsulation::raylib::Rectangle(1350, 285, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListMusic.push_back(std::move(std::make_unique<Button>(OTHER_RIGHT_ARROW, encapsulation::raylib::Rectangle(1610, 285, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListMusic.push_back(std::move(std::make_unique<Button>(OTHER_SCROLL_BAR, encapsulation::raylib::Rectangle(1385, 298, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5))));

    this->_buttonListEffect.push_back(std::move(std::make_unique<Button>(OTHER_LEFT_ARROW, encapsulation::raylib::Rectangle(1350, 355, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListEffect.push_back(std::move(std::make_unique<Button>(OTHER_RIGHT_ARROW, encapsulation::raylib::Rectangle(1610, 355, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30), encapsulation::raylib::Rectangle(0, 0, 20, 30))));
    this->_buttonListEffect.push_back(std::move(std::make_unique<Button>(OTHER_SCROLL_BAR, encapsulation::raylib::Rectangle(1385, 368, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5), encapsulation::raylib::Rectangle(0, 0, 208, 5))));
}

Indie::game::sceneHandler::SceneAudio::~SceneAudio()
{
}

int Indie::game::sceneHandler::SceneAudio::calcul(int x)
{
    int volume = 0;
    x = x - 1385;

    for(int i = 0; i < x; i += 2.08)
        volume++;

    if (volume >= 97)
        volume = 100;
    return (volume);
}

void Indie::game::sceneHandler::SceneAudio::update()
{
    encapsulation::raylib::Keyboard kb;
    encapsulation::raylib::Mouse mouse;

    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler.popScene();
        return;
    }

    if (this->_buttonListMaster[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        this->_btnMa = mouse.getMouseX() - 13;
        this->_sceneHandler._config.master_btn = this->_btnMa;
        this->_soundMa = this->calcul(mouse.getMouseX() - 13);
        this->_sceneHandler._config.master_volume = this->_soundMa;
    }

    if (this->_buttonListMusic[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        this->_btnMu = mouse.getMouseX() - 13;
        this->_sceneHandler._config.music_btn = this->_btnMu;
        this->_soundMu = this->calcul(mouse.getMouseX() - 13);
        this->_sceneHandler._config.music_volume = this->_soundMu;
    }

    if (this->_buttonListEffect[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        this->_btnEf = mouse.getMouseX() - 13;
        this->_sceneHandler._config.sound_btn = this->_btnEf;
        this->_soundEf = this->calcul(mouse.getMouseX() - 13);
        this->_sceneHandler._config.sound_volume = this->_soundEf;
    }

    if (this->_buttonList[1]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorMa = BLACK;
    else
        this->_colorMa = WHITE;
    if (this->_buttonList[2]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorMu = BLACK;
    else
        this->_colorMu = WHITE;
    if (this->_buttonList[3]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()))
        this->_colorEf = BLACK;
    else
        this->_colorEf = WHITE;
}

void Indie::game::sceneHandler::SceneAudio::draw()
{
    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(0, 0, WHITE);
        this->_texture[1]->drawTexture(150, 330, WHITE);
        this->_texture[2]->drawTexture(850, 100, WHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListMaster) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListMusic) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListEffect) { btn->drawButton(); }
        this->_texture[3]->drawTexture(_btnMa, 218, WHITE);
        this->_texture[3]->drawTexture(_btnMu, 288, WHITE);
        this->_texture[3]->drawTexture(_btnEf, 358, WHITE);
        this->_font.drawText(std::to_string(_soundMa).c_str(), Vector2{ 1270.0f, 213.0f }, 30, 10, this->_colorMa);
        this->_font.drawText(std::to_string(_soundMu).c_str(), Vector2{ 1270.0f, 283.0f }, 30, 10, this->_colorMu);
        this->_font.drawText(std::to_string(_soundEf).c_str(), Vector2{ 1270.0f, 353.0f }, 30, 10, this->_colorEf);
    this->_sceneHandler.getWindow().endDrawing();
}