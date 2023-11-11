//
// Created by Felicia Chen on 11/10/23.
//

#include "Item.h"

Item::Item()
: Item("", {0,0}, 10)
{

}
Item::Item(const std::string& text, sf::Vector2f position, unsigned int size) {
    this->text.setString(text);
    this->text.setFont(Fonts::getFont(MINECRAFT));
    this->text.setCharacterSize(size);
    box.setPosition(position);
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

}

void Item::update() {
    centerName();
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
