//
// Created by Felicia Chen on 11/30/23.
//

#ifndef ARTIFY_BUTTON_H
#define ARTIFY_BUTTON_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "MouseEvents.h"
#include "Fonts.h"

class Button : public sf::Drawable, public EventHandler, public States{
private:
    sf::RectangleShape button;
    sf::Text label;
    void updatePositions();
public:
    Button();
    Button(sf::Vector2f size, sf::Vector2f pos, const std::string& label);
    void setSize(sf::Vector2f);
    void setPosition(sf::Vector2f);
    void setLabel(const std::string& label);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //ARTIFY_BUTTON_H
