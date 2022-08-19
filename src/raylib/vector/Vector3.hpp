/*
** EPITECH PROJECT, 2022
** Vector3.hpp
** File description:
** Vector3
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Vector3 : public ::Vector3 {
            public:
                Vector3();
                Vector3(const ::Vector3&);
                Vector3(float, float, float);
                ~Vector3();

                bool operator==(const ::Vector3&) const;
                bool operator!=(const ::Vector3&) const;
                Vector3 operator+(const ::Vector3& vector);
                Vector3 operator-(const ::Vector3& vector);
                Vector3 operator*(const ::Vector3& vector);
                Vector3 operator/(const ::Vector3& vector);
                Vector3 vector3Add(const ::Vector3&);
                Vector3 vector3Subtract(const ::Vector3&);
                Vector3 vector3Multiply(const ::Vector3&);
                Vector3 vector3Divide(const ::Vector3&);
                Vector3& operator=(const ::Vector3&);
                Vector3& operator+=(const ::Vector3& vector);
                Vector3& operator-=(const ::Vector3& vector);
                Vector3& operator*=(const ::Vector3& vector);
                Vector3& operator/=(const ::Vector3& vector);

                void Set(const ::Vector3&);
            protected:
            private:
        };
    }
}
