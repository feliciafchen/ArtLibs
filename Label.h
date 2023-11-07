//
// Created by Felicia Chen on 11/7/23.
//

#ifndef TEXTINPUT_LABEL_H
#define TEXTINPUT_LABEL_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"

class Label : public sf::Text{
public:
    Label();
    Label(const std::string &label, unsigned int labelSize, sf::Color labelColor, sf::Vector2f position);
};


#endif //TEXTINPUT_LABEL_H
