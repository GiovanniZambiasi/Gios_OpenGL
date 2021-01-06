#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Debug.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

using namespace Gio;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "New Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    GLenum returnValue = glewInit();

    switch (returnValue)
    {
    case GLEW_OK:
        Debug::Log("Initializing OpenGL...");
        Debug::Log((const char*)glGetString(GL_VERSION));
        //std::cout << "Initializing OpenGL version '" << glGetString(GL_VERSION) << "'" << std::endl;
        break;
    default:
        Debug::LogError("GLEW needs a valid OpenGL context to initialize!");
        break;
    }

    // Scope created here to make sure the index and array buffers get deallocated before glTerminate is called
    {
        float vertices[] =
        {
             -0.5f,  -0.5f, // 0
              0.5f,  -0.5f, // 1
              0.5f,   0.5f, // 2
             -0.5f,   0.5f, // 3
        };

        unsigned int indices[] =
        {
            0,1,2,
            2,3,0
        };

        VertexArray vertexArray = VertexArray();

        VertexBuffer vertexBuffer = VertexBuffer(vertices, 4 * 2 * sizeof(float));

        VertexBufferLayout bufferLayout = VertexBufferLayout();
        bufferLayout.Push<float>(2);

        vertexArray.AddBuffer(vertexBuffer, bufferLayout);

        IndexBuffer indexBuffer = IndexBuffer(indices, 6);

        Shader shader = Shader("res/Shaders/Basic.shader");
        shader.Bind();
        
        shader.SetUniform4f("u_Color", .8f, .3f, .8f, 1.0f);

        vertexArray.UnBind();
        vertexBuffer.UnBind();
        indexBuffer.UnBind();
        shader.UnBind();

        float r = 0.0f;
        float increment = 0.05f;

        Renderer renderer = Renderer();

        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            renderer.Clear();

            shader.Bind();
            shader.SetUniform4f("u_Color", r, .3f, .8f, 1.0f);
            
            renderer.Draw(vertexArray, indexBuffer, shader);

            if (r > 1.0f)
                increment = -0.05f;
            else if (r < 0.0f)
                increment = 0.05f;

            r += increment;

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
};