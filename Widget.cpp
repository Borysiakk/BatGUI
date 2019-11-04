//
// Created by borysiak on 31.10.2019.
//

#include "Widget.hpp"

Widget::Widget():type(WidgetType::Widget)
{

}

void Widget::setSize(sf::Vector2f _size)
{
    size = _size;
    updateVertices(_size);
}

void Widget::setType(WidgetType type)
{
    type = type;
}

void Widget::connectSignalInit()
{
    functions[TypeSignal::Pressed];
}

bool Widget::mouseInWidget(float x, float y)
{
    return sf::FloatRect(getPosition(), getSize()).contains(x, y);
}
