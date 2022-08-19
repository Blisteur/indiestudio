/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneKeyboard
*/

#pragma once

#include "../AScene.hpp"
#include "../../../InputBox/InputBox.hpp"
#include "../../../InputBox/KeyDictionnary.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneKeyboard : public AScene {
                public:
                    SceneKeyboard(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneKeyboard();
                    void update();
                    void draw();
                protected:
                private:
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListP1;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListP2;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListP3;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListP4;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
                    std::vector<Indie::graphic::element::InputBox> _text_box_p1;
                    std::vector<Indie::graphic::element::InputBox> _text_box_p2;
                    std::vector<Indie::graphic::element::InputBox> _text_box_p3;
                    std::vector<Indie::graphic::element::InputBox> _text_box_p4;
            };
        }
    }
}
