/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-indiestudio-antoine.gasser
** File description:
** PlayersInputs
*/

#include "PlayersInputs.hpp"

Indie::game::inputHandler::PlayersInputs::PlayersInputs(const std::list<int> &watchedKeys): _gamepadRaylib(encapsulation::raylib::Gamepad(0))
{
    for (auto &key : watchedKeys) {
        _keyboard.push_back(std::make_pair(key, KEY_UP));
    }
}

Indie::game::inputHandler::PlayersInputs::~PlayersInputs()
{
}

void Indie::game::inputHandler::PlayersInputs::setInputsToWatched(const std::list<int> &watchedKeys)
{
    _keyboard.clear();
    for (const auto &key : watchedKeys)
        _keyboard.push_back(std::make_pair(key, KEY_UP));
}

std::list<std::pair<int, Indie::game::inputHandler::PlayersInputs::KeyMode>> Indie::game::inputHandler::PlayersInputs::getInputs()
{
    for (auto &keys : _keyboard) {
        if (keys.first >= 500 && keys.first <= 517) {
            if (_gamepadRaylib.isGamepadButtonDown(static_cast<KeyboardKey>(keys.first - 500)))
                keys.second = KEY_DOWN;
            else if (_gamepadRaylib.isGamepadButtonPressed(static_cast<KeyboardKey>(keys.first - 500)))
                keys.second = KEY_PRESSED;
            else if (_gamepadRaylib.isGamepadButtonReleased(static_cast<KeyboardKey>(keys.first - 500)))
                keys.second = KEY_RELEASED;
            else if (_gamepadRaylib.isGamepadButtonUp(static_cast<KeyboardKey>(keys.first - 500)))
                keys.second = KEY_UP;
            else
                keys.second = KEY_UP;
        } else if (keys.first > 517) {
            //printf("%d\n", keys.first);
            std::pair<float, float> joystick_left;
            std::pair<float, float> joystick_right;
            joystick_left = std::make_pair(_gamepadRaylib.getGamepadAxisMovement(GAMEPAD_AXIS_LEFT_X), _gamepadRaylib.getGamepadAxisMovement(GAMEPAD_AXIS_LEFT_Y));
            joystick_right = std::make_pair(_gamepadRaylib.getGamepadAxisMovement(GAMEPAD_AXIS_RIGHT_X), _gamepadRaylib.getGamepadAxisMovement(GAMEPAD_AXIS_RIGHT_Y));
            if (keys.first == 518) {
                if (joystick_left.second > 0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 519) {
                if (joystick_left.second < -0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 520) {
                if (joystick_left.first < -0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 521) {
                if (joystick_left.first > 0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 522) {
                if (joystick_right.second > 0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 523) {
                if (joystick_right.second < -0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 524) {
                if (joystick_right.first < -0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
            if (keys.first == 525) {
                if (joystick_right.first > 0.2)
                    keys.second = KEY_DOWN;
                else
                    keys.second = KEY_UP;
            }
        } else {
            if (_keyboardRaylib.isKeyPressed(static_cast<KeyboardKey>(keys.first)))
                keys.second = KEY_PRESSED;
            else if (_keyboardRaylib.isKeyDown(static_cast<KeyboardKey>(keys.first)))
                keys.second = KEY_DOWN;
            else if (_keyboardRaylib.isKeyReleased(static_cast<KeyboardKey>(keys.first)))
                keys.second = KEY_RELEASED;
            else if (_keyboardRaylib.isKeyUp(static_cast<KeyboardKey>(keys.first)))
                keys.second = KEY_UP;
            else
                keys.second = KEY_UP;
        }
    }
    return (_keyboard);
}