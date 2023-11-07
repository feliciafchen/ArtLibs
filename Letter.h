//
// Created by Felicia Chen on 10/17/23.
//

#ifndef TEXTINPUT_LETTER_H
#define TEXTINPUT_LETTER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Letter : public sf::Text {
private:
    sf::Vector2f position;
public:
    Letter();
    Letter(char letter, sf::Vector2f position);
    Letter(char letter, sf::Color color, unsigned int size, sf::Vector2f position);
    const sf::Vector2f &getPosition() const;
};
#endif //TEXTINPUT_LETTER_H
