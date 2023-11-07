//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_MOUSEEVENTS_CPP
#define TEXTINPUT_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    if(event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(clock.getElapsedTime().asMilliseconds() < 250)
            clicks++;
        else
            clicks = 1;
        clock.restart();
    }
}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    return hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    countClicks(event);
    return event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    return clicks == 2;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    return clicks == 3;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {

}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}

#endif