//
// Created by Felicia Chen on 11/13/23.
//

#ifndef TEXTINPUT_MENU_H
#define TEXTINPUT_MENU_H
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "ItemList.h"

class Menu : public sf::Drawable, public EventHandler, public States {
private:
    Item button;
    ItemList list;
    void updatePositions();
public:
    Menu();
    Menu(const std::string& title, const std::vector<std::string> &options, unsigned int s);
    void setBoxSize(sf::Vector2f);
    void setFillColor(sf::Color);
    void setOutlineColor(sf::Color);
    void setTextSize(unsigned int);
    void setTextColor(sf::Color);
    void setOutlineThickness(float);
    void setPosition(sf::Vector2f pos);
    const sf::Vector2f& getPosition();
    sf::FloatRect getButtonGlobalBounds();
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_MENU_H
