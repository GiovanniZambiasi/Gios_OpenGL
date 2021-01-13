#include "Keyboard.h"

Gio::Input::Devices::Keyboard::Keyboard(GLFWwindow* window)
{
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Space, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Apostrophe, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Comma, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Minus, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Period, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Slash, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_0, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_1, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_2, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_3, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_4, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_5, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_6, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_7, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_8, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::AlphaNumeric_9, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::SemiColon, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Equal, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::A, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::B, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::C, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::D, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::E, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::G, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::H, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::I, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::J, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::K, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::L, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::M, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::N, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::O, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::P, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Q, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::R, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::S, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::T, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::U, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::V, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::W, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::X, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Y, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Z, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Left_Bracket, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Backslash, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Right_Bracket, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Grave_Accent, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::World_1, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::World_2, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Escape, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Enter, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Tab, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Backspace, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Insert, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Delete, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Arrow_Right, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Arrow_Left, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Arrow_Up, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Arrow_Down, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Page_Up, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Page_Down, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Home, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::End, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::CapsLock, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::ScrollLock, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::NumLock, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::PrintScreen, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Pause, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F1, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F2, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F3, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F4, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F5, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F6, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F7, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F8, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F9, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F10, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F11, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F12, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F13, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F14, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F15, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F16, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F17, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F18, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F19, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F20, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F21, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F22, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F23, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F24, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::F25, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_0, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_1, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_2, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_3, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_4, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_5, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_6, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_7, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_8, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_9, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Decimal, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Divide, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Multiply, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Subtract, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Add, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Enter, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Keypad_Equal, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Shift_Left, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Control_Left, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Alt_Left, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Super_Left, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Shift_Right, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Control_Right, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Alt_Right, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Super_Right, window));
    _keys.push_back(*new KeyboardKey(KeyboardKey::Types::Menu, window));
}

Gio::Input::Devices::Keyboard::~Keyboard()
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey& key = _keys[i];
        
        delete &key;
    }
}

void Gio::Input::Devices::Keyboard::Update()
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey& key = _keys[i];
        key.Update();
    }
}

void Gio::Input::Devices::Keyboard::GetElements(std::vector<IInputElement*>& elements)
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey* key = &_keys[i];

        elements.push_back(key);
    }
}
