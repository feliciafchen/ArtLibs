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
    setPosition(position);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(icon, states);
    Item::draw(window, states);
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
    icon.setPosition(pos);
    Item::setPosition({pos.x + icon.getGlobalBounds().width, pos.y});
}

void FileItem::setIcon(imageEnum icon) {
    this->icon.setTexture(Images::getImage(icon));
}
