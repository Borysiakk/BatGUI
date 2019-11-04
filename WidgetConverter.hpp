//
// Created by borysiak on 02.11.2019.
//

#ifndef BGUI_WIDGETCONVERTER_HPP
#define BGUI_WIDGETCONVERTER_HPP

#include "Widget.hpp"
class WidgetConverter
{
public:
    explicit WidgetConverter(Widget * object);
    operator Widget *();

    template<class T> operator T*()
    {
        T * object = dynamic_cast<T*>(widget);
        return object;
    }
private:
    Widget * widget;
};


#endif //BGUI_WIDGETCONVERTER_HPP
