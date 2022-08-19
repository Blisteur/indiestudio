/*
** EPITECH PROJECT, 2022
** indie
** File description:
** SceneSettings
*/

#pragma once

#include "../AScene.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneSettings : public AScene {
                public:
                    SceneSettings(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneSettings();
                    void update();
                    void draw();
                protected:
                private:
                    encapsulation::raylib::Font _font;
                    Color _colorFps;
                    Color _colorFull;
                    Color _colorEfRes;
                    int _texte_fps;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
            };
        }
    }
}
