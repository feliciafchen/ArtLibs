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

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //TEXTINPUT_BOX_H
