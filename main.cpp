#include <iostream>

#include <SFML/Graphics.hpp>
#include "Widget/Button.hpp"
#include "Theme.hpp"

int main()
{
    Theme theme("Black.json");
    Gui * gui = theme.getGui();
    Button::Ptr button = theme.Create(WidgetType::Button);
    button->setPosition(50,50);
    sf::RenderWindow window(sf::VideoMode(800,600,32),"Test Gui");
    gui->setWindow(window);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

        }
        window.clear(sf::Color::Blue);
        gui->draw();
        window.display();
    }
}
