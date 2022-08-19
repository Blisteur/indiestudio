/*
** EPITECH PROJECT, 2022
** Window.hpp
** File description:
** Window
*/

#pragma once
#include "../include.hpp"

namespace encapsulation {
    namespace raylib {
        class Window {
            public:
                Window() = default;
                Window(std::size_t, std::size_t, std::string);
                ~Window();

                bool initWindow(std::size_t, std::size_t, std::string);
                bool windowShouldClose() const;
                void closeWindow();
                bool isWindowFocused() const;
                void setWindowState(std::size_t);
                void clearBackground(const Color&);
                void setWindowIcon(const Image&);
                void setWindowSize(std::size_t, std::size_t);
                void beginDrawing(void);
                void endDrawing(void);
                void setTargetFPS(std::size_t);
                double getTime(void) const;
                std::size_t getScreenWidth(void) const;
                std::size_t getScreenHeight(void) const;

            protected:
            private:
        };
    }
}
