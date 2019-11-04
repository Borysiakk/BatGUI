//
// Created by borysiak on 02.11.2019.
//

#include "Sprite.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Sprite::Sprite():buffer(sf::TrianglesStrip)
{
    
}

void Sprite::setTextureData(TextureData & resource)
{
    texture.part = resource.part;
    texture.middle = resource.middle;
}

void Sprite::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(buffer,states);
}

void Sprite::createVertices(const sf::Vector2f & _size)
{

    buffer.create(22);

    size = _size;
    sf::Vector2f texturePos = { texture.part.left,texture.part.top };
    sf::Vector2f textureSize = { texture.part.width,texture.part.height };
    sf::FloatRect middleRect = { texture.middle };
    sf::Color m_vertexColor = sf::Color::White;

    float scal_x = size.x - middleRect.left;
    float scal_y = size.y - middleRect.top;

    vertices[0] = { { 0,0 },{ texturePos.x,texturePos.y } };
    vertices[1] = { { middleRect.left,0 },m_vertexColor,{ texturePos.x + middleRect.left,texturePos.y } };
    vertices[2] = { { 0,middleRect.top },m_vertexColor,{ texturePos.x ,texturePos.y + middleRect.top } };
    vertices[3] = { { middleRect.left,middleRect.top },m_vertexColor,{ texturePos.x + middleRect.left,texturePos.y + middleRect.top } };
    vertices[4] = { { 0,scal_y },m_vertexColor,{ texturePos.x, texturePos.y + middleRect.top + middleRect.height } };
    vertices[5] = { { middleRect.left,scal_y },m_vertexColor,{ texturePos.x + middleRect.left,texturePos.y + middleRect.top + middleRect.height } };
    vertices[6] = { { 0,scal_y + middleRect.top },m_vertexColor,{ texturePos.x,texturePos.y + textureSize.y } };
    vertices[7] = { { middleRect.left,scal_y + middleRect.top },m_vertexColor,{ texturePos.x + middleRect.left ,texturePos.y + textureSize.y } };
    vertices[8] = { { scal_x,middleRect.top + scal_y },m_vertexColor,{ texturePos.x + middleRect.left + middleRect.width,texturePos.y + textureSize.y } };
    vertices[9] = vertices[5];
    vertices[10] = { { scal_x ,scal_y },m_vertexColor,{ texturePos.x + middleRect.left + middleRect.width,texturePos.y + middleRect.top + middleRect.height } };
    vertices[11] = vertices[3];
    vertices[12] = { { scal_x,middleRect.top },m_vertexColor,{ texturePos.x + middleRect.left + middleRect.width,texturePos.y + middleRect.top } };
    vertices[13] = vertices[1];
    vertices[14] = { { scal_x,0 },m_vertexColor,{ texturePos.x + middleRect.left + middleRect.width,texturePos.y } };
    vertices[15] = { { scal_x + middleRect.left,0 },m_vertexColor,{ textureSize.x + texturePos.x,texturePos.y } };
    vertices[16] = vertices[12];
    vertices[17] = { { scal_x + middleRect.left,middleRect.top },m_vertexColor,{ textureSize.x + texturePos.x ,texturePos.y + middleRect.top } };
    vertices[18] = vertices[10];
    vertices[19] = { { scal_x + middleRect.left,scal_y },m_vertexColor,{ textureSize.x + texturePos.x ,texturePos.y + middleRect.top + middleRect.height } };
    vertices[20] = vertices[8];
    vertices[21] = { { scal_x + middleRect.left ,scal_y + middleRect.top },m_vertexColor,{ textureSize.x + texturePos.x ,textureSize.y + texturePos.y } };

    buffer.update(vertices.data());
}

void Sprite::updateVertices(const sf::Vector2f & _size)
{

    sf::FloatRect middleRect = { texture.middle };
    if (_size.x != size.x && size.x != 0)
    {
        vertices[8].position.x =  _size.x - middleRect.left;
        vertices[10].position.x = _size.x - middleRect.left;
        vertices[12].position.x = _size.x - middleRect.left;
        vertices[14].position.x = _size.x - middleRect.left;
        vertices[16].position.x = vertices[12].position.x;
        vertices[18].position.x = vertices[10].position.x;
        vertices[20].position.x = vertices[8].position.x;

        vertices[15].position.x = _size.x;
        vertices[17].position.x = _size.x;
        vertices[19].position.x = _size.x;
        vertices[21].position.x = _size.x;
        size.x = _size.x;
    }
    if (_size.y != size.y && size.y != 0)
    {
        vertices[4].position.y = _size.y - middleRect.top;
        vertices[5].position.y = _size.y - middleRect.top;
        vertices[9].position.y = _size.y - middleRect.top;
        vertices[10].position.y = _size.y - middleRect.top;
        vertices[18].position.y = _size.y - middleRect.top;
        vertices[19].position.y = _size.y - middleRect.top;

        vertices[6].position.y = _size.y;
        vertices[7].position.y = _size.y;
        vertices[8].position.y = _size.y;
        vertices[20].position.y = _size.y;
        vertices[21].position.y = _size.y;
        size.y = _size.y;
    }
    buffer.update(vertices.data());
}
