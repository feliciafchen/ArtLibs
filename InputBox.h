//
// Created by Felicia Chen on 11/10/23.
//

#ifndef TEXTINPUT_INPUTBOX_H
#define TEXTINPUT_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Item.h"

class InputBox : public sf::Drawable, public States, public EventHandler{
private:
    Item item;
public:
    InputBox();
    explicit InputBox(const Item& item);
    void setBoxSize(sf::Vector2f);
    void setFillColor(sf::Color);
    void setOutlineColor(sf::Color);
    void setTextSize(unsigned int);
    void setTextColor(sf::Color c);
    void setOutlineThickness(float);
    void setPosition(sf::Vector2f pos);
    const sf::Vector2f& getPosition();
    const sf::FloatRect& getGlobalBounds();
    const sf::Text &getName() const;
    const Item& getItem() const;
    void setItem(const Item& item);
    void setName(const std::string &name);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_INPUTBOX_H
