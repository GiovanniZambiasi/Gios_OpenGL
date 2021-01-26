#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../IInputElement.h"

namespace Gio::InputSystem::Devices
{
    class KeyboardKey : public IInputElement
    {
    public:
        enum Types : int
        {
            Unknown = -1,
            Space,
            Apostrophe,
            Comma,
            Minus,
            Period,
            Slash,
            AlphaNumeric_0,
            AlphaNumeric_1,
            AlphaNumeric_2,
            AlphaNumeric_3,
            AlphaNumeric_4,
            AlphaNumeric_5,
            AlphaNumeric_6,
            AlphaNumeric_7,
            AlphaNumeric_8,
            AlphaNumeric_9,
            SemiColon,
            Equal,
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Left_Bracket,
            Backslash,
            Right_Bracket,
            Grave_Accent,
            World_1,
            World_2,
            Escape,
            Enter,
            Tab,
            Backspace,
            Insert,
            Delete,
            Arrow_Right,
            Arrow_Left,
            Arrow_Down,
            Arrow_Up,
            Page_Up,
            Page_Down,
            Home,
            End,
            CapsLock,
            ScrollLock,
            NumLock,
            PrintScreen,
            Pause,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            F25,
            Keypad_0,
            Keypad_1,
            Keypad_2,
            Keypad_3,
            Keypad_4,
            Keypad_5,
            Keypad_6,
            Keypad_7,
            Keypad_8,
            Keypad_9,
            Keypad_Decimal,
            Keypad_Divide,
            Keypad_Multiply,
            Keypad_Subtract,
            Keypad_Add,
            Keypad_Enter,
            Keypad_Equal,
            Shift_Left,
            Control_Left,
            Alt_Left,
            Super_Left,
            Shift_Right,
            Control_Right,
            Alt_Right,
            Super_Right,
            Menu
        };
    
    private:
        Types _type;
        std::string _name;
        int _glfwKeyID;
        GLFWwindow* _window;
        float _value;

    public:
        KeyboardKey(std::string name, Types type, int glfwKeyID, GLFWwindow* window);
        
        ~KeyboardKey();

        std::string GetName() {return _name; }

        Types GetType() { return _type; }

        float GetValue() override { return _value; }
        
        void Update() override;
    };
}