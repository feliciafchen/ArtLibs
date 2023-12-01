//
// Created by Felicia Chen on 11/7/23.
//

#ifndef TEXTINPUT_TEXTBOX_H
#define TEXTINPUT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "Typing.h"
#include "GUIComponent.h"
#include "MouseEvents.h"

class TextBox : public GUIComponent{
private:
    sf::RectangleShape box;
    sf::Vector2f position;
public:
    TextBox();
    TextBox(sf::Vector2f position, sf::Vector2f, unsigned int textSize,
            sf::Color fillColor, sf::Color textColor, sf::Color borderColor,
            float borderThickness);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Vector2f& getPosition();
    void setPosition(sf::Vector2f);
    bool contains(sf::Vector2f position);
};


#endif //TEXTINPUT_TEXTBOX_H
