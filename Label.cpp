//
// Created by Felicia Chen on 11/7/23.
//

#include "Label.h"

Label::Label() {

}

Label::Label(const std::string &label, unsigned int labelSize,
             sf::Color labelColor, sf::Vector2f position) {
    setPosition(position);
    setFont(Fonts::getFont(FREE_SANS));
    setString(label);
    setCharacterSize(labelSize);
    setFillColor(labelColor);
}
