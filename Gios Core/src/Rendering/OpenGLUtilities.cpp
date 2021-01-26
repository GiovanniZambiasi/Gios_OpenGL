#include "OpenGLUtilities.h"
#include "../Debug.h"

namespace Gio::Rendering 
{
    void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLLogCall(const char* function, const char* file, int line)
    {
        while (GLenum __error = glGetError())  // Runs until '__error' is different from 0 (GL_NO_ERROR)
        {
            Debug::LogError("[OpenGL]: \"" + std::to_string(__error) + "\". " + function + " " + file + " @ line: " + std::to_string(line));
            return false;
        }
        return true;
    }
}