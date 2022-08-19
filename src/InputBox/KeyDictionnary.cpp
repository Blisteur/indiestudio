/*
** EPITECH PROJECT, 2022
** bomberman
** File description:
** KeyDictionnary.cpp
*/

#include "KeyDictionnary.hpp"

std::string KeyDictionnary::getStringFromKey(int key) const {
    std::string s_return;
    switch (key) {
        case 32:
            s_return = "SP";
            break;
        case 39:
            s_return = "'";
            break;
        case 44:
            s_return = ",";
            break;
        case 45:
            s_return = "-";
            break;
        case 46:
            s_return = "PERIOD";
            break;
        case 47:
            s_return = "/";
            break;
        case 48:
            s_return = "0";
            break;
        case 49:
            s_return = "1";
            break;
        case 50:
            s_return = "2";
            break;
        case 51:
            s_return = "3";
            break;
        case 52:
            s_return = "4";
            break;
        case 53:
            s_return = "5";
            break;
        case 54:
            s_return = "6";
            break;
        case 55:
            s_return = "7";
            break;
        case 56:
            s_return = "8";
            break;
        case 57:
            s_return = "9";
            break;
        case 59:
            s_return = "SEMICOLON";
            break;
        case 61:
            s_return = "=";
            break;
        case 65:
            s_return = "A";
            break;
        case 66:
            s_return = "B";
            break;
        case 67:
            s_return = "C";
            break;
        case 68:
            s_return = "D";
            break;
        case 69:
            s_return = "E";
            break;
        case 70:
            s_return = "F";
            break;
        case 71:
            s_return = "G";
            break;
        case 72:
            s_return = "H";
            break;
        case 73:
            s_return = "I";
            break;
        case 74:
            s_return = "J";
            break;
        case 75:
            s_return = "K";
            break;
        case 76:
            s_return = "L";
            break;
        case 77:
            s_return = "M";
            break;
        case 78:
            s_return = "N";
            break;
        case 79:
            s_return = "O";
            break;
        case 80:
            s_return = "P";
            break;
        case 81:
            s_return = "Q";
            break;
        case 82:
            s_return = "R";
            break;
        case 83:
            s_return = "S";
            break;
        case 84:
            s_return = "T";
            break;
        case 85:
            s_return = "U";
            break;
        case 86:
            s_return = "V";
            break;
        case 87:
            s_return = "W";
            break;
        case 88:
            s_return = "X";
            break;
        case 89:
            s_return = "Y";
            break;
        case 90:
            s_return = "Z";
            break;
        case 91:
            s_return = "[";
            break;
        case 92:
            s_return = "\\";
            break;
        case 93:
            s_return = "]";
            break;
        case 96:
            s_return = "GRAVE";
            break;
        case 256:
            s_return = "ESP";
            break;
        case 257:
            s_return = "ENT";
            break;
        case 258:
            s_return = "TAB";
            break;
        case 259:
            s_return = "BACKSPACE";
            break;
        case 260:
            s_return = "INSERT";
            break;
        case 261:
            s_return = "DELETE";
            break;
        case 262:
            s_return = "→";
            break;
        case 263:
            s_return = "←";
            break;
        case 264:
            s_return = "↓";
            break;
        case 265:
            s_return = "↑";
            break;
        case 266:
            s_return = "PAGE_UP";
            break;
        case 267:
            s_return = "PAGE_DOWN";
            break;
        case 268:
            s_return = "HOME";
            break;
        case 269:
            s_return = "END";
            break;
        case 280:
            s_return = "CAPS_LOCK";
            break;
        case 281:
            s_return = "SCROLL_LOCK";
            break;
        case 282:
            s_return = "NUM_LOCK";
            break;
        case 283:
            s_return = "PRINT_SCREEN";
            break;
        case 284:
            s_return = "PAUSE";
            break;
        case 290:
            s_return = "F1";
            break;
        case 291:
            s_return = "F2";
            break;
        case 292:
            s_return = "F3";
            break;
        case 293:
            s_return = "F4";
            break;
        case 294:
            s_return = "F5";
            break;
        case 295:
            s_return = "F6";
            break;
        case 296:
            s_return = "F7";
            break;
        case 297:
            s_return = "F8";
            break;
        case 298:
            s_return = "F9";
            break;
        case 299:
            s_return = "F10";
            break;
        case 300:
            s_return = "F11";
            break;
        case 301:
            s_return = "F12";
            break;
        case 340:
            s_return = "LEFT_SHIFT";
            break;
        case 341:
            s_return = "LEFT_CONTROL";
            break;
        case 342:
            s_return = "LEFT_ALT";
            break;
        case 343:
            s_return = "LEFT_SUPER";
            break;
        case 344:
            s_return = "RIGHT_SHIFT";
            break;
        case 345:
            s_return = "RIGHT_CONTROL";
            break;
        case 346:
            s_return = "RIGHT_ALT";
            break;
        case 347:
            s_return = "RIGHT_SUPER";
            break;
        case 348:
            s_return = "KB_MENU";
            break;
        default:
            s_return = "NONE";
    }
    return s_return;
}
/**
KEY_ APOSTROPHE      = 39,       // Key: '
KEY_ COMMA           = 44,       // Key: ,
KEY_ MINUS           = 45,       // Key: -
KEY_ PERIOD          = 46,       // Key: .
KEY_ SLASH           = 47,       // Key: /
KEY_ ZERO            = 48,       // Key: 0
KEY_ ONE             = 49,       // Key: 1
KEY_ TWO             = 50,       // Key: 2
KEY_ THREE           = 51,       // Key: 3
KEY_ FOUR            = 52,       // Key: 4
KEY_ FIVE            = 53,       // Key: 5
KEY_ SIX             = 54,       // Key: 6
KEY_ SEVEN           = 55,       // Key: 7
KEY_ EIGHT           = 56,       // Key: 8
KEY_ NINE            = 57,       // Key: 9
KEY_ SEMICOLON       = 59,       // Key: ;
KEY_ EQUAL           = 61,       // Key: =
KEY_ A               = 65,       // Key: A | a
KEY_ B               = 66,       // Key: B | b
KEY_ C               = 67,       // Key: C | c
KEY_ D               = 68,       // Key: D | d
KEY_ E               = 69,       // Key: E | e
KEY_ F               = 70,       // Key: F | f
KEY_ G               = 71,       // Key: G | g
KEY_ H               = 72,       // Key: H | h
KEY_ I               = 73,       // Key: I | i
KEY_ J               = 74,       // Key: J | j
KEY_ K               = 75,       // Key: K | k
KEY_ L               = 76,       // Key: L | l
KEY_ M               = 77,       // Key: M | m
KEY_ N               = 78,       // Key: N | n
KEY_ O               = 79,       // Key: O | o
KEY_ P               = 80,       // Key: P | p
KEY_ Q               = 81,       // Key: Q | q
KEY_ R               = 82,       // Key: R | r
KEY_ S               = 83,       // Key: S | s
KEY_ T               = 84,       // Key: T | t
KEY_ U               = 85,       // Key: U | u
KEY_ V               = 86,       // Key: V | v
KEY_ W               = 87,       // Key: W | w
KEY_ X               = 88,       // Key: X | x
KEY_ Y               = 89,       // Key: Y | y
KEY_ Z               = 90,       // Key: Z | z
KEY_ LEFT_BRACKET    = 91,       // Key: [
KEY_ BACKSLASH       = 92,       // Key: '\'
KEY_ RIGHT_BRACKET   = 93,       // Key: ]
KEY_ GRAVE           = 96,       // Key: `
// F unction keys
KEY_ SPACE           = 32,       // Key: Space
KEY_ ESCAPE          = 256,      // Key: Esc
KEY_ ENTER           = 257,      // Key: Enter
KEY_ TAB             = 258,      // Key: Tab
KEY_ BACKSPACE       = 259,      // Key: Backspace
KEY_ INSERT          = 260,      // Key: Ins
KEY_ DELETE          = 261,      // Key: Del
KEY_ RIGHT           = 262,      // Key: Cursor right
KEY_ LEFT            = 263,      // Key: Cursor left
KEY_ DOWN            = 264,      // Key: Cursor down
KEY_ UP              = 265,      // Key: Cursor up
KEY_ PAGE_UP         = 266,      // Key: Page up
KEY_ PAGE_DOWN       = 267,      // Key: Page down
KEY_ HOME            = 268,      // Key: Home
KEY_ END             = 269,      // Key: End
KEY_ CAPS_LOCK       = 280,      // Key: Caps lock
KEY_ SCROLL_LOCK     = 281,      // Key: Scroll down
KEY_ NUM_LOCK        = 282,      // Key: Num lock
KEY_ PRINT_SCREEN    = 283,      // Key: Print screen
KEY_ PAUSE           = 284,      // Key: Pause
KEY_ F1              = 290,      // Key: F1
KEY_ F2              = 291,      // Key: F2
KEY_ F3              = 292,      // Key: F3
KEY_ F4              = 293,      // Key: F4
KEY_ F5              = 294,      // Key: F5
KEY_ F6              = 295,      // Key: F6
KEY_ F7              = 296,      // Key: F7
KEY_ F8              = 297,      // Key: F8
KEY_ F9              = 298,      // Key: F9
KEY_ F10             = 299,      // Key: F10
KEY_ F11             = 300,      // Key: F11
KEY_ F12             = 301,      // Key: F12
KEY_ LEFT_SHIFT      = 340,      // Key: Shift left
KEY_ LEFT_CONTROL    = 341,      // Key: Control left
KEY_ LEFT_ALT        = 342,      // Key: Alt left
KEY_ LEFT_SUPER      = 343,      // Key: Super left
KEY_ RIGHT_SHIFT     = 344,      // Key: Shift right
KEY_ RIGHT_CONTROL   = 345,      // Key: Control right
KEY_ RIGHT_ALT       = 346,      // Key: Alt right
KEY_ RIGHT_SUPER     = 347,      // Key: Super right
KEY_ KB_MENU         = 348,      // Key: KB menu
// K eypad keys
KEY_ KP_0            = 320,      // Key: Keypad 0
KEY_ KP_1            = 321,      // Key: Keypad 1
KEY_ KP_2            = 322,      // Key: Keypad 2
KEY_ KP_3            = 323,      // Key: Keypad 3
KEY_ KP_4            = 324,      // Key: Keypad 4
KEY_ KP_5            = 325,      // Key: Keypad 5
KEY_ KP_6            = 326,      // Key: Keypad 6
KEY_ KP_7            = 327,      // Key: Keypad 7
KEY_ KP_8            = 328,      // Key: Keypad 8
KEY_ KP_9            = 329,      // Key: Keypad 9
KEY_ KP_DECIMAL      = 330,      // Key: Keypad .
KEY_ KP_DIVIDE       = 331,      // Key: Keypad /
KEY_ KP_MULTIPLY     = 332,      // Key: Keypad *
KEY_ KP_SUBTRACT     = 333,      // Key: Keypad -
KEY_ KP_ADD          = 334,      // Key: Keypad +
KEY_ KP_ENTER        = 335,      // Key: Keypad Enter
KEY_ KP_EQUAL        = 336,      // Key: Keypad =
**/ 