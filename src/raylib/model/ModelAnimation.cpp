/*
** EPITECH PROJECT, 2022
** ModelAnimation.cpp
** File description:
** ModelAnimation
*/

#include "ModelAnimation.hpp"
#include <vector>

encapsulation::raylib::ModelAnimation::ModelAnimation()
{
    this->_animCount = 0;
    this->_animType = 0;
}

encapsulation::raylib::ModelAnimation::ModelAnimation(const ::ModelAnimation& model, int animCount)
{
    _animCount = animCount;
    _animType = 0;
    this->set(model);
}

encapsulation::raylib::ModelAnimation::~ModelAnimation()
{
    std::cout << "ModelAnimation::~ModelAnimation()" << std::endl;
    this->unload();
}

void encapsulation::raylib::ModelAnimation::set(const ::ModelAnimation& model)
{
    boneCount = model.boneCount;
    frameCount = model.frameCount;
    bones = model.bones;
    framePoses = model.framePoses;
}

void encapsulation::raylib::ModelAnimation::unload()
{
    for (unsigned int i = 0; i < _animCount; i += 1) {
        UnloadModelAnimation(this[i]);
    }
}

encapsulation::raylib::ModelAnimation& encapsulation::raylib::ModelAnimation::operator=(const ::ModelAnimation& model)
{
    this->set(model);
    return (*this);
}

void encapsulation::raylib::ModelAnimation::updateModelAnimation(::Model& model, int frame)
{
    UpdateModelAnimation(model, this[_animType], frame);
}

void encapsulation::raylib::ModelAnimation::loadModelAnimations(const std::string& filepath, unsigned int animCount)
{
    _animCount = animCount;
    ::ModelAnimation *model = LoadModelAnimations(filepath.c_str(), &animCount);
    this->set(*model);
    RL_FREE(model);
}

void encapsulation::raylib::ModelAnimation::setModelAnimation(unsigned int animType)
{
    _animType = animType;
}

unsigned int encapsulation::raylib::ModelAnimation::getModelAnimation() const
{
    return (_animType);
}