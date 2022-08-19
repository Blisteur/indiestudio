/*
** EPITECH PROJECT, 2022
** ModelAnimation.hpp
** File description:
** Modelanimation
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class ModelAnimation : public ::ModelAnimation{
            public:
                ModelAnimation();
                ModelAnimation(const ::ModelAnimation&, int animCount);
                ~ModelAnimation();

                void set(const ::ModelAnimation&);
                void unload();
                void updateModelAnimation(::Model&, int);
                void loadModelAnimations(const std::string&, unsigned int);
                ModelAnimation& operator=(const ::ModelAnimation&);
                void setModelAnimation(unsigned int);
                unsigned int getModelAnimation() const;

            protected:
            private:
                unsigned int _animCount;
                unsigned int _animType;
        };
    }
}
