#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Gio
{
    class Window
    {
    private:
        GLFWwindow* _window;
        
    public:
        Window(); 

        ~Window();

        bool TryToInitialize(const char* title, int width, int height);
        
        bool ShouldClose();

        void Update();
    };
}