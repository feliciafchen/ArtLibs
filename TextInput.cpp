//
// Created by Felicia Chen on 10/31/23.
//

#include "TextInput.h"

TextInput::TextInput()
: TextInput("First Name:", 20, {40,50}, 200, sf::Color::Black, sf::Color::Transparent, sf::Color::Black, 1)
{

}

TextInput::TextInput(const std::string &label, unsigned int labelSize, sf::Vector2f position, float boxLength,
                     sf::Color labelColor, sf::Color fillColor, sf::Color borderColor,
                     float borderThickness) {
    setPosition(position);
    auto l = Label(label, labelSize, labelColor, position);
    this->label = l;
    auto t = TextBox(getBoxPosition(), {boxLength, static_cast<float>(labelSize + labelSize/3)}, fillColor, borderColor, borderThickness);
    textbox = t;
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    textbox.draw(window, states);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textbox.addEventHandler(window, event);
}

void TextInput::update() {
    textbox.update();
}

Snapshot &TextInput::getSnapshot() {
    return textbox.getSnapshot();
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    textbox.applySnapshot(snapshot);
}

void TextInput::setLabel(const std::string& label) {
    this->label.setString(label);
}

void TextInput::setLabelSize(unsigned int size) {
    this->label.setCharacterSize(size);
}

sf::Vector2f TextInput::getBoxPosition() {
    return {getPosition().x + label.getGlobalBounds().width + (label.getGlobalBounds().width/10),
            getPosition().y};
}