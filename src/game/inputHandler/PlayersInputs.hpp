/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** PlayersInputs
*/

#pragma once

#include <list>
#include "../../raylib/keyboard/Keyboard.hpp"
#include "../../raylib/gamepad/Gamepad.hpp"

namespace Indie {
    namespace game {
        namespace inputHandler {
            class PlayersInputs {
                public:
                    enum KeyMode {
                        KEY_PRESSED,
                        KEY_DOWN,
                        KEY_RELEASED,
                        KEY_UP
                    };
                    PlayersInputs(const std::list<int> &watchedKeys);
                    ~PlayersInputs();
                    //get list of keys to watch and their mode
                    std::list<std::pair<int, KeyMode>> getInputs();
                    //set input to watch
                    void setInputsToWatched(const std::list<int> &watchedKeys);
                protected:
                private:
                    std::list<std::pair<int, KeyMode>> _keyboard;
                    encapsulation::raylib::Gamepad _gamepadRaylib;
                    encapsulation::raylib::Keyboard _keyboardRaylib;
            };
        }
    }
}
