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

void Button::loadResourceData(std::array<Resource*,2> resources)
{
    Resource * resource = resources[0];
    Resource * textureInfo = resources[1];

    normal.setTextureData(textureInfo->getTextureData("TextureNormal"));
    hover.setTextureData(textureInfo->getTextureData("TextureHover"));
    down.setTextureData(textureInfo->getTextureData("TextureDown"));

    text.setFont(resource->getFont());

    normal.createVertices(sf::Vector2f(getSize().x,getSize().y));
    hover.createVertices(sf::Vector2f(getSize().x,getSize().y));
    down.createVertices(sf::Vector2f(getSize().x,getSize().y));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    switch (clickedType)
    {
        case ClickedType::Normal:
            target.draw(normal, states);
            break;
        case ClickedType::Hover:
            target.draw(hover, states);
            break;
        case ClickedType::Down:
            target.draw(down, states);
            break;
    }
    text.draw(target,states);
}


void Button::updateVertices(const sf::Vector2f & _size)
{
    normal.updateVertices(size);
    hover.updateVertices(size);
    down.updateVertices(size);
    setText(text.getText());
}

bool Button::OnMove(float x, float y)
{
    if (mouseInWidget(x, y) == true)
    {
        if (clickedType != ClickedType::Down)
        {
            clickedType = ClickedType::Hover;
        }
        return true;
    }
    else
    {
        clickedType = ClickedType::Normal;
        //m_text.setColor(TextNormal);
        return false;
    }
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
    if (mouseInWidget(x, y) == true)
    {
        clickedType = ClickedType::Hover;
        text.setColor(sf::Color::Cyan);
        return true;
    }
    else
    {
        return false;
    }
}

void Button::setText(sf::String _text)
{
    sf::Vector2f buttonSize = getSize();
    text.setCharacterSize(text.findBestTextSize(buttonSize.y, buttonSize.x) * 0.8);

    text.setText(_text);

    sf::FloatRect textRect = text.getBoundLocal();
    text.setPosition((getSize().x - textRect.width) / 2, (getSize().y - textRect.height) / 2);
}
