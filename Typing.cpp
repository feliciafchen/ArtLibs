//
// Created by Felicia Chen on 10/14/23.
//

#include "Typing.h"

Typing::Typing()
= default;

Typing::Typing(sf::Vector2f position, const std::string &text, const sf::Font &font, const sf::Color &color, unsigned int size) {
    this->text.setPosition(position);
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(color);
    this->text.setSize(size);
    takeSnapshot();
}

void Typing::setString(const std::string &text) {
    this->text.setString(text);
}

void Typing::setFillColor(const sf::Color &color) {
    text.setFillColor(color);
}

void Typing::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

void Typing::setSize(unsigned int size) {
    text.setSize(size);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            if(event.text.unicode == 8)
                text.pop();
            else
                text.push(static_cast<char>(event.text.unicode));
        }
        takeSnapshot();
    }
}

void Typing::update() {
    text.update();
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text, states);
}

void Typing::setFont(const sf::Font &font) {
    text.setFont(font);
}

sf::Vector2f Typing::getLastPosition() {
    return text.getLastPosition();
}

const std::string& Typing::getString() {
    return text.getString();
}

void Typing::takeSnapshot() {
    HistoryNode n = *new HistoryNode;
    n.snapshot = Snapshot(getString());
    n.component = reinterpret_cast<GUIComponent *>(this);
    History::pushHistory(n);
}

sf::Vector2f Typing::getFirstPosition() {
    return text.getFirstPosition();
}
