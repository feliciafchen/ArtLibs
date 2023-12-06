//
// Created by Felicia Chen on 12/6/23.
//

#include "PromptDisplay.h"

PromptDisplay::PromptDisplay(const std::string &prompt, sf::Vector2f boxSize, sf::Vector2f position) {
    background.setSize(boxSize);
    background.setPosition(position);
    background.setFillColor(sf::Color(255,255,255,200));
    this->prompt.setString(prompt);
    this->prompt.setFillColor(sf::Color::Black);
    this->prompt.setFont(Fonts::getFont(KIRANG_HAERANG));
    this->prompt.setCharacterSize(25);
    this->prompt.setPosition(1325/2 - this->prompt.getGlobalBounds().width/2,
                             745/2 - this->prompt.getGlobalBounds().height/2);
}

void PromptDisplay::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(background, window))
        enableState(HOVERED);
    else
        disableState(HOVERED);
}

void PromptDisplay::update() {
    if(checkState(HOVERED))
        disableState(HIDDEN);
    else
        enableState(HIDDEN);
}

void PromptDisplay::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    target.draw(background);
    target.draw(prompt);
}

PromptDisplay::PromptDisplay() {
    enableState(HIDDEN);
}
