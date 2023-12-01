//
// Created by Felicia Chen on 11/30/23.
//

#include "EditScreen.h"

void EditScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    target.draw(image);
    target.draw(save);
    target.draw(reartify);
}

void EditScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    save.addEventHandler(window, event);
    reartify.addEventHandler(window, event);
}

void EditScreen::update() {
    save.update();
    reartify.update();
    if(reartify.checkState(CLICKED)){
        enableState(HIDDEN);
        reartify.disableState(CLICKED);
    }
}

EditScreen::EditScreen() {

}

EditScreen::EditScreen(const sf::Texture& texture) {
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);
    save.setLabel("Save");
    save.setPosition({1325/2 - reartify.getGlobalBounds().width - 35, 620});

    reartify.setLabel("Reartify");
    reartify.setPosition({1325/2 + reartify.getGlobalBounds().width/2, 620});
}
