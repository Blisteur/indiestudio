/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** ModelMenu
*/

#pragma once

#include <string>
#include <memory>
#include "../../raylib/texture/Texture2D.hpp"
#include "../../raylib/model/Model.hpp"
#include "../../raylib/model/ModelAnimation.hpp"
#include "../../raylib/camera/Camera3D.hpp"
#include "../../raylib/vector/Vector3.hpp"

namespace Indie {
    namespace game {
        class ModelMenu {
            public:
                ModelMenu(std::string texturePath, std::string modelPath, std::string animation, encapsulation::raylib::Vector3 pos);
                ~ModelMenu();

                void drawModels(encapsulation::raylib::Camera3D& camera);
                void updateModels();
                void setDisplay(bool state);

                void setAnimCounter(int value);
                unsigned int& getAnimCounter();
            protected:
            private:
                std::unique_ptr<encapsulation::raylib::Texture2D> _textureGuy;
                std::unique_ptr<encapsulation::raylib::Model> _modelGuy;
                std::unique_ptr<encapsulation::raylib::ModelAnimation> _animationGuy;

                std::unique_ptr<encapsulation::raylib::Texture2D> _textureBlock;
                std::unique_ptr<encapsulation::raylib::Model> _modelBlock;

                encapsulation::raylib::Vector3 _blockPos;
                encapsulation::raylib::Vector3 _guyPos;

                unsigned int _animFrameCounter = 0;

                bool _display = false;
        };
    }
}