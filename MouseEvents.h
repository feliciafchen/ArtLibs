//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_MOUSEEVENTS_H
#define TEXTINPUT_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
#include <iostream>

template <class T>
class MouseEvents {
private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    inline static sf::Clock clock;
    inline static int clicks = 0;
public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(T &object, sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked(T &object, sf::RenderWindow &window);

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);
};

#include "MouseEvents.cpp"

#endif //TEXTINPUT_MOUSEEVENTS_H
