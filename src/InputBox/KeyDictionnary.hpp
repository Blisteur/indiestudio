/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** KeyDictionnary.hpp
*/

#include <iostream>

#ifndef BOMBERMAN_KEYDICTIONNARY_HPP
#define BOMBERMAN_KEYDICTIONNARY_HPP

class KeyDictionnary {
public:
    KeyDictionnary() = default;
    std::string getStringFromKey(int key) const;
};

#endif //BOMBERMAN_KEYDICTIONNARY_HPP
