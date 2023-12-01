//
// Created by Felicia Chen on 10/31/23.
//

#include "TextInput.h"

TextInput::TextInput()
: TextInput("First Name:", 20, {40,50}, 200, sf::Color::Black, sf::Color::Black, sf::Color(217,217,217), sf::Color::White, 1)
{

}

TextInput::TextInput(const std::string &label, unsigned int labelSize, sf::Vector2f position, float boxLength,
                     sf::Color labelColor, sf::Color textColor, sf::Color fillColor, sf::Color borderColor,
                     float borderThickness) {
    setPosition(position);
    textbox = TextBox(getPosition(), boxLength, labelSize, fillColor, textColor, borderColor, borderThickness);;
    typing = Typing(getPosition(),"",Fonts::getFont(FREE_SANS),sf::Color::Black,labelSize);;
    typing.setPosition(getPosition());
    cursor = Cursor(labelSize,textColor,getPosition());
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textbox);
    window.draw(typing);
    if(!cursor.checkState(HIDDEN))
        window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(!textbox.checkState(CLICKED))
        cursor.enableState(HIDDEN);
    if(KeyShortcuts::isUndo() && !History::empty()){
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
        cursor.addEventHandler(window, event);
    }
}

void TextInput::update() {
    textbox.update();
    typing.update();
    typing.setPosition(getPosition());
    if(!typing.getString().empty())
        cursor.setPosition({cursor.getPosition().x + typing.getLastPosition().x,typing.getLastPosition().y});
    else
        cursor.setPosition({getPosition().x+1, getPosition().y-1});
    if(textbox.checkState(CLICKED))
        cursor.update();
}

Snapshot &TextInput::getSnapshot() {
    return textbox.getSnapshot();
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    typing.setString(snapshot.getData());
}

const std::string &TextInput::getString() {
    return typing.getString();
}
