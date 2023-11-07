//
// Created by Felicia Chen on 10/17/23.
//

#include "Letter.h"

Letter::Letter() : Letter('\0', sf::Color::Black, 24)
{

}

Letter::Letter(char letter)
        : Letter(letter, sf::Color::Black, 24) {
}

Letter::Letter(char letter, sf::Color color, unsigned int size)
        : color(color), size(size)
{
    setFont(Fonts::getFont(FREE_SANS));
    setString(std::string(1,letter));
    setCharacterSize(size);
    setFillColor(color);
}