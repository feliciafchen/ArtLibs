//
// Created by Felicia Chen on 10/31/23.
//

#include "TextInput.h"

TextInput::TextInput()
: TextInput("First Name:", 20, {40,50}, 200, sf::Color::Black, sf::Color::Black, sf::Color::Transparent, sf::Color::Black, 1)
{

}

TextInput::TextInput(const std::string &label, unsigned int labelSize, sf::Vector2f position, float boxLength,
                     sf::Color labelColor, sf::Color textColor, sf::Color fillColor, sf::Color borderColor,
                     float borderThickness) {
    setPosition(position);
    auto l = Label(label, labelSize, labelColor, position);
    this->label = l;
    auto t = TextBox(getBoxPosition(), boxLength, labelSize, fillColor, textColor, borderColor, borderThickness);
    textbox = t;
    Typing type(getBoxPosition(),"",Fonts::getFont(FREE_SANS),sf::Color::Black,labelSize);
    typing = type;
    typing.setPosition(getBoxPosition());
    Cursor c(labelSize,textColor,getBoxPosition());
    cursor = c;
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(textbox);
    window.draw(typing);
    if(!cursor.checkState(HIDDEN))
        window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(KeyShortcuts::isUndo()){
        applySnapshot(History::topHistory().snapshot);
        History::popHistory();
    }
    if(KeyShortcuts::isSave()){
        HistoryNode n = *new HistoryNode;
        n.snapshot = Snapshot(typing.getString());
        n.component = this;
        History::pushHistory(n);
    }
    textbox.addEventHandler(window, event);
    if(textbox.checkState(CLICKED)){
        typing.addEventHandler(window, event);
    }
    cursor.addEventHandler(window, event);
}

void TextInput::update() {
    if(!textbox.checkState(CLICKED)){
        cursor.enableState(HIDDEN);
    }
    textbox.update();
    typing.update();
    cursor.setPosition({cursor.getPosition().x + typing.getLastPosition().x,typing.getLastPosition().y});
}

Snapshot &TextInput::getSnapshot() {
    return textbox.getSnapshot();
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    typing.setString(snapshot.getData());
}

void TextInput::setLabel(const std::string& label) {
    this->label.setString(label);
}

void TextInput::setLabelSize(unsigned int size) {
    this->label.setCharacterSize(size);
}

sf::Vector2f TextInput::getBoxPosition() {
    return {getPosition().x + label.getGlobalBounds().width + (label.getGlobalBounds().width/10),
            getPosition().y};
}
