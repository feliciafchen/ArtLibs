//
// Created by Felicia Chen on 10/19/23.
//

#ifndef TEXTINPUT_FONTS_H
#define TEXTINPUT_FONTS_H
#include <SFML/Graphics.hpp>
#include <map>
#include "FontEnum.h"

class Fonts {
private:
    static inline std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);
public:
    static sf::Font& getFont(fontEnum font);
};


#endif //TEXTINPUT_FONTS_H
