/*
** EPITECH PROJECT, 2022
** Error class
** File description:
** IndieStudio
*/

#include <string>

namespace Indie
{
    namespace engine
    {
        // Error mother class
        class Error: public std::exception {
            public:
                Error(std::string const &message, std::string const &component = "Unknown") noexcept;
                const char *what() const noexcept override {return _message.data();};
            protected:
                std::string _message;
                std::string _component;
            private:
        };
        // fileError
        class fileError: public Error {
            public:
                fileError(std::string const &message, std::string const &component = "File error");
            private:
        };
    }
}