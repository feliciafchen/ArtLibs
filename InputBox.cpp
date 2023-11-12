//
// Created by Felicia Chen on 11/10/23.
//

#include "InputBox.h"

InputBox::InputBox() {

}

InputBox::InputBox(const Item& item) : item(item){
    disableState(CLICKED);
}

void InputBox::setBoxSize(sf::Vector2f size) {
    item.setBoxSize(size);
}

void InputBox::setFillColor(sf::Color c) {
    item.setFillColor(c);
}

void InputBox::setOutlineColor(sf::Color c) {
    item.setOutlineColor(c);
}

void InputBox::setTextSize(unsigned int s) {
    item.setTextSize(s);
}

void InputBox::setOutlineThickness(float f) {
    item.setOutlineThickness(f);
}

void InputBox::setPosition(sf::Vector2f pos) {
    item.setPosition(pos);
}

const sf::Text &InputBox::getName() const {
    return item.getName();
}

void InputBox::setName(const std::string &name) {
    item.setName(name);
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(item);
}

const Item &InputBox::getItem() const {
    return item;
}

void InputBox::setItem(const Item &item) {
    this->item = item;
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    item.addEventHandler(window, event);
    if(item.checkState(CLICKED)){
        enableState(CLICKED);
        item.disableState(CLICKED);
    }
}

void InputBox::update() {
    item.centerName();
}

const sf::Vector2f &InputBox::getPosition() {
    return item.getPosition();
}

void InputBox::setTextColor(sf::Color c) {
    item.setTextColor(c);
}

const sf::FloatRect &InputBox::getGlobalBounds() {
    return item.getGlobalBounds();
}
