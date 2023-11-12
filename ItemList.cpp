//
// Created by Felicia Chen on 11/10/23.
//

#include "ItemList.h"

ItemList::ItemList() {

}

ItemList::ItemList(const std::vector<std::string>& words, unsigned int size) {
    for(const auto& w : words){
        list.emplace_back(w, size);
    }
    for(auto &i : list){
        i.disableState(CLICKED);
    }
}

const std::string &ItemList::getSelected() const {
    return selected;
}

void ItemList::setSelected(const Item &selected) {
    ItemList::selected = selected.getText();
}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const auto& i : list){
        target.draw(i);
    }
}

void ItemList::setBoxSize(sf::Vector2f dimensions) {
    for(auto &i : list){
        i.setBoxSize(dimensions);
    }
}

void ItemList::setFillColor(sf::Color color) {
    for(auto &i : list){
        i.setFillColor(color);
    }
}

void ItemList::setOutlineColor(sf::Color color) {
    for(auto &i : list){
        i.setOutlineColor(color);
    }
}

void ItemList::setTextSize(unsigned int size) {
    for(auto &i : list){
        i.setTextSize(size);
    }
}

void ItemList::setTextColor(sf::Color color) {
    for(auto &i : list){
        i.setTextColor(color);
    }
}

void ItemList::setOutlineThickness(float f) {
    for(auto &i : list){
        i.setOutlineThickness(f);
    }
}

void ItemList::setPosition(sf::Vector2f pos) {
    list.front().setPosition(pos);
    updatePositions();
}

void ItemList::updatePositions() {
    sf::Vector2f pos = list.front().getPosition();
    for (int i = 1; i < list.size(); ++i) {
        list.at(i).setPosition({pos.x, pos.y + (i*list[i].getGlobalBounds().height)});
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto &i : list)
        i.addEventHandler(window, event);
}

void ItemList::update() {
    for(auto &i : list)
        i.update();
    updatePositions();
    for(auto &i : list){
        if(i.checkState(CLICKED)){
            i.disableState(CLICKED);
            setSelected(i);
            enableState(CLICKED);
        }
    }
}
