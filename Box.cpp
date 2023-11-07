//
// Created by Felicia Chen on 10/31/23.
//

#include "Box.h"
#include "HistoryNode.h"

Box::Box() : Box({50, 50}){

}

Box::Box(const sf::Vector2f &size) : box(size) {

}

void Box::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //get position of the mouse
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if (box.getGlobalBounds().contains(mpos))
        enableState(HOVERED);
    else
        disableState(HOVERED);
}

void Box::update() {
    if(checkState(HOVERED))
        box.setFillColor(sf::Color::Blue);
    else
        box.setFillColor(sf::Color::White);
}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    if(!checkState(HIDDEN))
        window.draw(box);
}

Snapshot& Box::getSnapshot() {
    auto n = Snapshot("hi");
    return n;
}

void Box::applySnapshot(const Snapshot &snapshot) {

}
