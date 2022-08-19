/*
** EPITECH PROJECT, 2022
** Camera3D.hpp
** File description:
** Camera3D
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Camera3D : public ::Camera3D {
            public:
                Camera3D(const ::Camera3D&);
                Camera3D(::Vector3, ::Vector3, ::Vector3, float, int);
                ~Camera3D();

                void set(const ::Camera3D&);
                void beginMode3D();
                void endMode3D();
                void update();
                Camera3D& operator=(const ::Camera3D&) = delete;

            protected:
            private:
                Camera3D* _camera3D;
        };
    }
}
