/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneKeyboard
*/

#include "SceneKeyboard.hpp"
#include "../SceneOption.hpp"
#include "../../Assets.hpp"

Indie::game::sceneHandler::SceneKeyboard::SceneKeyboard(Indie::game::sceneHandler::SceneHandler &sceneHandler): AScene(sceneHandler)
{
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(OTHER_SETTINGS)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(KEYBOARD_PLAYER1)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(KEYBOARD_PLAYER2)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(KEYBOARD_PLAYER3)));
    this->_texture.push_back(std::move(std::make_unique<encapsulation::raylib::Texture2D>(KEYBOARD_PLAYER4)));

    this->_buttonList.push_back(std::move(std::make_unique<Button>(GO_BACK, encapsulation::raylib::Rectangle(1726, 1012, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68), encapsulation::raylib::Rectangle(0, 0, 194, 68))));

    this->_buttonListP1.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_UP, encapsulation::raylib::Rectangle(60, 210, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP1.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_RIGHT, encapsulation::raylib::Rectangle(60, 280, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP1.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_LEFT, encapsulation::raylib::Rectangle(60, 350, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP1.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_DOWN, encapsulation::raylib::Rectangle(60, 420, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP1.push_back(std::move(std::make_unique<Button>(KEYBOARD_BOMB, encapsulation::raylib::Rectangle(60, 490, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));

    this->_buttonListP2.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_UP, encapsulation::raylib::Rectangle(1010, 210, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP2.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_RIGHT, encapsulation::raylib::Rectangle(1010, 280, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP2.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_LEFT, encapsulation::raylib::Rectangle(1010, 350, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP2.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_DOWN, encapsulation::raylib::Rectangle(1010, 420, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP2.push_back(std::move(std::make_unique<Button>(KEYBOARD_BOMB, encapsulation::raylib::Rectangle(1010, 490, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));

    this->_buttonListP3.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_UP, encapsulation::raylib::Rectangle(60, 720, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP3.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_RIGHT, encapsulation::raylib::Rectangle(60, 790, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP3.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_LEFT, encapsulation::raylib::Rectangle(60, 860, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP3.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_DOWN, encapsulation::raylib::Rectangle(60, 930, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP3.push_back(std::move(std::make_unique<Button>(KEYBOARD_BOMB, encapsulation::raylib::Rectangle(60, 1000, 900, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));

    this->_buttonListP4.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_UP, encapsulation::raylib::Rectangle(1010, 720, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP4.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_RIGHT, encapsulation::raylib::Rectangle(1010, 790, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP4.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_LEFT, encapsulation::raylib::Rectangle(1010, 860, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP4.push_back(std::move(std::make_unique<Button>(KEYBOARD_MOVE_DOWN, encapsulation::raylib::Rectangle(1010, 930, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));
    this->_buttonListP4.push_back(std::move(std::make_unique<Button>(KEYBOARD_BOMB, encapsulation::raylib::Rectangle(1010, 1000, 830, 55), encapsulation::raylib::Rectangle(0, 0, 830, 55), encapsulation::raylib::Rectangle(0, 55, 830, 55))));

    this->_text_box_p1.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 223, 30, 30, 690, 228), this->_sceneHandler._config.entity0_up));
    this->_text_box_p1.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 293, 30, 30, 690, 298), this->_sceneHandler._config.entity0_right));
    this->_text_box_p1.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 363, 30, 30, 690, 368), this->_sceneHandler._config.entity0_left));
    this->_text_box_p1.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 433, 30, 30, 690, 438), this->_sceneHandler._config.entity0_down));
    this->_text_box_p1.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 503, 30, 30, 690, 508), this->_sceneHandler._config.entity0_place));

    this->_text_box_p2.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 223, 30, 30, 1640, 228), this->_sceneHandler._config.entity1_up));
    this->_text_box_p2.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 293, 30, 30, 1640, 298), this->_sceneHandler._config.entity1_right));
    this->_text_box_p2.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 363, 30, 30, 1640, 368), this->_sceneHandler._config.entity1_left));
    this->_text_box_p2.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 433, 30, 30, 1640, 438), this->_sceneHandler._config.entity1_down));
    this->_text_box_p2.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 503, 30, 30, 1640, 508), this->_sceneHandler._config.entity1_place));

    this->_text_box_p3.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 733, 30, 30, 690, 733), this->_sceneHandler._config.entity2_up));
    this->_text_box_p3.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 803, 30, 30, 690, 803), this->_sceneHandler._config.entity2_right));
    this->_text_box_p3.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 873, 30, 30, 690, 873), this->_sceneHandler._config.entity2_left));
    this->_text_box_p3.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 943, 30, 30, 690, 943), this->_sceneHandler._config.entity2_down));
    this->_text_box_p3.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(680, 1013, 30, 30, 685, 1014), this->_sceneHandler._config.entity2_place));

    this->_text_box_p4.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 733, 30, 30, 1640, 736), this->_sceneHandler._config.entity3_up));
    this->_text_box_p4.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 803, 30, 30, 1640, 806), this->_sceneHandler._config.entity3_right));
    this->_text_box_p4.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 873, 30, 30, 1640, 876), this->_sceneHandler._config.entity3_left));
    this->_text_box_p4.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 943, 30, 30, 1640, 946), this->_sceneHandler._config.entity3_down));
    this->_text_box_p4.push_back(Indie::graphic::element::InputBox(Indie::graphic::position::Position2D(1630, 1013, 30, 30, 1640, 1016), this->_sceneHandler._config.entity3_place));
}

Indie::game::sceneHandler::SceneKeyboard::~SceneKeyboard()
{

}

void Indie::game::sceneHandler::SceneKeyboard::update()
{
    encapsulation::raylib::Keyboard kb;
    encapsulation::raylib::Mouse mouse;

    if (kb.isKeyPressed(KEY_ESCAPE) || (this->_buttonList[0]->_pos.coordInRect(mouse.getMouseX(), mouse.getMouseY()) && mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        this->_sceneHandler._config.entity0_up = this->_text_box_p1[0].getKey();
        this->_sceneHandler._config.entity0_right = this->_text_box_p1[1].getKey();
        this->_sceneHandler._config.entity0_left = this->_text_box_p1[2].getKey();
        this->_sceneHandler._config.entity0_down = this->_text_box_p1[3].getKey();
        this->_sceneHandler._config.entity0_place = this->_text_box_p1[4].getKey();

        this->_sceneHandler._config.entity1_up = this->_text_box_p2[0].getKey();
        this->_sceneHandler._config.entity1_right = this->_text_box_p2[1].getKey();
        this->_sceneHandler._config.entity1_left = this->_text_box_p2[2].getKey();
        this->_sceneHandler._config.entity1_down = this->_text_box_p2[3].getKey();
        this->_sceneHandler._config.entity1_place = this->_text_box_p2[4].getKey();

        this->_sceneHandler._config.entity2_up = this->_text_box_p3[0].getKey();
        this->_sceneHandler._config.entity2_right = this->_text_box_p3[1].getKey();
        this->_sceneHandler._config.entity2_left = this->_text_box_p3[2].getKey();
        this->_sceneHandler._config.entity2_down = this->_text_box_p3[3].getKey();
        this->_sceneHandler._config.entity2_place = this->_text_box_p3[4].getKey();

        this->_sceneHandler._config.entity3_up = this->_text_box_p4[0].getKey();
        this->_sceneHandler._config.entity3_right = this->_text_box_p4[1].getKey();
        this->_sceneHandler._config.entity3_left = this->_text_box_p4[2].getKey();
        this->_sceneHandler._config.entity3_down = this->_text_box_p4[3].getKey();
        this->_sceneHandler._config.entity3_place = this->_text_box_p4[4].getKey();
        this->_sceneHandler.popScene();
        return;
    }
}

void Indie::game::sceneHandler::SceneKeyboard::draw()
{
    encapsulation::raylib::Mouse mouse;
    int key = GetKeyPressed();

    this->_sceneHandler.getWindow().beginDrawing();
        this->_sceneHandler.getWindow().clearBackground(RAYWHITE);
        this->_texture[0]->drawTexture(0, 0, WHITE);
        this->_texture[1]->drawTexture(50, 65, WHITE);
        this->_texture[2]->drawTexture(1000, 65, WHITE);
        this->_texture[3]->drawTexture(50, 575, WHITE);
        this->_texture[3]->drawTexture(1000, 575, WHITE);
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListP1) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListP2) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListP3) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonListP4) { btn->drawButton(); }
        for(std::unique_ptr<Indie::game::Button>& btn : this->_buttonList) { btn->drawButton(); }
        for(auto &tbp1 : this->_text_box_p1) { tbp1.mouseInteract(mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)); tbp1.handleKeyPressed(key); tbp1.drawBox(false); }
        for(auto &tbp2 : this->_text_box_p2) { tbp2.mouseInteract(mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)); tbp2.handleKeyPressed(key); tbp2.drawBox(false); }
        for(auto &tbp3 : this->_text_box_p3) { tbp3.mouseInteract(mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)); tbp3.handleKeyPressed(key); tbp3.drawBox(false); }
        for(auto &tbp4 : this->_text_box_p4) { tbp4.mouseInteract(mouse.isMouseButtonPressed(MOUSE_BUTTON_LEFT)); tbp4.handleKeyPressed(key); tbp4.drawBox(false); }

        this->_sceneHandler.getWindow().endDrawing();
}