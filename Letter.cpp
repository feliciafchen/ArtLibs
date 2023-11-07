//
// Created by Felicia Chen on 10/17/23.
//

#include "Letter.h"

Letter::Letter() : Letter('\0', sf::Color::Black, 20, {100,100})
{

}

Letter::Letter(char letter, sf::Vector2f position)
        : Letter(letter, sf::Color::Black, 20, position) {
}

Letter::Letter(char letter, sf::Color color, unsigned int size, sf::Vector2f position)
{
    setFont(Fonts::getFont(FREE_SANS));
    setString(std::string(1,letter));
    setCharacterSize(size);
    setFillColor(color);
    setPosition(position);
}