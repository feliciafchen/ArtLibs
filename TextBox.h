//
// Created by Felicia Chen on 11/7/23.
//

#ifndef TEXTINPUT_TEXTBOX_H
#define TEXTINPUT_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "Typing.h"
#include "GUIComponent.h"

class TextBox : public GUIComponent{
private:
    sf::RectangleShape box;
    Typing typing;
    Cursor cursor;
public:
    TextBox();
    TextBox(sf::Vector2f position, sf::Vector2f dimensions,
            sf::Color fillColor, sf::Color borderColor,
            float borderThickness);
    TextBox(sf::RectangleShape box);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_TEXTBOX_H
