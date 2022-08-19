/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** TcpNetwork
*/

#pragma once

#include <boost/beast/core.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <thread>
#include "../error/Error.hpp"
#include "../Packet.hpp"

namespace Indie {
    namespace network {
        namespace protocol {
            class TcpNetwork {
                public:
                    TcpNetwork(boost::asio::io_context &context, const std::string &dns, const std::string &port);
                    ~TcpNetwork();
                    //void tickLoop();
                    void send(Indie::network::packet::packet &packet);
                    void receive();
                protected:
                    void resolverHandler(const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator it);
                    void connectHandler(const boost::system::error_code &ec);
                    void readHandler(const boost::system::error_code &ec, std::size_t bytes);
                    void writeHandler(const boost::system::error_code &ec, std::size_t bytes);
                private:
                    std::array<char, 4096> _buffer;
                    boost::asio::io_context &_context;
                    std::string _dns;
                    std::string _port;
                    boost::asio::ip::tcp::socket _socket;
                    boost::asio::ip::tcp::endpoint _endpoint;
                    boost::asio::ip::tcp::resolver _resolver;
                    uint32_t _idPacket;
            };
        }
    }
}
