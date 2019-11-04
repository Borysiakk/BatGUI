//
// Created by borysiak on 02.11.2019.
//

#include "WidgetConverter.hpp"

WidgetConverter::WidgetConverter(Widget * object): widget(object)
{

}

WidgetConverter::operator Widget *()
{
    return widget;
}
