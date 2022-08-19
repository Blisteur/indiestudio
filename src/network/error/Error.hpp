/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Error
*/

#pragma once

#include <string>

namespace Indie
{
    namespace network
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
        // class NetworkError
        class NetworkError: public Error {
            public:
                NetworkError(std::string const &message, std::string const &component = "Network module") noexcept;
        };
        // class ProtocolError
        class ProtocolError: public Error {
            public:
                ProtocolError(std::string const &message, std::string const &component = "Protocol network module") noexcept;
        };
        // class PacketError
        class PacketError: public Error {
            public:
                PacketError(std::string const &message, std::string const &component = "Packet system") noexcept;
        };
    }
}