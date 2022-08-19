/*
** EPITECH PROJECT, 2022
** Music.hpp
** File description:
** Music
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Music : public ::Music {
            public:
                Music(const ::Music&);
                Music(const std::string&);
                ~Music();

                void set(const ::Music&);
                void setMusicVolume(float);
                bool load(const std::string&);
                bool isMusicStreamPlaying() const;
                void unload();
                void updateMusicStream();
                void playMusicStream();
                void pauseMusicStream();
                void resumeMusicStream();
                void stopMusicStream();

            protected:
            private:
        };
    }
}
