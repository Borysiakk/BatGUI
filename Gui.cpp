//
// Created by borysiak on 31.10.2019.
//

#include "Gui.hpp"

#include <SFML/Window/Event.hpp>
Gui::Gui():containers()
{
    containers.reserve(24);
    texture.loadFromFile("Black.png");
}


int Gui::addWidget(Widget * obj)
{
    int id = containers.size();
    containers.push_back(std::unique_ptr<Widget>(obj));
    return id;
}


void Gui::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.texture =& texture;
    for(const auto & obj:containers)
    {
        target.draw(*obj,states);
    }
}

void Gui::handleEvent(sf::Event & event)
{
    if ((event.type == sf::Event::MouseMoved) || ((event.type == sf::Event::TouchMoved) && (event.touch.finger == 0)))
    {
        //float mousex = (event.type == sf::Event::MouseMoved) ? static_cast<float>(event.mouseMove.x) : static_cast<float>(event.touch.x);
        //float mousey = (event.type == sf::Event::MouseMoved) ? static_cast<float>(event.mouseMove.y) : static_cast<float>(event.touch.y);

        for (const auto & obj : containers)
        {
            //obj->OnMove(mousex, mousey);
        }
    }
    else if ((event.type == sf::Event::MouseButtonPressed) || ((event.type == sf::Event::TouchBegan) && (event.touch.finger == 0)))
    {
        float mouseX = (event.type == sf::Event::MouseButtonPressed) ? static_cast<float>(event.mouseButton.x) : static_cast<float>(event.touch.x);
        float mouseY = (event.type == sf::Event::MouseButtonPressed) ? static_cast<float>(event.mouseButton.y) : static_cast<float>(event.touch.y);

        if (event.mouseButton.button == sf::Mouse::Left || event.touch.finger == 0)
        {
            for (const auto & obj : containers)
            {
                if (event.mouseButton.button == sf::Mouse::Left || event.touch.finger == 0)
                {
                    obj->OnMousePressed(mouseX, mouseY);
                }
            }
        }
    }
    else if ((event.type == sf::Event::MouseButtonReleased) || ((event.type == sf::Event::TouchEnded) && (event.touch.finger == 0)))
    {
        float mouseX = (event.type == sf::Event::MouseButtonReleased) ? static_cast<float>(event.mouseButton.x) : static_cast<float>(event.touch.x);
        float mouseY = (event.type == sf::Event::MouseButtonReleased) ? static_cast<float>(event.mouseButton.y) : static_cast<float>(event.touch.y);

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for (const auto & it : containers)
            {
                it->OnMouseReleased(mouseX, mouseY);
            }
        }
    }
    else if (event.type == sf::Event::TextEntered)
    {
        for (const auto & it : containers)
        {
            if (it->getType() == WidgetType::EditBox)
            {
                //it->TextEntered(event.text.unicode);
            }
        }
    }
}

