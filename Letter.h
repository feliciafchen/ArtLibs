//
// Created by Felicia Chen on 10/17/23.
//

#ifndef TEXTINPUT_LETTER_H
#define TEXTINPUT_LETTER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Letter : public sf::Text {
private:
    sf::Color color;
    unsigned int size;
public:
    Letter();
    Letter(char letter);
    Letter(char letter, sf::Color color, unsigned int size);
};
#endif //TEXTINPUT_LETTER_H
