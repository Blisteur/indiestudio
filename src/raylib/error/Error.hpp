/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Error
*/

#pragma once

#include <string>

namespace encapsulation
{
    namespace raylib
    {
        // mother class Error
        class Error: public std::exception {
            public:
                Error(std::string const &message, std::string const &component = "Unknown") noexcept;
                const char *what() const noexcept override {return _message.data();};
            protected:
                std::string _message;
                std::string _component;
            private:
        };
        // class RaylibError
        class RaylibError: public Error {
            public:
                RaylibError(std::string const &message, std::string const &component = "Raylib encaps") noexcept;
        };
    }
}