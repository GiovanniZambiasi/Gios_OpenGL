#pragma once
#include "Window.h"

namespace Gio
{
    class GUI
    {
    private:
        GUI();
        
        ~GUI();

        inline static bool _shouldShowDebugInfo = false;
    public:
        static void Initialize(Window& window);

        static void Clear();
        
        static void Draw();
        
        static void Shutdown();
    };
}
