/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** SceneLoad
*/

#pragma once

#include "AScene.hpp"
#include "../saver/SavedGame.hpp"
#include "../saver/Saver.hpp"

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class SceneLoad : public AScene {
                public:
                    SceneLoad(Indie::game::sceneHandler::SceneHandler &sceneHandler);
                    ~SceneLoad();
                    void update();
                    void draw();
                protected:
                private:
                    int _nbSave = 0;
                    int _nbPage = 0;
                    bool _empty = true;
                    encapsulation::raylib::Font _font;
                    std::vector<std::string> _pathList;
                    std::vector<std::unique_ptr<Indie::game::Button>> _buttonList;
                    std::vector<std::unique_ptr<encapsulation::raylib::Texture2D>> _texture;
            };
        }
    }
}