//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_MOUSEEVENTS_CPP
#define TEXTINPUT_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    return hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window, sf::Event event) {
    return !hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked(T &object, sf::RenderWindow &window) {
    sf::Time elapsed = clock.getElapsedTime();
    if (hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (clicks == 0 || elapsed.asMilliseconds() > 250) { // Adjust the time threshold as needed
                clicks = 1;
                clock.restart();
            } else {
                clicks++;
                clock.restart();
                if (clicks == 2) {
                    clicks = 0; // Reset the click count
                    return true;
                }
            }
        }
    return false;
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