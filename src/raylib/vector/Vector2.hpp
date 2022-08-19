/*
** EPITECH PROJECT, 2022
** Vector2.hpp
** File description:
** Vector2
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Vector2 : public ::Vector2 {
            public:
                Vector2();
                Vector2(const ::Vector2&);
                Vector2(float, float);
                ~Vector2();

                bool operator==(const ::Vector2&) const;
                bool operator!=(const ::Vector2&) const;
                Vector2 operator+(const ::Vector2& vector);
                Vector2 operator-(const ::Vector2& vector);
                Vector2 operator*(const ::Vector2& vector);
                Vector2 operator/(const ::Vector2& vector);
                Vector2 vector2Add(const ::Vector2&);
                Vector2 vector2Subtract(const ::Vector2&);
                Vector2 vector2Multiply(const ::Vector2&);
                Vector2 vector2Divide(const ::Vector2&);
                Vector2& operator=(const ::Vector2&);
                Vector2& operator+=(const ::Vector2& vector);
                Vector2& operator-=(const ::Vector2& vector);
                Vector2& operator*=(const ::Vector2& vector);
                Vector2& operator/=(const ::Vector2& vector);

                void Set(const ::Vector2&);
            protected:
            private:
        };
    }
}
