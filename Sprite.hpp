//
// Created by borysiak on 02.11.2019.
//

#ifndef BGUI_SPRITE_HPP
#define BGUI_SPRITE_HPP

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "Resource/Resource.hpp"
#include "Resource/TextureData.hpp"

class Sprite :public sf::Drawable
{
public:
    Sprite();
    Sprite & operator = (const Sprite & sprite);

    void setTextureData(TextureData & resource);
    void createVertices(const sf::Vector2f & size);
    void updateVertices(const sf::Vector2f & position);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:

    std::array<sf::Vertex,22> vertices;
    sf::VertexBuffer buffer;
    TextureData texture;
    sf::Vector2f size;
};


#endif //BGUI_SPRITE_HPP
