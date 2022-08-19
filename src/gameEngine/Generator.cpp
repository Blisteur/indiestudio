/*
** EPITECH PROJECT, 2022
** Generator.cpp
** File description:
** indiestudio
*/

#include "Generator.hpp"

Indie::Generator::Generator()
{
    Indie::engine::Map generatedMap("path_to_box", "BOX");

    for (int i = 0; i != 17; i++) {
        std::vector <Indie::engine::Map> line = {};

        for (int j = 0; j != 33; j++)
            line.push_back(generatedMap);
        this->_map.push_back(line);
    }
    generatNewMap();
}

Indie::Generator::~Generator()
{

}

std::vector<std::vector<Indie::engine::Map>> &Indie::Generator::getMap()
{
    return (this->_map);
}

void Indie::Generator::generatNewMap()
{
    Indie::engine::Map wallMap("path_to_wall", "WALL");
    Indie::engine::Map emptyMap("path_to_empty", "EMPTY");

    srand(time(nullptr));
    for (int i = 0; i != (int)this->_map.size(); i++) {
        for (int j = 0; j != (int)this->_map[i].size(); j++) {
            if (j == 0 || j == (int)this->_map[i].size() - 1)
                this->_map[i][j] = wallMap;
            if (i == 0 || i == (int)this->_map.size() - 1)
                this->_map[i][j] = wallMap;
            if (j % 2 == 0 && i % 2 == 0)
                this->_map[i][j] = wallMap;
            if ((i - 1) < 0 || (i + 1) > (int)this->_map.size() - 1)
                continue;
            if ((j - 1) < 0 || (j + 1) > (int)this->_map[i].size() - 1)
                continue;
            if (j % 2 == 0 && i % 2 == 0) {
                if (rand() % 10 + 1 == 2)
                    this->_map[i - 1][j] = wallMap;
                if (rand() % 10 + 1 == 2)
                    this->_map[i + 1][j] = wallMap;
                if (rand() % 10 + 1 == 2)
                    this->_map[i][j + 1] = wallMap;
                if (rand() % 10 + 1 == 2)
                    this->_map[i - 1][j - 1] = wallMap;
            }
        }
    }
    this->_map[1][1] = emptyMap;
    this->_map[2][1] = emptyMap;      //TOP LEFT
    this->_map[1][2] = emptyMap;

    this->_map[1][31] = emptyMap;
    this->_map[1][30] = emptyMap;     //TOP RIGHT
    this->_map[2][31] = emptyMap;

    this->_map[15][1] = emptyMap;
    this->_map[14][1] = emptyMap;     //BOT LEFT
    this->_map[15][2] = emptyMap;

    this->_map[15][30] = emptyMap;
    this->_map[14][31] = emptyMap;      //BOT RIGHT
    this->_map[15][31] = emptyMap;
}