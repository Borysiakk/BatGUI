//
// Created by borysiak on 31.10.2019.
//

#include "Resource.hpp"

using namespace boost::spirit;

void Resource::addTextureData(std::string name, std::string part_str, std::string middle_str)
{
    std::vector<float> part = StringToRect(part_str);
    std::vector<float> middle = StringToRect(middle_str);

    //std::cout<<name<<"\n";
    //std::cout<<"Part =   "<<part[0]<<" "<<part[1]<<" "<<part[2]<<" "<<part[3]<<"\n";
    //std::cout<<"Middle = "<<middle[0]<<" "<<middle[1]<<" "<<middle[2]<<" "<<middle[3]<<"\n";

    mTextureData[name] = TextureData(sf::FloatRect{part[0],part[1],part[2],part[3]},sf::FloatRect{middle[0],middle[1],middle[2],middle[3]});
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
    auto   obj = mTextureData.find(name);
    return obj->second;

}