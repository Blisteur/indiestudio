/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** TcpNetwork
*/

#include "TcpNetwork.hpp"

Indie::network::protocol::TcpNetwork::TcpNetwork(boost::asio::io_context &context, const std::string &dns, const std::string &port): _context(context), _dns(dns), _port(port), _socket(_context), _resolver(_context)
{
    _idPacket = 0;
    std::cout << "TcpNetwork created" << std::endl;
    boost::asio::ip::tcp::resolver::query query(this->_dns, this->_port);
    _resolver.async_resolve(query, std::bind(&TcpNetwork::resolverHandler, this, std::placeholders::_1, std::placeholders::_2));
}

Indie::network::protocol::TcpNetwork::~TcpNetwork()
{
}

void Indie::network::protocol::TcpNetwork::resolverHandler(const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator it)
{
    if (ec) {
        std::cerr << "Error: " << ec.message() << std::endl;
        throw Indie::network::ProtocolError(ec.message(), "TcpNetwork::resolverHandler");
    } else {
        std::cout << "Resolved IP: " << it->endpoint() << std::endl;
        this->_endpoint = it->endpoint();
        this->_socket.async_connect(this->_endpoint, std::bind(&TcpNetwork::connectHandler, this, std::placeholders::_1));
    }
}

void Indie::network::protocol::TcpNetwork::connectHandler(const boost::system::error_code &ec)
{
    if (ec) {
        std::cerr << "Error: " << ec.message() << std::endl;
        throw Indie::network::ProtocolError(ec.message(), "TcpNetwork::connectHandler");
    } else {
        std::cout << "Connected to " << this->_endpoint.address().to_string() << std::endl;
        std::stringstream ss;
        ss << "Hello from " << this->_endpoint.address().to_string() << ":" << this->_endpoint.port() << std::endl;
        boost::asio::write(this->_socket, boost::asio::buffer(ss.str()));
        this->receive();
    }
}

void Indie::network::protocol::TcpNetwork::readHandler(const boost::system::error_code &ec, std::size_t bytes)
{
    if (ec) {
        std::cerr << "Error: " << ec.message() << std::endl;
        throw Indie::network::ProtocolError(ec.message(), "TcpNetwork::readHandler");
    } else {
        ///deseerialize
        Indie::network::packet::packet packet;
        boost::asio::streambuf buffer;
        std::istream is(&buffer);
        boost::archive::binary_iarchive ia(is);
        ia >> packet;
        // std::cout << packet << std::endl;
        // std::cout << "Received: " << packet.body << std::endl;
        this->_socket.async_read_some(boost::asio::buffer(this->_buffer), std::bind(&TcpNetwork::readHandler, this, std::placeholders::_1, std::placeholders::_2));
    }
}

void Indie::network::protocol::TcpNetwork::writeHandler(const boost::system::error_code &ec, std::size_t bytes)
{
    if (ec) {
        std::cerr << "Error: " << ec.message() << std::endl;
        throw Indie::network::ProtocolError(ec.message(), "TcpNetwork::writeHandler");
    } else {
        std::cout << "Sent: " << bytes << std::endl;
    }
}

void Indie::network::protocol::TcpNetwork::send(Indie::network::packet::packet &packet)
{
    packet.header.id = this->_idPacket;
    this->_idPacket += 1;
    boost::asio::streambuf buffer;
    std::ostream os(&buffer);
    boost::archive::binary_oarchive oa(os);
    oa << packet << "\n";
    std::cout << packet << std::endl;
    _socket.send(boost::asio::buffer(buffer.data(), buffer.size()));
}

void Indie::network::protocol::TcpNetwork::receive()
{
    this->_socket.async_read_some(boost::asio::buffer(this->_buffer), std::bind(&TcpNetwork::readHandler, this, std::placeholders::_1, std::placeholders::_2));
}