/*
** EPITECH PROJECT, 2022
** Texture2D.hpp
** File description:
** Texture2D
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Texture2D : public ::Texture2D {
            public:
                Texture2D() = default;
                Texture2D(unsigned int, int, int, int, int);
                Texture2D(const ::Texture&);
                Texture2D(const ::Image&);
                Texture2D(const std::string&);
                ~Texture2D();

                void set(const ::Texture2D&);
                bool load(const ::Image&);
                bool load(const std::string&);
                void unload();
                void updateTexture(const void *);
                void updateTextureRec(::Rectangle, const void *);
                void drawTexture(int, int, ::Color) const;
                void drawTextureV(::Vector2, ::Color) const;
                void drawTextureRec(::Rectangle, ::Vector2, ::Color) const;
                void drawTextureEx(::Vector2 position, float rotation, float scale, ::Color tint) const;
                void drawTextureTiled(::Rectangle source, ::Rectangle dest, ::Vector2 origin, float rotation, float scale, ::Color tint) const;
                Texture2D& operator=(const ::Texture2D&) = delete;

            protected:
            private:
        };
    }
}
