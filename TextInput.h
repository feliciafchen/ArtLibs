//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H
#include "GUIComponent.h"
#include "TextBox.h"
#include "Label.h"
#include "KeyShortcuts.h"
#include "History.h"

class TextInput : public GUIComponent {
private:
    TextBox textbox;
    Typing typing;
    Cursor cursor;
public:
    TextInput();
    TextInput(const std::string& label, unsigned int labelSize, sf::Vector2f position,
              sf::Vector2f, sf::Color labelColor, sf::Color textColor, sf::Color fillColor, sf::Color borderColor,
              float borderThickness);
    const std::string& getString();
    void setPosition(sf::Vector2f);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};

#endif //TEXTINPUT_TEXTINPUT_H
