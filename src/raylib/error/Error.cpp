/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Error
*/

#include "Error.hpp"

encapsulation::raylib::Error::Error(std::string const &message, std::string const &component) noexcept
{
    _message = message;
    _component = component;
}

encapsulation::raylib::RaylibError::RaylibError(std::string const &message, std::string const &component) noexcept: Error(message, component)
{
}