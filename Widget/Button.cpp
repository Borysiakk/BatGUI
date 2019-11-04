//
// Created by borysiak on 31.10.2019.
//

#include "Button.hpp"

Button::Button()
{

}

void Button::loadResourceData(Resource * resource)
{
    normal.setTextureData(resource->getTextureData("TextureNormal"));
    normal.createVertices(sf::Vector2f(200,200));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(normal,states);
}
