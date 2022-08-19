/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneAudio
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneAudio : public AScene {
                public:
                    SceneAudio(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneAudio();
                    void update();
                    void draw();
                protected:
                private:
                    int calcul(int x);
                    int _btnMa;
                    int _soundMa;
                    int _btnMu;
                    int _soundMu;
                    int _btnEf;
                    int _soundEf;
                    Color _colorMa;
                    Color _colorMu;
                    Color _colorEf;
                    encapsulation::raylib::Font _font;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListMaster;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListMusic;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonListEffect;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
            };
        }
    }
}