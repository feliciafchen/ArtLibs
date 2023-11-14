//
// Created by Felicia Chen on 11/13/23.
//

#include "Menu.h"

Menu::Menu(){
    std::vector<std::string> options = {"Item 1", "Item 2", "Item 3"};
    Menu("Menu 1", options, 25);
}

Menu::Menu(const std::string& title, const std::vector<std::string> &words, unsigned int s) {
    list = ItemList(words,s);
    button = Item(title,s);
    setBoxSize({200,50});
    setFillColor(sf::Color::Transparent);
    setOutlineColor(sf::Color::White);
    setOutlineThickness(1);
    setTextColor(sf::Color::White);
    setPosition({100,100});
}

void Menu::setBoxSize(sf::Vector2f s) {
    button.setBoxSize(s);
    list.setBoxSize(s);
}

void Menu::setFillColor(sf::Color c) {
    button.setFillColor(c);
    list.setFillColor(c);
}

void Menu::setOutlineColor(sf::Color c) {
    button.setOutlineColor(c);
    list.setOutlineColor(c);
}

void Menu::setTextSize(unsigned int s) {
    button.setTextSize(s);
    list.setTextSize(s);
}

void Menu::setTextColor(sf::Color c) {
    button.setTextColor(c);
    list.setTextColor(c);
}

void Menu::setOutlineThickness(float f) {
    button.setOutlineThickness(f);
    list.setOutlineThickness(f);
}

void Menu::setPosition(sf::Vector2f pos) {
    button.setPosition(pos);
    updatePositions();
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    if(!list.checkState(HIDDEN))
        target.draw(list);
    if(!button.checkState(HIDDEN))
        target.draw(button);
}
void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    button.addEventHandler(window,event);
    list.addEventHandler(window,event);
}

void Menu::update() {
    updatePositions();
    list.update();
    button.centerName();
    if(button.checkState(CLICKED)){
        button.setFillColor(sf::Color::Blue);
        list.toggleState(HIDDEN);
        button.disableState(CLICKED);
    }
    if(list.checkState(CLICKED) && !list.checkState(HIDDEN)){
        button.disableState(CLICKED);
        list.disableState(CLICKED);
        list.enableState(HIDDEN);
        button.setFillColor(sf::Color::Transparent);
    }
}

void Menu::updatePositions() {
    list.setPosition({button.getPosition().x, button.getPosition().y + button.getGlobalBounds().height});
}

const sf::Vector2f &Menu::getPosition() {
    return button.getPosition();
}

sf::FloatRect Menu::getButtonGlobalBounds() {
    return button.getGlobalBounds();
}
