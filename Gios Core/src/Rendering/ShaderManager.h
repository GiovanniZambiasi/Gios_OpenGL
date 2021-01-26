#pragma once
#include <string>

#include "Shader.h"

namespace Gio::Rendering
{
    class ShaderManager
    {
    private:
        ShaderManager();
        
        ~ShaderManager();

        inline static std::vector<Shader*> shaders = std::vector<Gio::Rendering::Shader*>();;
    
    public:
        static void LoadShaders();

        static void LoadShader(const std::string& filePath);
        
        static void UnloadShader(const std::string& name);

        static Shader* GetShader(const std::string& name);
        
        static Shader* GetShader(const unsigned int rendererID);

        static ShaderProgramSource ParseShader(const std::string& source);
    };
}
