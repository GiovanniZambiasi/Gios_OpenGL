#include "Rendering/Renderer.h"
#include "Object2D.h"
#include "Window.h"

using namespace Gio;

int main(void)
{
    Window window;

    if (!window.TryToInitialize())
        return -1;

    // Scope created here to make sure the index and array buffers get deallocated before glTerminate is called
    {
        float vertices[] =
        {
            -0.5f, -0.5f, // 0
            0.5f, -0.5f, // 1
            0.5f, 0.5f, // 2
            -0.5f, 0.5f, // 3
        };

        unsigned int indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

        //Rendering::Renderer renderer = Rendering::Renderer();

        Object2D object = Object2D(vertices, indices);

        while (!window.ShouldClose())
        {
            /* Render here */
            Rendering::Renderer::Clear();

            object.Render();

            window.Update();
        }
    }
    return 0;
};
