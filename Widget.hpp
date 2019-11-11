//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_WIDGET_HPP
#define BGUI_WIDGET_HPP

#include "WidgetClickable.hpp"
#include "Resource/Resource.hpp"

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

enum class WidgetType
{
    Widget,
    Button,
    EditBox,
    CheckBox,
};

class Widget :public sf::Drawable, public sf::Transformable, public WidgetClickable
{
public:
    Widget();
    sf::Vector2f getSize() {return size;}

    void setType(WidgetType type);
    WidgetType getType() { return type;}

    virtual void connectSignalInit();
    virtual void setSize(sf::Vector2f size);
    virtual bool mouseInWidget(float x, float y);
    virtual void loadResourceData(std::array<Resource*,2> resources) = 0;
    virtual void updateVertices(const sf::Vector2f & size) = 0;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    sf::Vector2f size;
private:
    WidgetType type;
};


#endif //BGUI_WIDGET_HPP
