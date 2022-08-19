/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Scene
*/

#pragma once

namespace Indie {
    namespace game {
        namespace sceneHandler {
            class IScene {
                public:
                    IScene() = default;
                    virtual ~IScene() = default;
                    virtual void update() = 0;
                    virtual void draw() = 0;
                protected:
                private:
            };
        }
    }
}
