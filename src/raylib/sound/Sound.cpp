/*
** EPITECH PROJECT, 2022
** Sound.cpp
** File description:
** Sound
*/

#include "Sound.hpp"

encapsulation::raylib::Sound::Sound(const ::Sound& sound)
{
    this->set(sound);
}

encapsulation::raylib::Sound::Sound(AudioStream stream, unsigned int frameCount): ::Sound{stream, frameCount}
{
}

encapsulation::raylib::Sound::~Sound()
{
    UnloadSound(*this);
}

void encapsulation::raylib::Sound::set(const ::Sound& sound)
{
    stream = sound.stream;
    frameCount = sound.frameCount;
}

encapsulation::raylib::Sound& encapsulation::raylib::Sound::operator=(const ::Sound& sound)
{
    this->set(sound);
    return (*this);
}

bool encapsulation::raylib::Sound::loadSound(const std::string& filepath)
{
    this->set(LoadSound(filepath.c_str()));
    return (stream.buffer ? true : false);
}

bool encapsulation::raylib::Sound::loadSoundFromWave(const ::Wave& wave)
{
    this->set(LoadSoundFromWave(wave));
    return (stream.buffer ? true : false);
}

void encapsulation::raylib::Sound::playSound()
{
    PlaySound(*this);
}

void encapsulation::raylib::Sound::stopSound()
{
    StopSound(*this);
}

void encapsulation::raylib::Sound::pauseSound()
{
    PlaySound(*this);
}

void encapsulation::raylib::Sound::resumeSound()
{
    ResumeSound(*this);
}

void encapsulation::raylib::Sound::setSoundVolume(float volume)
{
    SetSoundVolume(*this, volume);
}

bool encapsulation::raylib::Sound::isSoundPlaying() const
{
    return (IsSoundPlaying(*this));
}
