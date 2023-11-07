//
// Created by Felicia Chen on 11/7/23.
//

#ifndef TEXTINPUT_CURSOR_H
#define TEXTINPUT_CURSOR_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "Fonts.h"

class Cursor : public States, public EventHandler, public sf::Drawable{
private:
    sf::Text cursor;
    sf::Clock clock;
    sf::Color color;
public:
    Cursor();
    Cursor(unsigned int size, sf::Color color, sf::Vector2f position);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update() override;
};


#endif //TEXTINPUT_CURSOR_H
