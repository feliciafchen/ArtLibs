//
// Created by Felicia Chen on 10/17/23.
//

#include "Letter.h"

Letter::Letter() : Letter('\0')
{

}

Letter::Letter(char letter) : sf::Text()
{
    setFont(Fonts::getFont(FREE_SANS));
    setString(std::string(1, letter));
    setCharacterSize(24);
}
