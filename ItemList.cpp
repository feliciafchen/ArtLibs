//
// Created by Felicia Chen on 11/10/23.
//

#include "ItemList.h"

ItemList::ItemList() {

}

ItemList::ItemList(std::vector<std::string> words) {
    for(auto w : words){
//        list.push_back(Item(w));
    }
}

const Item &ItemList::getSelected() const {
    return selected;
}

void ItemList::setSelected(const Item &selected) {
    ItemList::selected = selected;
}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const auto& i : list){
        target.draw(i);
    }
}
