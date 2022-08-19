/*
** EPITECH PROJECT, 2022
** Error class
** File description:
** IndieStudio
*/

#include "Error.hpp"

Indie::engine::Error::Error(std::string const &message, std::string const &component) noexcept
{
    _message = message;
    _component = component;
}

Indie::engine::fileError::fileError(std::string const &message, std::string const &component): Error(message, component)
{
}
