//
// Created by Felicia Chen on 11/7/23.
//

#include "TextBox.h"

TextBox::TextBox()
{

}

TextBox::TextBox(sf::Vector2f position, float length, unsigned int textSize, sf::Color fillColor, sf::Color textColor,
                 sf::Color borderColor, float borderThickness) {
    this->position = position;
    box.setPosition(position);
    box.setSize({length, static_cast<float>(textSize + textSize/3)});
    box.setFillColor(fillColor);
    box.setOutlineThickness(borderThickness);
    box.setOutlineColor(borderColor);
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box,window))
        enableState(HOVERED);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box,window))
        enableState(CLICKED);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box,window, event))
        disableState(CLICKED);
}

void TextBox::update() {
    if(checkState(CLICKED)){
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);
    }
    else{
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(1);
    }
}

Snapshot &TextBox::getSnapshot() {
    return GUIComponent::getSnapshot();
}

void TextBox::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

sf::Vector2f &TextBox::getPosition() {
    return position;
}

bool TextBox::contains(sf::Vector2f position) {
    return box.getGlobalBounds().contains(position);
}
