/*
** EPITECH PROJECT, 2022
** Ia
** File description:
** Ia
*/

#include "Ia.hpp"

Indie::gameEngine::Ia::Ia(std::pair<float, float> player_pos, std::vector<std::vector<char>> actualMap, std::list<std::tuple<float, float, float>> bombPos)
{
    this->_charMap = actualMap;
    this->_bombs_pos = bombPos;
    this->where_they_go = -1;
    this->willBombBePlaced = false;
    this->_player_pos = player_pos;
    this->_goal_pos = this->_player_pos;
    this->fillVarsAndMap();
    this->setNewGoal();
    this->updatePos();
}

void Indie::gameEngine::Ia::updatePos()
{
    //std::shared_ptr<>
}


void Indie::gameEngine::Ia::fillVarsAndMap()
{
    for (auto &value : this->_bombs_pos) {
        for (unsigned long int i = 1, x = std::get<1>(value) - 1; x > 0 && i < std::get<2>(value); i++, x--) {
            if (this->_charMap[x][std::get<0>(value)] == 'X'
                || this->_charMap[x][std::get<0>(value)] == 'I'
                || this->_charMap[x][std::get<0>(value)] == 'B')
                break;
            if (this->_charMap[x][std::get<0>(value)] == 'E') continue;
            this->_charMap[x][std::get<0>(value)] = '|';
        }
        for (unsigned long int i = 1, x = std::get<1>(value) + 1; x < 33 && i < std::get<2>(value); i++, x++) {
            if (this->_charMap[x][std::get<0>(value)] == 'X'
            || this->_charMap[x][std::get<0>(value)] == 'I'
            || this->_charMap[x][std::get<0>(value)] == 'B')
                break;
            if (this->_charMap[x][std::get<0>(value)] == 'E') continue;
            this->_charMap[x][std::get<0>(value)] = '|';
        }
        for (unsigned long int i = 1, x = std::get<0>(value) - 1; x > 0 && i < std::get<2>(value); i++, x--) {
            if (this->_charMap[std::get<1>(value)][x] == 'X'
            || this->_charMap[std::get<1>(value)][x] == 'I'
            || this->_charMap[std::get<1>(value)][x] == 'B')
                break;
            if (this->_charMap[std::get<1>(value)][x] == 'E') continue;
            this->_charMap[std::get<1>(value)][x] = '|';
        }
        for (unsigned long int i = 1, x = std::get<0>(value) + 1; x < 17 && i < std::get<2>(value); i++, x++) {
            if (this->_charMap[std::get<1>(value)][x] == 'X'
            || this->_charMap[std::get<1>(value)][x] == 'I'
            || this->_charMap[std::get<1>(value)][x] == 'B')
                break;
            if (this->_charMap[std::get<1>(value)][x] == 'E') continue;
            this->_charMap[std::get<1>(value)][x] = '|';
        }
    }
}

int Indie::gameEngine::Ia::isSolid(int line, int column) const
{
    if (this->_charMap[line][column] == 'X' ||
    this->_charMap[line][column] == 'I' ||
    this->_charMap[line][column] == 'B' ) {
        return (true);
    }
    return (false);
}

int Indie::gameEngine::Ia::isDangerousZone(int line, int column) const
{
    if (this->_charMap[line][column] == '|' ||
    this->_charMap[line][column] == 'B' ) {
        return (true);
    }
    return (false);
}

void Indie::gameEngine::Ia::setNewGoal()
{
    int bomb = rand() % 50;
    int random = rand() % 4;
    int dir[4] = {1, 1, -1, -1};

    if (random == 0) {
        if (isSolid(std::get<1>(_player_pos), std::get<0>(_player_pos) + dir[random]) == false) {
            this->_goal_pos = std::make_pair(std::get<0>(_player_pos)  + dir[random], (std::get<1>(_player_pos)));
            if (bomb == 0) this->putBomb();
            return;
        }
    }
    if (random == 1) {
        if (isSolid(std::get<1>(_player_pos) + dir[random], std::get<0>(_player_pos)) == false) {
            this->_goal_pos = std::make_pair(std::get<0>(_player_pos), (std::get<1>(_player_pos) + dir[random]));
            if (bomb == 0) this->putBomb();
            return;
        }
    }
    if (random == 2) {
        if (isSolid(std::get<1>(_player_pos) + dir[random], std::get<0>(_player_pos)) == false) {
            this->_goal_pos = std::make_pair(std::get<0>(_player_pos), std::get<1>(_player_pos) + dir[random]);
            if (bomb == 0) this->putBomb();
            return;
        }
    }
    if (random == 3) {
        if (isSolid(std::get<1>(_player_pos), std::get<0>(_player_pos) + dir[random]) == false) {
            this->_goal_pos = std::make_pair(std::get<0>(_player_pos)  + dir[random], (std::get<1>(_player_pos)));
            if (bomb == 0) this->putBomb();
            return;
        }
    }

}

void Indie::gameEngine::Ia::putBomb()
{
    std::cout << "Explosion INCOMING" << std::endl;
    this->willBombBePlaced = true;
}

bool Indie::gameEngine::Ia::getWillBombBePlaced()
{
    return (this->willBombBePlaced);
}

std::pair<float, float> Indie::gameEngine::Ia::getPlayerPos() const
{
    return (this->_player_pos);
}

std::list<std::tuple<float, float, float>> Indie::gameEngine::Ia::getBombPos() const
{
    return (this->_bombs_pos);
}

std::pair<float, float> Indie::gameEngine::Ia::getGoalPos() const
{
    return (_goal_pos);
}

Indie::gameEngine::Ia::~Ia()
{

}