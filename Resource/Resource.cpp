//
// Created by borysiak on 31.10.2019.
//

#include "Resource.hpp"

using namespace boost::spirit;

void Resource::addFontName(std::string_view name)
{
    font = std::make_unique<sf::Font>();
    font->loadFromFile(name.data());
}

void Resource::addTextureData(std::string name, std::string part_str, std::string middle_str)
{
    std::vector<float> part = StringToRect(part_str);
    std::vector<float> middle = StringToRect(middle_str);

    textureData[name] = TextureData(sf::FloatRect{part[0],part[1],part[2],part[3]},sf::FloatRect{middle[0],middle[1],middle[2],middle[3]});
}

std::vector<float> Resource::StringToRect(std::string_view value_str)
{
    std::vector<float> rect;
    if (qi::phrase_parse(value_str.begin(), value_str.end(), qi::float_ % ',', ascii::space, rect))
    {
        return rect;
    }
}

TextureData & Resource::getTextureData(std::string name)
{
    return textureData.find(name)->second;
}

sf::Font * Resource::getFont()
{
    return font.get();
}
