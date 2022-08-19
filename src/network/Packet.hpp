/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** Packet
*/

#include <vector>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include "error/Error.hpp"

namespace Indie {
    namespace network {
        namespace packet {
            // Packet header
            struct packetHeader {
                uint32_t id;
                uint32_t size;
            };
            // Main packet
            struct packet {
                packetHeader header{};
                std::vector<uint16_t> body;

                // Return the packet size
                size_t size() const
                {
                    return sizeof(packetHeader) + body.size();
                }

                // Print the packet header
                friend std::ostream &operator<<(std::ostream &os, const packet &packet)
                {
                    os << "id: " << packet.header.id << " size: " << packet.header.size;
                    return os;
                }

                // Push any data into the packet
                template <typename Type>
                friend packet &operator<<(packet &packet, const Type &data)
                {
                    // Check if the data is OK
                    static_assert(std::is_standard_layout<Type>::value, "Type must be standard layout");

                    // Get tmp of data size
                    size_t tmp_size = packet.body.size();

                    // Resize vector
                    packet.body.resize(tmp_size + sizeof(Type));

                    //copy old data into the vector
                    std::memcpy(packet.body.data() + tmp_size, &data, sizeof(Type));

                    // Update packet size
                    packet.header.size = packet.size();

                    return (packet);
                }

                // Get any data from the packet in the right order
                template <typename Type>
                friend packet &operator>>(packet &packet, Type &data)
                {
                    // Check if the data is OK
                    static_assert(std::is_standard_layout<Type>::value, "Type must be standard layout");

                    // Check if the packet is OK
                    if (packet.body.size() < sizeof(Type))
                        throw Indie::network::PacketError("Packet is too small");

                    // Get tmp of data size
                    size_t tmp_size = packet.body.size() - sizeof(Type);

                    // Copy data into the right place
                    std::memcpy(&data, packet.body.data() + tmp_size, sizeof(Type));

                    // Shrink the vector to remove the data we just read
                    packet.body.resize(tmp_size);

                    // Update packet size
                    packet.header.size = packet.size();

                    return (packet);
                }
                friend class boost::serialization::access;
                // serialize the packet
                template <typename Archive>
                void serialize(Archive &ar, const unsigned int version)
                {
                    ar & header.id;
                    ar & header.size;
                    ar & body;
                }
            };
        }
    }
}
