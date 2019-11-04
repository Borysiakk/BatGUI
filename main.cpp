#include <iostream>

#include <SFML/Graphics.hpp>
#include "Widget/Button.hpp"
#include "Theme.hpp"

void fun(Button::Ptr a)
{
    auto size = a->getSize();
    a->setSize(sf::Vector2f(size.x + 50,size.y + 50));
}
int main()
{
    Gui gui;
    Theme theme("Black.json");
    sf::RenderWindow window(sf::VideoMode(800,600,32),"Test Gui");

    Button::Ptr button = theme.Create(WidgetType::Button);
    button->connect(TypeSignal::Pressed,std::bind(fun,button));
    button->setPosition(50,50);

    gui.addWidget(button);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q)
                {
                    button->setSize(sf::Vector2f(200,200));
                }
            }
            gui.handleEvent(event);
        }
        window.clear(sf::Color::Blue);
        window.draw(gui);
        window.display();
    }
}
