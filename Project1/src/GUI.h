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
        inline static bool _shouldShowEntities = false;
        inline static int _windowHeight = 0;
        inline static int _windowWidth = 0;
    public:

        static void Initialize(Window& window);

        static void Clear();
        
        static void Draw();
        
        static void Shutdown();

        static void DrawSettingsWindow();

        inline static GUI* instance;
    };
}
