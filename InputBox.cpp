//
// Created by Felicia Chen on 11/10/23.
//

#include "InputBox.h"

InputBox::InputBox()
        : InputBox("", {0,0}, 10)
{

}
InputBox::InputBox(const std::string& text, sf::Vector2f position, unsigned int size) {
    this->text.setString(text);
    this->text.setFont(Fonts::getFont(MINECRAFT));
    this->text.setCharacterSize(size);
    box.setPosition(position);
}

void InputBox::centerName() {
    text.setPosition({static_cast<float>(box.getPosition().x + (box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2)),
                      static_cast<float>(box.getPosition().y + (box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.25))});
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(text);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void InputBox::update() {
    centerName();
}

const sf::Text &InputBox::getName() const {
    return text;
}

void InputBox::setName(const std::string& name) {
    text.setString(name);
}

void InputBox::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);
    centerName();
}

void InputBox::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
}

void InputBox::setFillColor(sf::Color color) {
    box.setFillColor(color);
}

void InputBox::setOutlineColor(sf::Color color) {
    box.setOutlineColor(color);
}

void InputBox::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
}

void InputBox::setOutlineThickness(float thickness) {
    box.setOutlineThickness(thickness);
}
