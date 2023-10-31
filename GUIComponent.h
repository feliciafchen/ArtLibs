//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_GUICOMPONENT_H
#define TEXTINPUT_GUICOMPONENT_H
#include <SFML/Graphics.hpp>

class GUIComponent : public sf::Drawable{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //TEXTINPUT_GUICOMPONENT_H
