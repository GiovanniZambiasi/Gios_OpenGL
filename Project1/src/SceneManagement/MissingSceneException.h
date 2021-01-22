#pragma once
#include <exception>
#include <string>

namespace Gio::SceneManagement
{
    class MissingSceneException : public std::exception
    {
    private:
        int _key;
    
    public:
        MissingSceneException(int key)
            :_key(key)
        { }
        
        char const* what() const override
        {
            return ("No scene registered for key " + std::to_string(_key)).c_str();
        }
    };
}
