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
    this->name = text;
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
    Item::text.setPosition({pos.x + icon.getGlobalBounds().width + padding*3, pos.y});
}

void FileItem::setIcon(imageEnum icon) {
    this->icon.setTexture(Images::getImage(icon));
    if(icon == FILE_ICON)
        this->icon.setScale({0.18,0.18});
}

void FileItem::update() {
    centerNameY();
    centerIconY();
    if(checkState(CLICKED)){
        text.setStyle(sf::Text::Bold);
        icon.setScale({.2,.2});
    }
    else{
        setFillColor(sf::Color::Transparent);
        text.setStyle(sf::Text::Regular);
        icon.setScale({.18,.18});
    }
}

void FileItem::centerIconY() {
    icon.setPosition({icon.getPosition().x, box.getPosition().y + box.getGlobalBounds().height/2 - icon.getGlobalBounds().height/2});
}

void FileItem::centerNameY() {
    text.setPosition({text.getPosition().x, box.getPosition().y+5});
}

std::string &FileItem::getText() {
    return name;
}

std::string FileItem::getString() {
    return name;
}
