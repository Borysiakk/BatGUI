//
// Created by Borysiak on 28.07.2019.
//

#include "Theme.hpp"
#include "Widget.hpp"

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


namespace pt = boost::property_tree;

std::vector<std::string> Theme::WidgetNames =
{
        {"Button"},
};

std::map<std::string,WidgetType> Theme::NameWidgetType =
{
        {"Button",WidgetType::Button},
};

Theme::Theme(std::string fileName):fileName(fileName)
{
    load();
}

WidgetConverter Theme::Create(WidgetType type)
{
    Widget * object  = nullptr;
    std::array<Resource*,2> stock;
    stock[0] = resources[WidgetType::Widget].get();

    switch(type)
    {
        case WidgetType::Button:
        {
            object = new Button();
            stock[1] = resources[WidgetType::Button].get();
            object->loadResourceData(stock);
            break;
        }
    }
    return WidgetConverter(object);
}


void Theme::load()
{
    pt::ptree root;
    std::unique_ptr<Resource> resource;
    pt::read_json(fileName,root);

    std::string fontName;
    auto && configure = root.get_child("ConfigureGlobal");
    for(auto item :configure)
    {
        if(item.first == "FontGlobalName")
        {
            resource = std::make_unique<Resource>();
            resource->addFontName(item.second.data());
            resources[WidgetType::Widget] = std::move(resource);
        }
    }

    for(auto && widgetName : WidgetNames )
    {
        resource = std::make_unique<Resource>();
        for (auto && type :root.get_child(widgetName))
        {

            if (type.first == "Texture")
            {
                for (auto && texture : type.second)
                {
                    std::string name = texture.first;
                    std::string part = texture.second.get<std::string>("Part");
                    std::string middle = texture.second.get<std::string>("Middle");

                    resource->addTextureData(name, part, middle);
                }
            }
            else if (type.first == "Color")
            {
                //....
            }
        }
        resources[NameWidgetType[widgetName]] = std::move(resource);
    }
}
