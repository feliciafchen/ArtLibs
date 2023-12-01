//
// Created by Felicia Chen on 11/30/23.
//

#include "Artify.h"

void Artify::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(logo);
    window.draw(myArt);
    if(screen)
        window.draw(editScreen);
    else
        window.draw(promptScreen);
}

void Artify::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    myArt.addEventHandler(window, event);
}

void Artify::update() {
    myArt.update();
    if(screen)
        logo.enableEditState();
    else
        logo.enablePromptState();
}

Snapshot &Artify::getSnapshot() {
}

void Artify::applySnapshot(const Snapshot &snapshot) {
}

bool Artify::getScreen() const {
    return screen;
}

void Artify::setScreen(bool screen) {
    Artify::screen = screen;
}

Artify::Artify() : screen(false){

}
