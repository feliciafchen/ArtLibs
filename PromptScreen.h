//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_PROMPTSCREEN_H
#define TEXTINPUT_PROMPTSCREEN_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "DropdownMenu.h"

class PromptScreen : public sf::Drawable, public EventHandler {
private:
    std::string fullPrompt;
    DropdownMenu styleType;
    DropdownMenu artType;

};


#endif //TEXTINPUT_PROMPTSCREEN_H
