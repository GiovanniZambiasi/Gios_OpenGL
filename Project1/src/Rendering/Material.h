#pragma once

#include "Shader.h"
#include "../Color.h"

namespace Gio::Rendering
{
    class Material
    {
    private:
        Shader& _shader;
        std::unordered_map<int, Color> _colorProperties;
        std::unordered_map<int, float> _floatProperties;

        template <typename  TProperty>
        void SetProperty(std::unordered_map<int, TProperty>& map, const std::string& propertyName, TProperty val);

        template <typename  TProperty>
        void ApplyProperties(std::unordered_map<int, TProperty>& map);
    
    public:
        Material(Shader& shader);

        ~Material();
        
        void SetColor(const std::string& propertyName, Color color);
        
        void SetFloat(const std::string& propertyName, float v);

        Shader& GetShader() { return _shader; }

        void ApplyProperties();
    };
}
