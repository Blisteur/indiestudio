/*
** EPITECH PROJECT, 2022
** Window.cpp
** File description:
** Window
*/

#include "Window.hpp"

encapsulation::raylib::Window::Window(size_t width, size_t height, std::string title)
{
    if (!initWindow(width, height, title))
        throw encapsulation::raylib::RaylibError("Window initialization failed", "Window");
    SetExitKey(KEY_KB_MENU);
}

encapsulation::raylib::Window::~Window()
{
    CloseWindow();
}

bool encapsulation::raylib::Window::initWindow(size_t width, size_t height, std::string title)
{
    InitWindow(width, height, title.c_str());
    WindowShouldClose();
    SetExitKey(KEY_KB_MENU);
    return (IsWindowReady());
}

bool encapsulation::raylib::Window::windowShouldClose() const
{
    return (WindowShouldClose());
}

void encapsulation::raylib::Window::closeWindow()
{
    CloseWindow();
}

bool encapsulation::raylib::Window::isWindowFocused() const
{
    return (IsWindowFocused());
}

void encapsulation::raylib::Window::setWindowState(std::size_t flag)
{
    SetWindowState(flag);
}

void encapsulation::raylib::Window::clearBackground(const Color& color)
{
    ClearBackground(color);
}

void encapsulation::raylib::Window::setWindowIcon(const Image& image)
{
    SetWindowIcon(image);
}

void encapsulation::raylib::Window::setWindowSize(std::size_t width, std::size_t height)
{
    SetWindowSize(width, height);
}

void encapsulation::raylib::Window::beginDrawing(void)
{
    BeginDrawing();
}

void encapsulation::raylib::Window::endDrawing(void)
{
    EndDrawing();
}

void encapsulation::raylib::Window::setTargetFPS(std::size_t fps)
{
    SetTargetFPS(fps);
}

double encapsulation::raylib::Window::getTime(void) const
{
    return (GetTime());
}

std::size_t encapsulation::raylib::Window::getScreenWidth(void) const
{
    return (GetScreenWidth());
}

std::size_t encapsulation::raylib::Window::getScreenHeight(void) const
{
    return (GetScreenHeight());
}
