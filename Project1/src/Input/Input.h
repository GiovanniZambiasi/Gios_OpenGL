#pragma once
#include "Key.h"
#include "../Window.h"

namespace Gio::Input
{
    class Input
    {
    private:
        Input();
        
        ~Input();
        
        inline static Window* _window = nullptr;
    public:
        static void Initialize(Window& window);

        static bool GetKeyDown(Key key);
    };
}
