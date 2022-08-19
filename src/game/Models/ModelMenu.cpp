/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** ModelMenu
*/

#include "ModelMenu.hpp"
#include "../Assets.hpp"

Indie::game::ModelMenu::ModelMenu(std::string texturePath, std::string modelPath, std::string animationPath, encapsulation::raylib::Vector3 pos)
{
    (void)animationPath;
    this->_textureGuy = std::make_unique<encapsulation::raylib::Texture2D>(texturePath);
    this->_modelGuy = std::make_unique<encapsulation::raylib::Model>(modelPath);
    this->_animationGuy = std::make_unique<encapsulation::raylib::ModelAnimation>();
    this->_animationGuy->loadModelAnimations("assets/LookAnimation.iqm", 1);
    this->_animFrameCounter = 0;
    this->_animationGuy->updateModelAnimation(*this->_modelGuy, this->_animFrameCounter);
    this->_modelGuy->setMaterial(MATERIAL_MAP_DIFFUSE, *this->_textureGuy.get());
    this->_guyPos = pos;
    this->_modelGuy->transform = MatrixRotateXYZ({DEG2RAD * 90, DEG2RAD * 90, 0});

    this->_textureBlock = std::make_unique<encapsulation::raylib::Texture2D>(BLOCK_MAIN_TEXTURE);
    this->_modelBlock = std::make_unique<encapsulation::raylib::Model>(BLOCK_MAIN_MODEL);
    this->_blockPos = pos;
    this->_blockPos.y = pos.y - 2;
    this->_modelBlock->setMaterial(MATERIAL_MAP_DIFFUSE, *this->_textureBlock.get());
}

Indie::game::ModelMenu::~ModelMenu()
{
}

void Indie::game::ModelMenu::drawModels(encapsulation::raylib::Camera3D& camera)
{
    camera.beginMode3D();
    if (this->_display)
        this->_modelGuy->drawModel(this->_guyPos, 0.01f, WHITE);
    this->_modelBlock->drawModel(this->_blockPos, 0.8f, WHITE);
    camera.endMode3D();
}

void Indie::game::ModelMenu::updateModels()
{
    this->_animationGuy->updateModelAnimation(*this->_modelGuy, this->_animFrameCounter);
    this->_animFrameCounter += 1;
    if ((int)this->_animFrameCounter >= this->_animationGuy.get()[this->_animationGuy->getModelAnimation()].frameCount)
        this->_animFrameCounter = 0;
}

void Indie::game::ModelMenu::setDisplay(bool state)
{
    this->_display = state;
}

void Indie::game::ModelMenu::setAnimCounter(int value)
{
    this->_animFrameCounter = value;
}

unsigned int& Indie::game::ModelMenu::getAnimCounter()
{
    return this->_animFrameCounter;
}
