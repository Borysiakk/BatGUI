//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_GUI_HPP
#define BGUI_GUI_HPP

#include "Widget.hpp"

#include <memory>
#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Gui :public sf::Drawable
{
public:
    Gui();
    void setConfigureGui();
    int  addWidget(Widget * obj);
    bool removeWidget(int id);
    void handleEvent(sf::Event & events);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
private:
    sf::Texture texture;
    std::vector<std::unique_ptr<Widget>> containers;
};


#endif //BGUI_GUI_HPP
