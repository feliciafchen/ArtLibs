//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H
#include "GUIComponent.h"
#include "TextBox.h"
#include "Label.h"

class TextInput : public GUIComponent {
private:
    TextBox textbox;
    Label label;
    Typing typing;
    Cursor cursor;
    sf::Vector2f getBoxPosition();
public:
    TextInput();
    TextInput(const std::string& label, unsigned int labelSize, sf::Vector2f position,
              float length, sf::Color labelColor, sf::Color textColor, sf::Color fillColor, sf::Color borderColor,
              float borderThickness);
    void setLabel(const std::string& label);
    void setLabelSize(unsigned int size);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
    void updateCursorPosition();
};

#endif //TEXTINPUT_TEXTINPUT_H
