/*
** EPITECH PROJECT, 2022
** Sound.hpp
** File description:
** Sound
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Sound : public ::Sound {
            public:
                Sound(const ::Sound&);
                Sound(AudioStream, unsigned int);
                ~Sound();

                void set(const ::Sound&);
                bool loadSound(const std::string&);
                bool loadSoundFromWave(const Wave&);
                void playSound();
                void stopSound();
                void pauseSound();
                void resumeSound();
                void setSoundVolume(float);
                bool isSoundPlaying() const;

                Sound& operator=(const ::Sound&);
            protected:
            private:
        };
    }
}
