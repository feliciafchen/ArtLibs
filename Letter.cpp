//
// Created by Felicia Chen on 10/17/23.
//

#include "Letter.h"

Letter::Letter() : Letter('\0', sf::Color::Black, 30, {100,100})
{

}

Letter::Letter(char letter, sf::Vector2f position)
        : Letter(letter, sf::Color::Black, 30, position) {
}

Letter::Letter(char letter, sf::Color color, unsigned int size, sf::Vector2f position)
{
    this->letter = letter;
    setFont(Fonts::getFont(KIRANG_HAERANG));
    setString(std::string(1,letter));
    setCharacterSize(size);
    setFillColor(color);
    setPosition(position);
}

std::string& Letter::getLetter(){
    return letter;
}
