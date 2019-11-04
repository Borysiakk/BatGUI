//
// Created by borysiak on 31.10.2019.
//

#include "Gui.hpp"

Gui::Gui()
{
    texture.loadFromFile("Black.png");
}


int Gui::addWidget(Widget * obj)
{
    int id = containers.size();
    containers.insert(std::pair<int,std::unique_ptr<Widget>>(id,std::unique_ptr<Widget>(obj)));
    return id;
}

void Gui::setWindow(sf::RenderWindow &win)
{
    window = &win;
}

void Gui::draw()
{
    for(auto & [key,obj]:containers)
    {
        window->draw(*obj,&texture);
    }
}
