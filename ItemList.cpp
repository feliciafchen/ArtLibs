//
// Created by Felicia Chen on 11/10/23.
//

#include "ItemList.h"

const Item &ItemList::getSelected() const {
    return selected;
}

void ItemList::setSelected(const Item &selected) {
    ItemList::selected = selected;
}
