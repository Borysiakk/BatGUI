//
// Created by borysiak on 04.11.2019.
//

#ifndef BGUI_WIDGETCLICKABLE_HPP
#define BGUI_WIDGETCLICKABLE_HPP

#include "Signal.hpp"

class WidgetClickable :public Signal
{
public:
    WidgetClickable() = default;

    virtual bool OnMove(float x, float y) = 0;
    virtual bool OnMousePressed(float x, float y) = 0;
    virtual bool OnMouseReleased(float x, float y) = 0;
};


#endif //BGUI_WIDGETCLICKABLE_HPP
