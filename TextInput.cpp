//
// Created by Felicia Chen on 10/31/23.
//

#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(const std::string &label, float labelSize, const sf::Vector2f &position) {

}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    GUIComponent::draw(window, states);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void TextInput::update() {
    GUIComponent::update();
}

Snapshot &TextInput::getSnapshot() {
    return GUIComponent::getSnapshot();
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

void TextInput::setLabel(const std::string& label) {

}

void TextInput::setLabelSize(float size) {

}