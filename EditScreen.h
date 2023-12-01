//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_EDITSCREEN_H
#define TEXTINPUT_EDITSCREEN_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Button.h"

class EditScreen : public sf::Drawable, public EventHandler {
private:
    sf::Sprite image;
    Button save;
    Button reartify;
public:
    EditScreen();

};


#endif //TEXTINPUT_EDITSCREEN_H
