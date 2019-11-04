//
// Created by borysiak on 31.10.2019.
//

#include "TextureData.hpp"

TextureData & TextureData::operator = (const TextureData & textureData)
{
    if(this != &textureData)
    {
        this->middle = textureData.middle;
        this->part = textureData.part;
    }
    return * this;
}