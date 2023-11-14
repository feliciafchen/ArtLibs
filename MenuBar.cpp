//
// Created by Felicia Chen on 11/13/23.
//

#include "MenuBar.h"

void MenuBar::updatePositions() {
    sf::Vector2f pos = menus.front().getPosition();
    for (int i = 1; i < menus.size(); ++i) {
        menus[i].setPosition({pos.x+menus[i].getButtonGlobalBounds().width*i, pos.y});
    }
}

MenuBar::MenuBar() {

}

MenuBar::MenuBar(std::vector<Menu> &menus) {
    this->menus = menus;
    updatePositions();
}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto &i : menus){
        target.draw(i);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto &i : menus){
        i.addEventHandler(window, event);
    }
}

void MenuBar::update() {
    for(auto &i : menus){
        i.update();
    }
}

void MenuBar::setPosition(const sf::Vector2f &position) {
    menus.front().setPosition(position);
    updatePositions();
}
