//
// Created by Felicia Chen on 11/16/23.
//

#include "FileItem.h"
#include "Images.h"

FileItem::FileItem() {

}

FileItem::FileItem(imageEnum icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    setIcon(icon);
    setName(text);
    setBoxSize(size);
    setTextSize(size.y/1.5);
    setFillColor(sf::Color::Transparent);
    setPosition(position);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(icon, states);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    Item::addEventHandler(window, event);
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
    return Item::getBoxSize();
}

sf::Vector2f FileItem::getPosition() const {
    return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {
    Item::box.setPosition(pos);
    icon.setPosition({pos.x+padding, pos.y+padding});
    Item::text.setPosition({pos.x + icon.getGlobalBounds().width + padding*2, pos.y});
}

void FileItem::setIcon(imageEnum icon) {
    this->icon.setTexture(Images::getImage(icon));
    this->icon.setScale({0.075,0.075});
}

void FileItem::update() {
    centerNameY();
    centerIconY();
    if(checkState(CLICKED)){
        setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
    }
    else{
        setFillColor(sf::Color::Transparent);
        text.setStyle(sf::Text::Regular);
    }
}

void FileItem::centerIconY() {
    icon.setPosition({icon.getPosition().x, box.getPosition().y + box.getGlobalBounds().height/2 - icon.getGlobalBounds().height/2});
}

void FileItem::centerNameY() {
    text.setPosition({text.getPosition().x, box.getPosition().y+5});
}
