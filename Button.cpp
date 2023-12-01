//
// Created by Felicia Chen on 11/30/23.
//

#include "Button.h"

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(button);
    target.draw(label);
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(button, window))
        enableState(CLICKED);
    else
        disableState(CLICKED);
    if(MouseEvents<sf::RectangleShape>::hovered(button, window))
        enableState(HOVERED);
    else
        disableState(HOVERED);
}

void Button::update() {
    if(checkState(CLICKED)){
        button.setFillColor(sf::Color(217,217,217));
    }
    else
        button.setFillColor(sf::Color::White);
    if(checkState(HOVERED)){
        button.setFillColor(sf::Color(217,217,217));
        label.setStyle(sf::Text::Bold);
    }
    else{
        button.setFillColor(sf::Color::White);
        label.setStyle(sf::Text::Regular);
    }
    updatePositions();
}

Button::Button() : Button({100, 45}, {900,900},"button"){

}

void Button::setSize(sf::Vector2f size) {
    button.setSize(size);
}

void Button::setPosition(sf::Vector2f pos) {
    button.setPosition(pos);
    label.setPosition({button.getPosition().x + button.getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
                       button.getPosition().y + button.getGlobalBounds().height/2 - label.getGlobalBounds().height});
}

void Button::setLabel(const std::string &label) {
    this -> label.setString(label);
}

Button::Button(sf::Vector2f size, sf::Vector2f pos, const std::string &label) {
    button.setSize(size);
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);
    this->label.setString(label);
    this->label.setFillColor(sf::Color::Black);
    this->label.setFont(Fonts::getFont(KIRANG_HAERANG));
    this->label.setCharacterSize(30);
    setPosition(pos);
}

void Button::updatePositions() {
    label.setPosition({button.getPosition().x + button.getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
                       button.getPosition().y + button.getGlobalBounds().height/2 - label.getGlobalBounds().height});
}

sf::FloatRect Button::getGlobalBounds() {
    return button.getGlobalBounds();
}
