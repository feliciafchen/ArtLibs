//
// Created by Felicia Chen on 11/30/23.
//

#include "EditScreen.h"

void EditScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(image);
    target.draw(save);
    target.draw(reartify);
}

void EditScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void EditScreen::update() {

}

EditScreen::EditScreen() {

}

EditScreen::EditScreen(const sf::Texture& texture) {
        this->image.setTexture(texture);
        this->image.setScale(.4,.4);
        this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                                745/2 - image.getGlobalBounds().height/2.2);
}
