//
// Created by borysiak on 31.10.2019.
//

#include "Button.hpp"

Button::Button():clickedType(ClickedType::Normal)
{
    connectSignalInit();
    setType(WidgetType::Button);
    size = sf::Vector2f(120,50);
}

void Button::loadResourceData(Resource * resource)
{
    normal.setTextureData(resource->getTextureData("TextureNormal"));
    hover.setTextureData(resource->getTextureData("TextureHover"));
    down.setTextureData(resource->getTextureData("TextureDown"));

    normal.createVertices(sf::Vector2f(getSize().x,getSize().y));
    hover.createVertices(sf::Vector2f(getSize().x,getSize().y));
    down.createVertices(sf::Vector2f(getSize().x,getSize().y));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(normal,states);
}


void Button::updateVertices(const sf::Vector2f & _size)
{
    normal.updateVertices(size);
    hover.updateVertices(size);
    down.updateVertices(size);
}

bool Button::OnMove(float x, float y)
{
    return false;
}

bool Button::OnMousePressed(float x, float y)
{
    if (mouseInWidget(x,y) == true)
    {
        if (functions[TypeSignal::Pressed] != nullptr)
        {
            functions[TypeSignal::Pressed]();
        }
        clickedType = ClickedType::Down;
        return true;
    }
    else
    {
        clickedType = ClickedType::Normal;
        return false;
    }
}

bool Button::OnMouseReleased(float x, float y)
{
    return false;
}
