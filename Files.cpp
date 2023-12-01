//
// Created by Felicia Chen on 11/30/23.
//

#include "Files.h"

Files::Files() {
    files.push("My Art");
}

void Files::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    files.addEventHandler(window, event);
}

void Files::update() {
    files.update();
}

void Files::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(files);
}
