#include <fstream>
#include <filesystem>
#include "../Debug.h"
#include "OpenGLUtilities.h"
#include "Shader.h"
#include "../Renderer.h"
#include "../Color.h"

namespace Gio::Rendering 
{
    Shader::Shader(ShaderProgramSource source)
        : Shader(source.name, source.vertexSource, source.fragmentSource)
    {
    }

    Shader::Shader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)
        : _name(name)
    {
        _rendererID = CreateShader(vertexSource, fragmentSource);
    }

    Shader::~Shader()
    {
        GLCall(glDeleteProgram(_rendererID));
    }

    void Shader::Bind() const
    {
        GLCall(glUseProgram(_rendererID));
    }

    void Shader::UnBind() const
    {
        GLCall(glUseProgram(0));
    }

    template <typename TUniform>
    void Shader::SetUniform(const std::string& name, TUniform val)
    {
        Debug::LogError("Uniform type not specialized for property '" + name + "'");
    }

    template<>
    void Shader::SetUniform(const std::string& name, float val)
    {
        GLCall(glUniform1f(GetUniformLocation(name), val));
    }
    
    template<>
    void Shader::SetUniform(const std::string& name, Color val)
    {
        GLCall(glUniform4f(GetUniformLocation(name), val.r, val.g, val.b, val.a));
    }

    template<>
    void Shader::SetUniform(const std::string& name, glm::mat4 val)
    {
        GLCall(glUniformMatrix4fv(GetUniformLocation(name),1, GL_FALSE, &val[0][0]));
    }
    
    int Shader::GetUniformLocation(const std::string& name)
    {
        if (_uniformLocationCache.find(name) != _uniformLocationCache.end())
        {
            return _uniformLocationCache[name];
        }

        GLCall(int location = glGetUniformLocation(_rendererID, name.c_str()));

        if (location == -1)
            Gio::Debug::LogWarning("[Uniform]: " + name + " doesn't exist!");

        _uniformLocationCache[name] = location;

        return location;
    }
    
    unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
    {
        unsigned int __id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(__id, 1, &src, nullptr);
        glCompileShader(__id);

        int __result;
        glGetShaderiv(__id, GL_COMPILE_STATUS, &__result);
        if (__result == GL_FALSE)
        {
            int __length;
            glGetShaderiv(__id, GL_INFO_LOG_LENGTH, &__length);
            char* __message = (char*)alloca(__length * sizeof(char));
            glGetShaderInfoLog(__id, __length, &__length, __message);
            Gio::Debug::LogError(__message);
            glDeleteShader(__id);
            return 0;
        }

        return __id;
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
    {
        unsigned int __program = glCreateProgram();
        unsigned int __vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int __fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        // Attaches both vertex and fragment shaders together
        GLCall(glAttachShader(__program, __vs));
        GLCall(glAttachShader(__program, __fs));
        GLCall(glLinkProgram(__program));
        GLCall(glValidateProgram(__program));

        // Deletes the "intermediary" shader files
        GLCall(glDeleteShader(__vs));
        GLCall(glDeleteShader(__fs));

        return __program;
    }

    void Shader::SetUniformMat4f(const std::string& name, glm::mat4 matrix)
    {
        Debug::LogError("Not implemented");
    }
}
