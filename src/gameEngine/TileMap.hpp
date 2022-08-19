/*
** EPITECH PROJECT, 2022
** Tilemap class
** File description:
** IndieStudio
*/

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <array>
#include <vector>

namespace Indie {
    namespace engine {
        class Map {
            public :
                Map();
                Map(std::string path, std::string type);
                ~Map();

                        /*  All setters  */
                void setAsset(std::string path);
                void setType(std::string type);

                        /*  All getters  */
                std::string getAsset() const;
                std::string getType() const;
            private :
                std::string _asset;
                std::string _type;
            protected :
        };
    };
};