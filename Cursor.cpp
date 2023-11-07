//
// Created by Felicia Chen on 11/7/23.
//

#include "Cursor.h"
#include "iostream"
Cursor::Cursor()
: Cursor(20, sf::Color::Black, {100,100})
{

}

Cursor::Cursor(unsigned int size, sf::Color color, sf::Vector2f position) {
    clock.restart();
    cursor.setFont(Fonts::getFont(FREE_SANS));
    cursor.setCharacterSize(size);
    cursor.setFillColor(color);
    this->color = color;
    cursor.setPosition(position);
    cursor.setString("|");
    enableState(HIDDEN);
}


void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(clock.getElapsedTime().asMilliseconds() > 500)
    {
        toggleState(HIDDEN);
        clock.restart();
    }
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(cursor, states);
}

void Cursor::update() {
//    if(!checkState(HIDDEN))
//        cursor.setFillColor(color);
//    else
//        cursor.setFillColor(sf::Color::White);
}

void Cursor::setPosition(sf::Vector2f pos) {
    cursor.setPosition(pos);
}


