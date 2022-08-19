/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Network
*/

#pragma once

#include <boost/beast/core.hpp>
#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <thread>
#include <tuple>
#include "protocol/TcpNetwork.hpp"

namespace Indie {
    class Network {
        public:
            Network();
            Network(const std::string &ip, const std::string &port);
            ~Network();

            std::unique_ptr<Indie::network::protocol::TcpNetwork> _tcp;
        protected:
            void resolverHandler(boost::asio::io_context &io_context, const std::string &dns, const std::string &port, const std::string &type);
            void connectionHandler(boost::asio::io_context &io_context, const std::string &type);

        private:
            boost::asio::io_context _io_context;
            std::string _ip;
            std::string _port;
            std::thread _thread;
    };
}