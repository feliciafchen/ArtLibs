//
// Created by Felicia Chen on 11/6/23.
//

#ifndef TEXTINPUT_EVENTHANDLER_H
#define TEXTINPUT_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler {
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //TEXTINPUT_EVENTHANDLER_H
