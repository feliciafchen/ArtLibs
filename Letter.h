//
// Created by Felicia Chen on 10/17/23.
//

#ifndef SFMLTYPING_LETTER_H
#define SFMLTYPING_LETTER_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Letter : public sf::Text {
public:
    Letter();
    Letter(char letter);
};
#endif //SFMLTYPING_LETTER_H
