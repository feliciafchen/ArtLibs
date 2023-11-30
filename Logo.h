//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_LOGO_H
#define TEXTINPUT_LOGO_H
#include <SFML/Graphics.hpp>
#include "Images.h"

class Logo : public sf::Sprite {
public:
    Logo();
    void enablePromptState();
    void enableEditState();
};


#endif //TEXTINPUT_LOGO_H
