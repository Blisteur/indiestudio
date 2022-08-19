/*
** EPITECH PROJECT, 2022
** Model.hpp
** File description:
** Model
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Model : public ::Model {
            public:
                Model() = default;
                Model(const std::string&);
                Model(const ::Model& model);
                ~Model();

                bool load(const std::string&);
                void unload();
                void set(const ::Model&);
                void drawModel(::Vector3 position, float scale, Color tint);
                void setMaterial(int, const ::Texture2D&);
                Model& operator=(const ::Model&) = delete;

            protected:
            private:
       };
    }
}
