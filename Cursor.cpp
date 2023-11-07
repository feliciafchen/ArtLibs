//
// Created by Felicia Chen on 11/7/23.
//

#include "Cursor.h"

Cursor::Cursor()
: Cursor(20, sf::Color::Black, {100,100})
{

}

Cursor::Cursor(unsigned int size, sf::Color color, sf::Vector2f position) {
    setFont(Fonts::getFont(FREE_SANS));
    setCharacterSize(size);
    setFillColor(color);
    setPosition(position);
    setString('|');
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(clock.getElapsedTime() >= sf::milliseconds(500))
    {
        toggleState(HIDDEN);
        clock.restart();
    }
}

void Cursor::update() {

}
