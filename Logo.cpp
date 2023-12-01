//
// Created by Felicia Chen on 11/30/23.
//

#include "Logo.h"

Logo::Logo() {
    setTexture(Images::getImage(ARTIFY_LOGO));
    enablePromptState();
}

void Logo::enablePromptState() {
    setScale(.4,.4);
    setPosition(1325/2 - getGlobalBounds().width/2,114);
}

void Logo::enableEditState() {
    setScale(.3,.3);
    setPosition(1325/2 - getGlobalBounds().width/2,50);
}
