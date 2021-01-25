#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "WindowSize.h"
#include "Utilities/Subject.h"

namespace Gio
{
    typedef void(*WindowSizeHandler)(WindowSize);
    
    class Window
    {
    private:
        GLFWwindow* _window;
        WindowSize _size;
        bool _isValid;
    
    public:
        Window(const char* title, int width, int height); 

        ~Window();

        Utilities::Subject<WindowSize> onWindowSizeChanged;

        WindowSizeHandler onTest;
        
        GLFWwindow* GetGLFWWindow() { return _window; }

        WindowSize GetSize() { return _size; }
        
        bool GetIsValid() { return _isValid; }
        
        bool ShouldClose();

        void Update();

        void SetSize(WindowSize size);

    private:
        bool TryToInitialize(const char* title, int width, int height);

        void HandleWin(GLFWwindow* win, int w, int h);
    };
}
