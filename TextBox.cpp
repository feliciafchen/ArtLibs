//
// Created by Felicia Chen on 11/7/23.
//

#include "TextBox.h"

TextBox::TextBox()
{

}

TextBox::TextBox(sf::Vector2f position, sf::Vector2f dimensions, sf::Color fillColor, sf::Color borderColor,
                 float borderThickness) {
    box.setPosition(position);
    box.setSize(dimensions);
    box.setFillColor(fillColor);
    box.setOutlineThickness(borderThickness);
    box.setOutlineColor(borderColor);
}

TextBox::TextBox(sf::RectangleShape box) {

}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box, states);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void TextBox::update() {
    GUIComponent::update();
}

Snapshot &TextBox::getSnapshot() {
    return GUIComponent::getSnapshot();
}

void TextBox::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}
