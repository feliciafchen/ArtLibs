//
// Created by Felicia Chen on 11/6/23.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        return true;
    }
    return false;
}
