//
// Created by borysiak on 05.11.2019.
//

#include "Text.hpp"

Text::Text()
{
    text.setCharacterSize(20);
}

Text & Text::operator + (const char sign)
{
    text.setString(text.getString() + sign);
    return * this;
}


Text & Text::operator--()
{
    sf::String _text = text.getString();
    if (_text.getSize() != 0)
    {
        _text.erase(_text.getSize() - 1, 1);
        text.setString(_text);
    }
    return * this;
}

Text & Text::operator=(std::string_view _text)
{
    text.setString(_text.data());
    text.setOrigin(0, text.getLocalBounds().top);
    return * this;
}

Text & Text::operator=(const char * _text)
{
    text.setString(_text);
    return * this;
}

void Text::setText(sf::String & _text)
{
    text.setString(_text);
    text.setOrigin(text.getLocalBounds().left, text.getLocalBounds().top);
}

void Text::setFont(sf::Font * _font)
{
    font = _font;
    text.setFont(*font);
}

void Text::setColor(sf::Color color)
{
    text.setFillColor(color);
}
void Text::setCharacterSize(unsigned int size)
{
    text.setCharacterSize(size);
}
void Text::setOutlineColor(sf::Color & color)
{
    text.setOutlineColor(color);
}

sf::FloatRect Text::getBoundLocal()
{
    return text.getLocalBounds();
}

int Text::getCharacterSize()
{
    return text.getCharacterSize();
}

sf::String Text::getText()
{
    return text.getString();
}

float Text::calculateExtraVerticalSpace(unsigned int characterSize)
{
    bool bold = 0;
    float lineHeight = characterSize + font->getGlyph('g', characterSize, bold).bounds.height + font->getGlyph('g', characterSize, bold).bounds.top;
    float lineSpacing = font->getLineSpacing(characterSize);
    return lineHeight - lineSpacing;
}

unsigned int Text::findBestTextSize(float height, int fit)
{
    if (height < 2)
        return 1;

    std::vector<unsigned int> textSizes(static_cast<std::size_t>(height));
    for (unsigned int i = 0; i < static_cast<unsigned int>(height); ++i)textSizes[i] = i + 1;

    auto high = std::lower_bound(textSizes.begin(), textSizes.end(), height,[&](unsigned int charSize, float h) { return font->getLineSpacing(charSize) + calculateExtraVerticalSpace(charSize) < h; });
    if (high == textSizes.end())return static_cast<unsigned int>(height);

    float highLineSpacing = font->getLineSpacing(*high);
    if (highLineSpacing == height)return *high;

    auto low = high - 1;
    float lowLineSpacing = font->getLineSpacing(*low);

    if (fit < 0)return *low;
    else if (fit > 0)return *high;
    else
    {
        if (std::abs(height - lowLineSpacing) < std::abs(height - highLineSpacing))return *low;
        else return *high;
    }
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(text,states);
}

