//
// Created by Felicia Chen on 11/30/23.
//

#include "EditScreen.h"

void EditScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(image);
//    target.draw(save);
//    target.draw(reartify);
}

void EditScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void EditScreen::update() {

}

EditScreen::EditScreen() {

}

EditScreen::EditScreen(sf::Texture &image) {

}
