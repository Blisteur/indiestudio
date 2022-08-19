/*
** EPITECH PROJECT, 2022
** Generator.hpp
** File description:
** indiestudio
*/

#pragma once

#include <vector>
#include <iostream>
#include "TileMap.hpp"

namespace Indie {
    enum Type { WALL, EMPTY, BOX };

    class Generator {
        public :
            Generator();
            ~Generator();

            /*  All getters  */
            std::vector<std::vector<Indie::engine::Map> > & getMap();

            void generatNewMap();
        private :
            std::vector<std::vector<Indie::engine::Map> > _map;
        protected :
    };
};