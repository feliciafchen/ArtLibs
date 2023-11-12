//
// Created by Felicia Chen on 11/10/23.
//

#ifndef TEXTINPUT_DROPDOWNMENU_H
#define TEXTINPUT_DROPDOWNMENU_H
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"
#include "GUIComponent.h"
#include "KeyShortcuts.h"
#include "History.h"

class DropdownMenu : public GUIComponent {
private:
    ItemList list;
    InputBox inputBox;
    void updatePositions();
public:
    DropdownMenu();
    DropdownMenu(const std::vector<std::string>& words, unsigned int);
    void takeSnapshot();
    void setBoxSize(sf::Vector2f);
    void setFillColor(sf::Color);
    void setOutlineColor(sf::Color);
    void setTextSize(unsigned int);
    void setTextColor(sf::Color);
    void setOutlineThickness(float);
    void setPosition(sf::Vector2f pos);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    const Item &getSelected() const;
    void setSelected(const Item &selected);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};


#endif //TEXTINPUT_DROPDOWNMENU_H
