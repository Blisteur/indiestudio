/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Error
*/

#include "Error.hpp"

Indie::network::Error::Error(std::string const &message, std::string const &component) noexcept
{
    _message = message;
    _component = component;
}

Indie::network::NetworkError::NetworkError(std::string const &message, std::string const &component) noexcept: Error(message, component)
{
}

Indie::network::ProtocolError::ProtocolError(std::string const &message, std::string const &component) noexcept: Error(message, component)
{
}

Indie::network::PacketError::PacketError(std::string const &message, std::string const &component) noexcept: Error(message, component)
{
}