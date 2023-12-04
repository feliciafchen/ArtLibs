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
    this->name = text;
    this->text.setFillColor(sf::Color::Black);
    this->text.setFont(Fonts::getFont(KIRANG_HAERANG));
    this->text.setCharacterSize(size);
    disableState(CLICKED);
    disableState(DOUBLE_CLICKED);
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
        toggleState(CLICKED);
    if(!MouseEvents<sf::RectangleShape>::mouseClicked(box, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        disableState(CLICKED);
    }
    if(MouseEvents<sf::RectangleShape>::mouseDoubleClicked(box, window)){
        enableState(DOUBLE_CLICKED);
    }
}

void Item::update() {
    centerName();
    if(checkState(HOVERED)){
        sf::Color gray(217,217,217);
        setFillColor(gray);
        text.setStyle(sf::Text::Bold);
    }
    else{
        setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Regular);
    }
}

const sf::Text &Item::getName() const {
    return text;
}

void Item::setName(const std::string& name) {
    text.setString(name);
    this->name = name;
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

const std::string &Item::getText() const {
    return name;
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
