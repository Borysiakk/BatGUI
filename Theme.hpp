//
// Created by Borysiak on 28.07.2019.
//

#ifndef BGUI_THEME_HPP
#define BGUI_THEME_HPP

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "Gui.hpp"
#include "Widget.hpp"
#include "Widget/Button.hpp"
#include "WidgetConverter.hpp"
#include "Resource/Resource.hpp"
class Widget;

class Theme
{
public:

    Theme(std::string fileName);
    WidgetConverter Create(WidgetType type);
    Gui * getGui() {return gui.get();}
private:
    void load();

    std::string fileName;
    std::unique_ptr<Gui> gui;
    static std::vector<std::string> WidgetNames;
    static std::map<std::string,WidgetType> NameWidgetType;
    std::unordered_map<WidgetType,std::unique_ptr<Resource>> resources;
};


#endif //BGUI_THEME_HPP
