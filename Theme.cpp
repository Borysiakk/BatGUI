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

Theme::Theme(std::string fileName):fileName(fileName),gui(std::make_unique<Gui>())
{
    load();
}

WidgetConverter Theme::Create(WidgetType type)
{
    Widget * object;

    switch(type)
    {
        case WidgetType::Button:
        {
            object = new Button();
            object->loadResourceData(resources[WidgetType::Button].get());
            gui->addWidget(object);
            break;
        }
    }
    return WidgetConverter(object);
}


void Theme::load()
{
    pt::ptree root;
    std::unique_ptr<Resource> resource;
    pt::read_json("Black.json",root);

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
