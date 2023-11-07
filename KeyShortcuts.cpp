//
// Created by Felicia Chen on 11/6/23.
//

#include "KeyShortcuts.h"
#include "iostream"

bool KeyShortcuts::isUndo() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        return true;
    }
    return false;
}

bool KeyShortcuts::isSave() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        return true;
    }
    return false;
}
