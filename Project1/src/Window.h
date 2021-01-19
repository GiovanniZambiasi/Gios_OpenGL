#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gio
{
    typedef void(*WindowSizeChangeHandler)(unsigned int width, unsigned int height);
    
    class Window
    {
    private:
        GLFWwindow* _window;
        unsigned int _width;
        unsigned int _height;
        bool _isValid;
    
    public:
        Window(const char* title, int width, int height); 

        ~Window();

        WindowSizeChangeHandler onSizeChanged;
        
        GLFWwindow* GetGLFWWindow() { return _window; }

        unsigned int GetWidth() { return _width; }
        
        unsigned int GetHeight() { return _height; }
        
        bool GetIsValid() { return _isValid; }
        
        bool ShouldClose();

        void SwapBuffers();

        void SetSize(unsigned int width, unsigned int height);

    private:
        bool TryToInitialize(const char* title, int width, int height);
    };
}
