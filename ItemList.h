//
// Created by Felicia Chen on 11/10/23.
//

#ifndef TEXTINPUT_ITEMLIST_H
#define TEXTINPUT_ITEMLIST_H
#include "Item.h"
#include <list>

class ItemList : public sf::Drawable {
private:
    std::list<Item> list;
    Item selected;
public:
    ItemList();
    ItemList(std::vector<std::string> words);
    const Item &getSelected() const;
    void setSelected(const Item &selected);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_ITEMLIST_H
