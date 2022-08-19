/*
** EPITECH PROJECT, 2022
** Saver class
** File description:
** IndieStudio
*/

#pragma once

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <iostream>

namespace Indie {
    class Saver {
        public:
            Saver() = default;
            ~Saver() = default;

            template <class Class>
            void saveConfig(Class& savedClass, std::string path)
            {
                std::ofstream ofs(path);
                {
                    boost::archive::text_oarchive oa(ofs);
                    oa << savedClass;
                }
            };
            template <class Class>
            bool loadConfig(Class& savedClass, std::string path)
            {
                {
                    std::ifstream ifs(path);
                    if (!ifs)
                        return false;
                    boost::archive::text_iarchive ia(ifs);
                    ia >> savedClass;
                }
                return true;
            };
        private:
        protected:
    };
};