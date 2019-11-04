//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_WIDGET_HPP
#define BGUI_WIDGET_HPP

#include "Resource/Resource.hpp"

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
enum class WidgetType
{
    Button,
    EditBox,
};

class Widget :public sf::Drawable, public sf::Transformable
{
public:
    Widget();
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize() {return m_size;}

    void setType(WidgetType type);
    WidgetType getType() { return type;}

    virtual void loadResourceData(Resource * resource) = 0;
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    sf::Vector2f m_size;
private:
    WidgetType type;
};


#endif //BGUI_WIDGET_HPP
