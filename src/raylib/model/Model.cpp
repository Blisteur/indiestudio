/*
** EPITECH PROJECT, 2022
** Model.cpp
** File description:
** Model
*/

#include "Model.hpp"

encapsulation::raylib::Model::Model(const std::string& filepath)
{
    if (!this->load(filepath))
        throw encapsulation::raylib::RaylibError("Model::Model: Failed to load model from filepath: " + filepath, "Model constructor");
}

encapsulation::raylib::Model::Model(const ::Model& model)
{
    this->set(model);
}

encapsulation::raylib::Model::~Model()
{
    this->unload();
    std::cout << "Model unload" << std::endl;
}

void encapsulation::raylib::Model::unload()
{
    UnloadModel(*this);
}

void encapsulation::raylib::Model::set(const ::Model& model)
{
    transform = model.transform;
    meshCount = model.meshCount;
    meshes = model.meshes;
    materials = model.materials;
    meshMaterial = model.meshMaterial;
    boneCount = model.boneCount;
    bones = model.bones;
    bindPose = model.bindPose;
    materialCount = model.materialCount;
}

bool encapsulation::raylib::Model::load(const std::string& filepath)
{
    this->set(::LoadModel(filepath.c_str()));
    return (meshCount > 0 || materialCount > 0 || boneCount > 0);
}

void encapsulation::raylib::Model::setMaterial(int mapType, const ::Texture2D &texture)
{
    SetMaterialTexture(this->materials, mapType, texture);
}

void encapsulation::raylib::Model::drawModel(Vector3 position, float scale, Color tint)
{
    DrawModel(*this, position, scale, tint);
}