/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCY-4-1-Indiestudio-antoine.gasser
** File description:
** main
*/

#include "raylib.h"

#include "../game/inputHandler/InputHandler.hpp"
#include "../game/inputHandler/KeyBoardKeys.hpp"
#include "../game/inputHandler/PlayersInputs.hpp"
#include "../game/sceneHandler/SceneHandler.hpp"
#include "../game/sceneHandler/SceneMain.hpp"
#include "../game/sceneHandler/SceneSplash.hpp"
#include "./GameEngine.hpp"
#include "entity/Player.hpp"
#include "../InputBox/InputBox.hpp"

#include <memory>

int main(void)
{
//    Indie::Saver saver;

    Indie::game::inputHandler::PlayersInputs player1(std::list<int>({
        Indie::game::inputHandler::KeyboardKey::KEY_W,
        Indie::game::inputHandler::KeyboardKey::KEY_S,
        Indie::game::inputHandler::KeyboardKey::KEY_A,
        Indie::game::inputHandler::KeyboardKey::KEY_D,
        Indie::game::inputHandler::KeyboardKey::KEY_SPACE,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    Indie::game::inputHandler::PlayersInputs player2(std::list<int>({
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_RIGHT_UP,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_RIGHT_DOWN,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_RIGHT_LEFT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_RIGHT_RIGHT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_LEFT_UP,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_LEFT_DOWN,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_LEFT_LEFT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_JOSTICK_LEFT_RIGHT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_FACE_DOWN,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_FACE_UP,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_FACE_LEFT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_FACE_RIGHT,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_TRIGGER_1,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_TRIGGER_2,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_RIGHT_THUMB,
        Indie::game::inputHandler::KeyboardKey::GAMEPAD_BUTTON_LEFT_THUMB,
        Indie::game::inputHandler::KeyboardKey::KEY_ESCAPE
    }));
    Indie::game::InputHandler inputHandler(std::list<Indie::game::inputHandler::PlayersInputs>({player1, player2}));
    Indie::game::sceneHandler::SceneHandler sceneHandler;

//    saver.loadConfig<Indie::Config>(sceneHandler._config, "config");
    srand(time(NULL));
    sceneHandler.getWindow().initWindow(1920, 1080, "Bomberman");
    sceneHandler.getWindow().setTargetFPS(sceneHandler._config._texte_fps);
    sceneHandler.getWindow().setWindowState(FLAG_FULLSCREEN_MODE);
    sceneHandler.pushScene(std::unique_ptr<Indie::game::sceneHandler::IScene>(new Indie::game::sceneHandler::SceneSplash(sceneHandler)));

    while (!WindowShouldClose() && sceneHandler.getStatus())
    {
        sceneHandler.gameLoop();
    }
//    saver.saveConfig<Indie::Config>(sceneHandler._config, "config");
    return 0;
}