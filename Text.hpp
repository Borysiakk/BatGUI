//
// Created by borysiak on 05.11.2019.
//

#ifndef BGUI_TEXT_HPP
#define BGUI_TEXT_HPP

#include <string>
#include <string_view>

#include "SFML/Graphics/Text.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>


class Text :public sf::Transformable
{
public:
    Text();
    Text & operator + (const char sign);
    Text & operator --();
    Text & operator = (std::string_view text);
    Text & operator = (const char * text);

    void setFont(sf::Font * _font);
    void setText(sf::String & text);
    void setColor(sf::Color color);
    void setCharacterSize(unsigned int size);
    void setOutlineColor(sf::Color & color);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    float calculateExtraVerticalSpace(unsigned int characterSize);
    unsigned int findBestTextSize(float height, int fit);

    sf::FloatRect getBoundLocal();
    int getCharacterSize();
    sf::String getText();
private:
    sf::Font * font;
    sf::Text text;
};


#endif //BGUI_TEXT_HPP
