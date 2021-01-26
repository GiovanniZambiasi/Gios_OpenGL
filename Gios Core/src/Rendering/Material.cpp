#include "Material.h"

Gio::Rendering::Material::Material(Shader& shader)
    : _shader(shader)
    , _colorProperties(std::unordered_map<int, Color>())
    , _floatProperties(std::unordered_map<int, float>())
{
}

Gio::Rendering::Material::~Material()
{
}

void Gio::Rendering::Material::SetColor(const std::string& propertyName, Color color)
{
    SetProperty(_colorProperties, propertyName, color);
}

void Gio::Rendering::Material::SetFloat(const std::string& propertyName, float v)
{
    SetProperty(_floatProperties, propertyName, v);
}

void Gio::Rendering::Material::ApplyProperties()
{   
    ApplyProperties(_colorProperties);
    ApplyProperties(_floatProperties);
}

template <typename TProperty>
void Gio::Rendering::Material::SetProperty(std::unordered_map<int, TProperty>& map, const std::string& propertyName, TProperty val)
{
    int location = _shader.GetUniformLocation(propertyName);
    map[location] = val;
}

template <typename TProperty>
void Gio::Rendering::Material::ApplyProperties(std::unordered_map<int, TProperty>& map)
{
    typename std::unordered_map<int, TProperty>::iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
        int location = it->first;
        TProperty val = it->second;

        _shader.SetUniformByLocation(location, val);
    }
}