#include "KeyboardKey.h"

Gio::Input::Devices::KeyboardKey::KeyboardKey(Types type, GLFWwindow* window)
    : _type(type)
    , _window(window)
    , _isPressed(false)
    , _wasPressedThisFrame(false)
{
}

Gio::Input::Devices::KeyboardKey::~KeyboardKey()
{}

std::string Gio::Input::Devices::KeyboardKey::GetName()
{
    if (keyNameMap.find(_type) != keyNameMap.end())
    {
        return keyNameMap[_type];
    }
    
    return "N/A";
}

void Gio::Input::Devices::KeyboardKey::Update()
{
    bool wasPressed = _isPressed;
    
    _isPressed = glfwGetKey(_window, _type);

    _wasPressedThisFrame = _isPressed && !wasPressed;
    _wasReleasedThisFrame = wasPressed && !_isPressed;
}

std::unordered_map<Gio::Input::Devices::KeyboardKey::Types, std::string> Gio::Input::Devices::KeyboardKey::keyNameMap =
    {
            {Unknown,           "Unknown"},
            {Space,             "Space"},
            {Apostrophe,        "Apostrophe"},
            {Comma,             "Comma"},
            {Minus,             "Minus"},
            {Period,            "Period"},
            {Slash,             "Slash"},
            {AlphaNumeric_0,    "Alpha_0"},
            {AlphaNumeric_1,    "Alpha_1"},
            {AlphaNumeric_2,    "Alpha_2"},
            {AlphaNumeric_3,    "Alpha_3"},
            {AlphaNumeric_4,    "Alpha_4"},
            {AlphaNumeric_5,    "Alpha_5"},
            {AlphaNumeric_6,    "Alpha_6"},
            {AlphaNumeric_7,    "Alpha_7"},
            {AlphaNumeric_8,    "Alpha_8"},
            {AlphaNumeric_9,    "Alpha_9"},
            {SemiColon,         "SemiColon"},
            {Equal,             "Equal"},
            {A,                 "A"},
            {B,                 "B"},
            {C,                 "C"},
            {D,                 "D"},
            {E,                 "E"},
            {F,                 "F"},
            {G,                 "G"},
            {H,                 "H"},
            {I,                 "I"},
            {J,                 "J"},
            {K,                 "K"},
            {L,                 "L"},
            {M,                 "M"},
            {N,                 "N"},
            {O,                 "O"},
            {P,                 "P"},
            {Q,                 "Q"},
            {R,                 "R"},
            {S,                 "S"},
            {T,                 "T"},
            {U,                 "U"},
            {V,                 "V"},
            {W,                 "W"},
            {X,                 "X"},
            {Y,                 "Y"},
            {Z,                 "Z"},
            {Left_Bracket,      "Left_Bracket"},
            {Backslash,         "Backslash"},
            {Right_Bracket,     "Right_Bracket"},
            {Grave_Accent,      "Grave_Accent"},
            {World_1,           "World_1"},
            {World_2,           "World_2"},
            {Escape,            "Escape"},
            {Enter,             "Enter"},
            {Tab,               "Tab"},
            {Backspace,         "Backspace"},
            {Insert,            "Insert"},
            {Delete,            "Delete"},
            {Arrow_Right,       "Arrow_Right"},
            {Arrow_Left,        "Arrow_Left"},
            {Arrow_Down,        "Arrow_Down"},
            {Arrow_Up,          "Arrow_Up"},
            {Page_Up,           "Page_Up"},
            {Page_Down,         "Page_Down"},
            {Home,              "Home"},
            {End,               "End"},
            {CapsLock,          "CapsLock"},
            {ScrollLock,        "ScrollLock"},
            {NumLock,           "NumLock"},
            {PrintScreen,       "PrintScreen"},
            {Pause,             "Pause"},
            {F1,                "F1"},
            {F2,                "F2"},
            {F3,                "F3"},
            {F4,                "F4"},
            {F5,                "F5"},
            {F6,                "F6"},
            {F7,                "F7"},
            {F8,                "F8"},
            {F9,                "F9"},
            {F10,               "F10"},
            {F11,               "F11"},
            {F12,               "F12"},
            {F13,               "F13"},
            {F14,               "F14"},
            {F15,               "F15"},
            {F16,               "F16"},
            {F17,               "F17"},
            {F18,               "F18"},
            {F19,               "F19"},
            {F20,               "F20"},
            {F21,               "F21"},
            {F22,               "F22"},
            {F23,               "F23"},
            {F24,               "F24"},
            {F25,               "F25"},
            {Keypad_0,          "Keypad_0"},
            {Keypad_1,          "Keypad_1"},
            {Keypad_2,          "Keypad_2"},
            {Keypad_3,          "Keypad_3"},
            {Keypad_4,          "Keypad_4"},
            {Keypad_5,          "Keypad_5"},
            {Keypad_6,          "Keypad_6"},
            {Keypad_7,          "Keypad_7"},
            {Keypad_8,          "Keypad_8"},
            {Keypad_9,          "Keypad_9"},
            {Keypad_Decimal,    "Keypad_Decimal"},
            {Keypad_Divide,     "Keypad_Divide"},
            {Keypad_Multiply,   "Keypad_Multiply"},
            {Keypad_Subtract,   "Keypad_Subtract"},
            {Keypad_Add,        "Keypad_Add"},
            {Keypad_Enter,      "Keypad_Enter"},
            {Keypad_Equal,      "Keypad_Equal"},
            {Shift_Left,        "Shift_Left"},
            {Control_Left,      "Control_Left"},
            {Alt_Left,          "Alt_Left"},
            {Super_Left,        "Super_Left"},
            {Shift_Right,       "Shift_Right"},
            {Control_Right,     "Control_Right"},
            {Alt_Right,         "Alt_Right"},
            {Super_Right,       "Super_Right"},
            {Menu,              "Menu"}
    };