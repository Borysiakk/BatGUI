//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_GUI_HPP
#define BGUI_GUI_HPP

#include "Widget.hpp"
#include <memory>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Gui
{
public:
    Gui();
    int  addWidget(Widget * obj);
    bool removeWidget(int id);
    void setWindow(sf::RenderWindow & win);
    void draw();
private:
    sf::Texture texture;
    sf::RenderWindow * window;
    std::map<int,std::unique_ptr<Widget>> containers;
};


#endif //BGUI_GUI_HPP
