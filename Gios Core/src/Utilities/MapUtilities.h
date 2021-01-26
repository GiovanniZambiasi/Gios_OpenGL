#pragma once
#include <map>

namespace Gio::Utilities
{
    template<typename TKey, typename TValue>
    bool ContainsKey(std::map<TKey, TValue>& map, TKey key)
    {
        typename std::map<TKey, TValue>::iterator it;
        
        for (it = map.begin(); it != map.end(); it++)
        {
            TKey k = it->first;

            if(key == k)
                return true;
        }

        return false;
    }

    template<typename TKey, typename TValue>
    bool ContainsValue(std::map<TKey, TValue>& map, TValue val)
    {
        typename std::map<TKey, TValue>::iterator it;
        
        for (it = map.begin(); it != map.end(); it++)
        {
            TValue v = it->second;

            if(val == v)
                return true;
        }

        return false;
    }

    template<typename TKey, typename TValue>
    bool ContainsKey(std::unordered_map<TKey, TValue>& map, TKey key)
    {
        typename std::unordered_map<TKey, TValue>::iterator it;
        
        for (it = map.begin(); it != map.end(); it++)
        {
            TKey k = it->first;

            if(key == k)
                return true;
        }

        return false;
    }

    template<typename TKey, typename TValue>
    bool ContainsValue(std::unordered_map<TKey, TValue>& map, TValue val)
    {
        typename std::unordered_map<TKey, TValue>::iterator it;
        
        for (it = map.begin(); it != map.end(); it++)
        {
            TValue v = it->second;

            if(val == v)
                return true;
        }

        return false;
    }
}
