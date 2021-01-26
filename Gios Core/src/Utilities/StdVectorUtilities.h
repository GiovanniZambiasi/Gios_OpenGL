#pragma once
#include <vector>

namespace Gio::Utilities
{
    template<typename T>
    bool Contains(T object, std::vector<T>& vec)
    {
        for (auto i = 0; i < vec.size(); i++)
        {
            auto element = vec[i];

            if(element == object)
                return true;
        }
        
        return false;
    }
}
