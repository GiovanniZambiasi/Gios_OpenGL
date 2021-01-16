#include "ShaderManager.h"

#include <filesystem>
#include <fstream>
#include <sstream>

#include "../Debug.h"
#include "../Utilities/StringUtilities.h"

const std::string shaderFileExtension = ".shader";

void Gio::Rendering::ShaderManager::LoadShaders()
{
    for (const auto& entry : std::filesystem::directory_iterator("res/Shaders/"))
    {
        auto path = entry.path().string();
        if(Utilities::EndsWith(path, shaderFileExtension))
        {
            LoadShader(path);
        }
        else
            Debug::LogWarning("Non-shader file found @ '" + path + "'");
    }
}

void Gio::Rendering::ShaderManager::LoadShader(const std::string& filePath)
{
    ShaderProgramSource source = ParseShader(filePath);
    Shader* shader = new Shader(source);
    shaders.push_back(shader);
}

void Gio::Rendering::ShaderManager::UnloadShader(const std::string& name)
{
    for (int i = 0; i < shaders.size(); i++)
    {
        auto shader = shaders[i];

        if(shader->GetName() == name)
        {
            shaders.erase(shaders.begin() + i);
            delete shader;
            return;
        }
    }
}

Gio::Rendering::Shader* Gio::Rendering::ShaderManager::GetShader(const std::string& name)
{
    for (int i = 0; i < shaders.size(); i++)
    {
        auto shader = shaders[i];

        if(shader->GetName() == name)
        {
            return shader;
        }
    }

    return nullptr;
}

Gio::Rendering::Shader* Gio::Rendering::ShaderManager::GetShader(const unsigned int rendererID)
{
    for (int i = 0; i < shaders.size(); i++)
    {
        auto shader = shaders[i];

        if(shader->GetRendererID() == rendererID)
        {
            return shader;
        }
    }

    return nullptr;
}

Gio::Rendering::ShaderProgramSource Gio::Rendering::ShaderManager::ParseShader(const std::string& filePath)
{
    std::string name = Utilities::GetFileNameFromPath(filePath);
    Utilities::TrimEnd(name, shaderFileExtension.length());
    
    std::ifstream stream(filePath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream stringStreams[2];
    ShaderType shaderType = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                shaderType = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                shaderType = ShaderType::FRAGMENT;
        }
        else
        {
            stringStreams[(int)shaderType] << line << "\n";
        }
    }

    return { name, stringStreams[(int)ShaderType::VERTEX].str(), stringStreams[(int)ShaderType::FRAGMENT].str() };
}