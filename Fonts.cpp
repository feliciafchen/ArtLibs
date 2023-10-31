//
// Created by Felicia Chen on 10/19/23.
//

#include "Fonts.h"

void Fonts::loadFont(fontEnum font) {
    fonts[font].loadFromFile(getFontPath(font));
}

std::string Fonts::getFontPath(fontEnum font) {
    std::string f[] = {"fonts/FreeSans.ttf", "fonts/OpenSans.ttf", "fonts/Roboto.ttf"};
    return f[font];
}

sf::Font &Fonts::getFont(fontEnum font) {
    loadFont(font);
    return fonts[font];
}
