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
    
    public:
        Window(); 

        ~Window();

        WindowSizeChangeHandler onSizeChanged;
        
        GLFWwindow* GetGLFWWindow() { return _window; }

        unsigned int GetWidth() { return _width; }
        
        unsigned int GetHeight() { return _height; }
        
        bool TryToInitialize(const char* title, int width, int height);
        
        bool ShouldClose();

        void SwapBuffers();

        void SetSize(unsigned int width, unsigned int height);

        inline static Window* instance = nullptr;
    };
}
