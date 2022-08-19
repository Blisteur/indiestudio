/*
** EPITECH PROJECT, 2022
** Camera3D.cpp
** File description:
** Camera3D
*/

#include "Camera3D.hpp"

encapsulation::raylib::Camera3D::Camera3D(const ::Camera3D& camera)
{
    this->set(camera);
}

encapsulation::raylib::Camera3D::Camera3D(::Vector3 position, ::Vector3 target, ::Vector3 up, float fovy, int projection) : ::Camera3D{position, target, up, fovy, projection}
{
}

encapsulation::raylib::Camera3D::~Camera3D()
{
}

void encapsulation::raylib::Camera3D::set(const ::Camera3D& camera)
{
    position = camera.position;
    target = camera.target;
    up = camera.up;
    fovy = camera.fovy;
    projection = camera.projection;
}

void encapsulation::raylib::Camera3D::beginMode3D()
{
    BeginMode3D(*this);
}

void encapsulation::raylib::Camera3D::endMode3D()
{
    EndMode3D();
}

void encapsulation::raylib::Camera3D::update()
{
    UpdateCamera(this);
}