//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_TEXTUREDATA_HPP
#define BGUI_TEXTUREDATA_HPP

#include <SFML/Graphics/Rect.hpp>

class TextureData
{
public:
    TextureData() {}
    TextureData(sf::FloatRect part, sf::FloatRect middle) : part(part), middle(middle) {}

    TextureData & operator = (const TextureData & textureData);

    sf::FloatRect part;
    sf::FloatRect middle;
};

#endif //BGUI_TEXTUREDATA_HPP
