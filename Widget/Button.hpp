//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_BUTTON_HPP
#define BGUI_BUTTON_HPP

#include "../Widget.hpp"
#include "../Sprite.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

enum class ClickedType
{
    Normal,
    Hover,
    Down,
};

class Button :public Widget
{
public:
    using Ptr = Button *;

    Button();
    void updateVertices(const sf::Vector2f & size);
    void loadResourceData(Resource * resource) override;

    bool OnMove(float x, float y);
    bool OnMousePressed(float x, float y);
    bool OnMouseReleased(float x, float y);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    ClickedType clickedType;
    Sprite normal;
    Sprite hover;
    Sprite down;
};


#endif //BGUI_BUTTON_HPP
