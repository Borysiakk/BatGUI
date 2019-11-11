#include <iostream>

#include <SFML/Graphics.hpp>
#include "Widget/Button.hpp"
#include "Theme.hpp"

void fun(Button::Ptr a)
{
    auto size = a->getSize();
    a->setSize(sf::Vector2f(size.x * 1.25,size.y * 1.25));
}

int main()
{
    Gui gui;
    Theme theme("Gui.json");

    sf::RenderWindow window(sf::VideoMode(400,400,32),"Test Gui");

    Button::Ptr button = theme.Create(WidgetType::Button);
    button->connect(TypeSignal::Pressed,std::bind(fun,button));
    button->setPosition(70,50);
    button->setSize(sf::Vector2f(250,50));
    button->setText("NEW GAME");

    Button::Ptr button1 = theme.Create(WidgetType::Button);
    button1->connect(TypeSignal::Pressed,std::bind(fun,button));
    button1->setPosition(70,130);
    button1->setSize(sf::Vector2f(250,50));
    button1->setText("OPTIONS");

    Button::Ptr button2 = theme.Create(WidgetType::Button);
    button2->connect(TypeSignal::Pressed,std::bind(fun,button));
    button2->setPosition(70,210);
    button2->setSize(sf::Vector2f(250,50));
    button2->setText("EXIT");

    gui.addWidget(button);
    gui.addWidget(button1);
    gui.addWidget(button2);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
            gui.handleEvent(event);
        }
        window.clear(sf::Color::White);
        window.draw(gui);
        window.display();
    }
}
