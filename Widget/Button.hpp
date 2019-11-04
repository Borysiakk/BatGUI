//
// Created by borysiak on 31.10.2019.
//

#ifndef BGUI_BUTTON_HPP
#define BGUI_BUTTON_HPP

#include "../Widget.hpp"
#include "../Sprite.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Button :public Widget
{
public:
    using Ptr = Button *;

    Button();
    void loadResourceData(Resource * resource) override;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    Sprite normal;
    Sprite hover;
    Sprite down;
};


#endif //BGUI_BUTTON_HPP
