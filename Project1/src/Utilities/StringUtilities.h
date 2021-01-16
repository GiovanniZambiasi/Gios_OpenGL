#pragma once
#include <string>

namespace Gio::Utilities
{
    bool EndsWith(const std::string& str, const std::string& ending)
    {
        if(ending.length() > str.length())
            return false;

        return 0 == str.compare(str.length() - ending.length(), ending.length(), ending);
    }

    std::string GetFileNameFromPath(const std::string& filePath)
    {
        for (int i = filePath.length() - 1; i >= 0; i--)
        {
            char character = filePath.at(i);
            if(character == '/')
            {
                return filePath.substr(i+1, filePath.length());
            } 
        }

        Debug::LogError("Couldn't find file name from path '" + filePath + "'");
        return "NULL";
    }

    void TrimEnd(std::string& str, unsigned int count)
    {
        if(count > str.length())
        {
            Debug::LogError("Couldn't trim string '" + str + "', because it's length is smaller than the trim count");
            return;
        }

        const int trimmedLength = str.length() - count;
        str = str.substr(0, trimmedLength);
    }
}
