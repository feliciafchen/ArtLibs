//
// Created by Felicia Chen on 11/10/23.
//

#ifndef TEXTINPUT_ITEMLIST_H
#define TEXTINPUT_ITEMLIST_H
#include "Item.h"
#include <list>
#include "iostream"

class ItemList : public sf::Drawable, public EventHandler, public States {
private:
    std::vector<Item> list;
    std::string selected;
    void updatePositions();
public:
    ItemList();
    ItemList(const std::vector<std::string>& words, unsigned int);
    void setBoxSize(sf::Vector2f);
    void setFillColor(sf::Color);
    void setOutlineColor(sf::Color);
    void setTextSize(unsigned int);
    void setTextColor(sf::Color);
    void setOutlineThickness(float);
    void setPosition(sf::Vector2f pos);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    const std::string&getSelected() const;
    void setSelected(const Item &selected);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_ITEMLIST_H
