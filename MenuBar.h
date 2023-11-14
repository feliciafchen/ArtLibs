//
// Created by Felicia Chen on 11/13/23.
//

#ifndef TEXTINPUT_MENUBAR_H
#define TEXTINPUT_MENUBAR_H
#include "Menu.h"
#include <SFML/Graphics.hpp>

class MenuBar : public sf::Drawable, public EventHandler, public States{
private:
    std::vector<Menu> menus;
    void updatePositions();
public:
    MenuBar();
    MenuBar(std::vector<Menu>& menus);
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};

#endif //TEXTINPUT_MENUBAR_H
