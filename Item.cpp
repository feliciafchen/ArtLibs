//
// Created by Felicia Chen on 11/10/23.
//

#include "Item.h"

Item::Item()
: Item("", 10)
{

}
Item::Item(const std::string& text, unsigned int size) {
    this->text.setString(text);
    this->text.setFont(Fonts::getFont(FREE_SANS));
    this->text.setCharacterSize(size);
    disableState(CLICKED);
}

void Item::centerName() {
    text.setPosition({static_cast<float>(box.getPosition().x + (box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2)),
                      static_cast<float>(box.getPosition().y + (box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.25))});
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(text);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box, window))
        enableState(HOVERED);
    else
        disableState(HOVERED);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box, window))
        enableState(CLICKED);
}

void Item::update() {
    centerName();
    if(checkState(HOVERED)){
        setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
    }
    else{
        setFillColor(sf::Color::Transparent);
        text.setStyle(sf::Text::Regular);
    }
}

const sf::Text &Item::getName() const {
    return text;
}

void Item::setName(const std::string& name) {
    text.setString(name);
}

void Item::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);
    centerName();
}

void Item::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
}

void Item::setFillColor(sf::Color color) {
    box.setFillColor(color);
}

void Item::setOutlineColor(sf::Color color) {
    box.setOutlineColor(color);
}

void Item::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
}

void Item::setOutlineThickness(float thickness) {
    box.setOutlineThickness(thickness);
}

void Item::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

std::string &Item::getText() const {
    std::string string = text.getString();
    return string;
}

const sf::Vector2f &Item::getPosition() {
    return box.getPosition();
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

const sf::Vector2f & Item::getBoxSize() const {
    return box.getSize();
}
