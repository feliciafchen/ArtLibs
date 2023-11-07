//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H
#include "GUIComponent.h"
#include "Typing.h"
#include "TextBox.h"
#include "Cursor.h"
#include "Label.h"

class TextInput : public GUIComponent {
private:
    TextBox textbox;
    Typing typing;
    Cursor cursor;
    Label label;
    sf::Vector2f position;
public:
    TextInput();
    TextInput(const std::string& label, float labelSize, const sf::Vector2f& position);
    void setLabel(const std::string& label);
    void setLabelSize(float size);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};

#endif //TEXTINPUT_TEXTINPUT_H
