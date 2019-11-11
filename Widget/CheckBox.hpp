//
// Created by borysiak on 11.11.2019.
//

#ifndef BGUI_CHECKBOX_HPP
#define BGUI_CHECKBOX_HPP

#include "../Widget.hpp"
#include "../Sprite.hpp"
#include "../Text.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class CheckBox :public Widget
{
public:
    CheckBox();

    void updateVertices(const sf::Vector2f & size);
    void loadResourceData(std::array<Resource*,2> resources);

    bool OnMove(float x, float y);
    bool OnMousePressed(float x, float y);
    bool OnMouseReleased(float x, float y);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //BGUI_CHECKBOX_HPP
