//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_BOX_H
#define TEXTINPUT_BOX_H
#include "States.h"
#include "GUIComponent.h"

class Box : public GUIComponent, public States {
private:
    sf::RectangleShape box;
public:
    Box();
    Box(const sf::Vector2f& size);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //TEXTINPUT_BOX_H
