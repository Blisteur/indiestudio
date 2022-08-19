/*
** EPITECH PROJECT, 2022
** Tilemap class
** File description:
** IndieStudio
*/

#include "TileMap.hpp"

Indie::engine::Map::Map()
{
    this->_asset = "Mettre un default sprite";
    this->_type = " ";
}

Indie::engine::Map::Map(std::string const path, std::string const type)
{
    this->_asset = path;
    this->_type = type;
}

Indie::engine::Map::~Map()
{

}

std::string Indie::engine::Map::getAsset() const
{
    return (this->_asset);
}

std::string Indie::engine::Map::getType() const
{
    return (this->_type);
}

void Indie::engine::Map::setAsset(std::string const path)
{
    this->_asset = path;
}

void Indie::engine::Map::setType(std::string const type)
{
    this->_type = type;
}
