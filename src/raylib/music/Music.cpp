/*
** EPITECH PROJECT, 2022
** Music.cpp
** File description:
** Music
*/

#include "Music.hpp"

encapsulation::raylib::Music::Music(const ::Music& music)
{
    this->set(music);
}

encapsulation::raylib::Music::Music(const std::string& filepath)
{
    this->set(LoadMusicStream(filepath.c_str()));
}

encapsulation::raylib::Music::~Music()
{
}

void encapsulation::raylib::Music::unload()
{
    UnloadMusicStream(*this);
}

void encapsulation::raylib::Music::set(const ::Music& music)
{
    stream = music.stream;
    frameCount = music.frameCount;
    looping = music.looping;
    ctxType = music.ctxType;
    ctxData = music.ctxData;
}

bool encapsulation::raylib::Music::load(const std::string& filepath)
{
    this->set(LoadMusicStream(filepath.c_str()));
    return (stream.buffer ? true : false);
}

void encapsulation::raylib::Music::updateMusicStream()
{
    UpdateMusicStream(*this);
}

void encapsulation::raylib::Music::playMusicStream()
{
    PlayMusicStream(*this);
}

void encapsulation::raylib::Music::pauseMusicStream()
{
    PauseMusicStream(*this);
}
void encapsulation::raylib::Music::resumeMusicStream()
{
    ResumeMusicStream(*this);
}
void encapsulation::raylib::Music::stopMusicStream()
{
    StopMusicStream(*this);
}

bool encapsulation::raylib::Music::isMusicStreamPlaying() const
{
    return (IsMusicStreamPlaying(*this));
}

void encapsulation::raylib::Music::setMusicVolume(float volume)
{
    SetMusicVolume(*this, volume);
}
