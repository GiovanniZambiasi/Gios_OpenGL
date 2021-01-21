#include "Window.h"
#include <GLFW/glfw3native.h>
#include "Debug.h"

Gio::Window::Window(const char* title, int width, int height)
    : _window(nullptr)
    , onWindowSizeChanged()
{
    _isValid = TryToInitialize(title, width, height);
}

Gio::Window::~Window()
{
    glfwTerminate();
}

bool Gio::Window::TryToInitialize(const char* title, int width, int height)
{
    if (!glfwInit())
        return false;

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title, NULL, NULL);

    SetSize(WindowSize(width, height));
    
    if (!_window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(_window);

    glfwSwapInterval(0);

    GLenum returnValue = glewInit();

    switch (returnValue)
    {
    case GLEW_OK:
        Debug::Log("Initializing OpenGL...");
        Debug::Log("[OpenGL] v." + std::string((const char*)glGetString(GL_VERSION)));
        break;
    default:
        Debug::LogError("GLEW needs a valid OpenGL context to initialize!");
        break;
    }

    return true;
}

bool Gio::Window::ShouldClose() { return glfwWindowShouldClose(_window); }

void Gio::Window::Update()
{
    glfwSwapBuffers(_window);

    glfwPollEvents();
}

void Gio::Window::SetSize(WindowSize size)
{
    _size = size;

    glViewport(0, 0, size.width, size.height);
    glfwSetWindowSize(_window, _size.width, _size.height);
    glfwSetWindowSizeLimits(_window, _size.width, _size.height, _size.width, _size.height);
    
    onWindowSizeChanged.Invoke(_size);
}