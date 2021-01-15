#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include "../IInputElement.h"

namespace Gio::Input::Devices
{
    class KeyboardKey : public IInputElement
    {
    public:
        enum Types : int
        {
            Unknown = -1,
            Space = 32,
            Apostrophe = 39,
            Comma = 44,
            Minus = 45,
            Period = 46,
            Slash = 47,
            AlphaNumeric_0 = 48,
            AlphaNumeric_1 = 49,
            AlphaNumeric_2 = 50,
            AlphaNumeric_3 = 51,
            AlphaNumeric_4 = 52,
            AlphaNumeric_5 = 53,
            AlphaNumeric_6 = 54,
            AlphaNumeric_7 = 55,
            AlphaNumeric_8 = 56,
            AlphaNumeric_9 = 57,
            SemiColon = 59,
            Equal = 61,
            A = 65,
            B = 66,
            C = 67,
            D = 68,
            E = 69,
            F = 70,
            G = 71,
            H = 72,
            I = 73,
            J = 74,
            K = 75,
            L = 76,
            M = 77,
            N = 78,
            O = 79,
            P = 80,
            Q = 81,
            R = 82,
            S = 83,
            T = 84,
            U = 85,
            V = 86,
            W = 87,
            X = 88,
            Y = 89,
            Z = 90,
            Left_Bracket = 91,
            Backslash = 92,
            Right_Bracket = 93,
            Grave_Accent = 96,
            World_1 = 161,
            World_2 = 162,
            Escape = 256,
            Enter = 257,
            Tab = 258,
            Backspace = 259,
            Insert = 260,
            Delete = 261,
            Arrow_Right = 262,
            Arrow_Left = 263,
            Arrow_Down = 264,
            Arrow_Up = 265,
            Page_Up = 266,
            Page_Down = 267,
            Home = 268,
            End = 269,
            CapsLock = 280,
            ScrollLock = 281,
            NumLock = 282,
            PrintScreen = 283,
            Pause = 284,
            F1 = 290,
            F2 = 291,
            F3 = 292,
            F4 = 293,
            F5 = 294,
            F6 = 295,
            F7 = 296,
            F8 = 297,
            F9 = 298,
            F10 = 299,
            F11 = 300,
            F12 = 301,
            F13 = 302,
            F14 = 303,
            F15 = 304,
            F16 = 305,
            F17 = 306,
            F18 = 307,
            F19 = 308,
            F20 = 309,
            F21 = 310,
            F22 = 311,
            F23 = 312,
            F24 = 313,
            F25 = 314,
            Keypad_0 = 320,
            Keypad_1 = 321,
            Keypad_2 = 322,
            Keypad_3 = 323,
            Keypad_4 = 324,
            Keypad_5 = 325,
            Keypad_6 = 326,
            Keypad_7 = 327,
            Keypad_8 = 328,
            Keypad_9 = 329,
            Keypad_Decimal = 330,
            Keypad_Divide = 331,
            Keypad_Multiply = 332,
            Keypad_Subtract = 333,
            Keypad_Add = 334,
            Keypad_Enter = 335,
            Keypad_Equal = 336,
            Shift_Left = 340,
            Control_Left = 341,
            Alt_Left = 342,
            Super_Left = 343,
            Shift_Right = 344,
            Control_Right = 345,
            Alt_Right = 346,
            Super_Right = 347,
            Menu = 348
        };

        static std::unordered_map<Types, std::string> keyNameMap;
    
    private:
        Types _type;
        GLFWwindow* _window;
        bool _isPressed;
        bool _wasPressedThisFrame;
        bool _wasReleasedThisFrame;

    public:
        KeyboardKey(Types type, GLFWwindow* window);
        
        ~KeyboardKey();

        std::string GetName() override;

        bool IsPressed() override { return _isPressed; }

        bool WasPressedThisFrame() override { return _wasPressedThisFrame; }
        
        bool WasReleasedThisFrame() override { return _wasReleasedThisFrame; }
        
        void Update() override;
    };
}