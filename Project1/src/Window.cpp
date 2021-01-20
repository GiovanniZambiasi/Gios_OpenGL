#include "Window.h"
#include "Debug.h"

Gio::Window::Window(const char* title, int width, int height)
    : _window(nullptr)
    , onSizeChanged(nullptr)
{
    _isValid = TryToInitialize(title, width, height);
}

Gio::Window::~Window()
{
    glfwTerminate();
}

bool Gio::Window::TryToInitialize(const char* title, int width, int height)
{
    /* Initialize the library */
    if (!glfwInit())
        return false;

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, title, NULL, NULL);

    _width = width;
    _height = height;
    
    if (!_window)
    {
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);

    //glfwSwapInterval(1);

    GLenum returnValue = glewInit();

    switch (returnValue)
    {
    case GLEW_OK:
        Debug::Log("Initializing OpenGL...");
        
        {
            std::string version = std::string("[OpenGL] v.");
            version += (const char*)glGetString(GL_VERSION);
            Debug::Log(version);
        }
        
        break;
    default:
        Debug::LogError("GLEW needs a valid OpenGL context to initialize!");
        break;
    }

    return true;
}

bool Gio::Window::ShouldClose() { return glfwWindowShouldClose(_window); }

void Gio::Window::SwapBuffers()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(_window);

    /* Poll for and process events */
    glfwPollEvents();
}

void Gio::Window::SetSize(unsigned int width, unsigned int height)
{
    glfwSetWindowSize(_window, width, height);

    _width = width;
    _height = height;

    if(onSizeChanged != nullptr)
        onSizeChanged(width, height);
}
