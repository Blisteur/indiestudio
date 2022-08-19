/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Network
*/

#include "Network.hpp"


Indie::Network::Network()
{
    std::string dns = "127.0.0.1";
    std::string port = "1234";
    this->_tcp = std::make_unique<Indie::network::protocol::TcpNetwork>(this->_io_context, dns, port);
    std::cout << "Network created" << std::endl;
    this->_thread = std::thread([&]() { this->_io_context.run(); });
    std::cout << "Network run" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Indie::network::packet::packet packet;
    size_t id = 0;
    size_t input = 3;
    packet << id << input;
    std::cout << packet << std::endl;
    this->_tcp->send(packet);
    for (int i = 0; i < 10000; i++) {
        this->_tcp->send(packet);
        packet >> id >> input;
        id = rand() % 100;
        input = rand() % 100;
        packet << id << input;
    }
    // serveur renvoie
    // size_t uid = 0;
    // size_t id = 0;
    // std::tuple<size_t, size_t, size_t> input;
    // short int status = 0;

}

Indie::Network::Network(const std::string &dns, const std::string &port)
{
}

Indie::Network::~Network()
{
}
