//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_RESOURCE_HPP
#define BGUI_RESOURCE_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <boost/utility/string_ref.hpp>
#include <boost/spirit/include/qi.hpp>

#include "TextureData.hpp"

class Resource
{
public:
    Resource() = default;
    TextureData & getTextureData(std::string name);
    void addTextureData(std::string name, std::string part, std::string middle);
private:
    std::vector<float> StringToRect(std::string_view value_str);
    std::map<std::string, TextureData> mTextureData;
};


#endif //BGUI_RESOURCE_HPP
