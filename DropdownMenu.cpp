//
// Created by Felicia Chen on 11/10/23.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {

}

DropdownMenu::DropdownMenu(const std::vector<std::string> &words, unsigned int s) {
    list = ItemList(words,s);
    inputBox = InputBox(Item(" ",s));
}

void DropdownMenu::setBoxSize(sf::Vector2f s) {
    inputBox.setBoxSize(s);
    list.setBoxSize(s);
}

void DropdownMenu::setFillColor(sf::Color c) {
    inputBox.setFillColor(c);
    list.setFillColor(c);
}

void DropdownMenu::setOutlineColor(sf::Color c) {
    inputBox.setOutlineColor(c);
    list.setOutlineColor(c);
}

void DropdownMenu::setTextSize(unsigned int s) {
    inputBox.setTextSize(s);
    list.setTextSize(s);
}

void DropdownMenu::setTextColor(sf::Color c) {
    inputBox.setTextColor(c);
    list.setTextColor(c);
}

void DropdownMenu::setOutlineThickness(float f) {
    inputBox.setOutlineThickness(f);
    list.setOutlineThickness(f);
}

void DropdownMenu::setPosition(sf::Vector2f pos) {
    inputBox.setPosition(pos);
    updatePositions();
}

const Item &DropdownMenu::getSelected() const {
    return inputBox.getItem();
}

void DropdownMenu::setSelected(const Item &selected) {
    inputBox.setItem(selected);
}

void DropdownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    if(!list.checkState(HIDDEN))
        target.draw(list);
    if(!inputBox.checkState(HIDDEN))
        target.draw(inputBox);
}
void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(inputBox.checkState(CLICKED)){
        list.toggleState(HIDDEN);
        inputBox.disableState(CLICKED);
    }
    inputBox.addEventHandler(window,event);
    list.addEventHandler(window,event);
}

void DropdownMenu::update() {
    updatePositions();
    list.update();
    inputBox.update();
    if(list.checkState(CLICKED)){
        inputBox.setName(list.getSelected());
        inputBox.disableState(CLICKED);
        list.disableState(CLICKED);
    }
}

void DropdownMenu::updatePositions() {
    list.setPosition({inputBox.getPosition().x, inputBox.getPosition().y + inputBox.getGlobalBounds().height});
}

Snapshot &DropdownMenu::getSnapshot() {
    return GUIComponent::getSnapshot();
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}
