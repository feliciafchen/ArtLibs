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
public:
    TextBox();
    TextBox(sf::Vector2f position, float length, unsigned int textSize,
            sf::Color fillColor, sf::Color textColor, sf::Color borderColor,
            float borderThickness);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_TEXTBOX_H
