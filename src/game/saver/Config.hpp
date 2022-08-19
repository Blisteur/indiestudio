/*
** EPITECH PROJECT, 2022
** Config class
** File description:
** IndieStudio
*/

#pragma once

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace Indie {
    class Config {
        public:
            Config() = default;
            ~Config() = default;

            int sound_volume = 100;     // in %
            int music_volume = 100;     // in %
            int master_volume = 100;     // in %
            int sound_btn = 1580;      // in %
            int music_btn = 1580;      // in %
            int master_btn = 1580;       // in %
            int brightness = 100;       // in %
            int _texte_fps = 60;        //in %

            int entity0_up = 90;        // Z
            int entity0_down = 83;      // S
            int entity0_left = 81;      // Q
            int entity0_right = 68;     // D
            int entity0_place = 65;     // A

            int entity1_up = 73;        // I
            int entity1_down = 75;      // K
            int entity1_left = 74;      // J
            int entity1_right = 76;     // L
            int entity1_place = 79;     // O

            int entity2_up = 265;       // UP
            int entity2_down = 264;     // DOWN
            int entity2_left = 263;     // LEFT
            int entity2_right = 262;    // RIGHT
            int entity2_place = 32;     // SPACE

            int entity3_up = 84;        // T
            int entity3_down = 71;      // G
            int entity3_left = 70;      // F
            int entity3_right = 72;     // H
            int entity3_place = 82;     // R
        private:
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive &ar, const unsigned int version)
            {
                (void)version;
                ar & sound_volume;
                ar & music_volume;
                ar & master_volume;
                ar & sound_btn;
                ar & music_btn;
                ar & master_btn;
                ar & brightness;
                ar & entity0_up;
                ar & _texte_fps;

                ar & entity0_down;
                ar & entity0_left;
                ar & entity0_right;
                ar & entity0_place;

                ar & entity1_down;
                ar & entity1_left;
                ar & entity1_right;
                ar & entity1_place;

                ar & entity2_down;
                ar & entity2_left;
                ar & entity2_right;
                ar & entity2_place;

                ar & entity3_down;
                ar & entity3_left;
                ar & entity3_right;
                ar & entity3_place;
            }
        protected:
    };
};