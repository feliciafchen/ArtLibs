//
// Created by Felicia Chen on 10/31/23.
//

#include "TextInput.h"

TextInput::TextInput()
: TextInput("", 25, {40,50}, {200, 35}, sf::Color::Black, sf::Color::Black, sf::Color(217,217,217), sf::Color::White, 1)
{

}

TextInput::TextInput(const std::string &label, unsigned int labelSize, sf::Vector2f position, sf::Vector2f boxSize,
                     sf::Color labelColor, sf::Color textColor, sf::Color fillColor, sf::Color borderColor,
                     float borderThickness) {
    setPosition(position);
    textbox = TextBox(getPosition(), boxSize, labelSize, fillColor, textColor, borderColor, borderThickness);;
    typing = Typing({getPosition().x+1, getPosition().y-1},"",Fonts::getFont(FREE_SANS),sf::Color::Black,labelSize);;
    typing.setPosition(textbox.getPosition());
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
    typing.setPosition({textbox.getPosition().x+5, textbox.getPosition().y-5});
    if(!typing.getString().empty())
        cursor.setPosition({cursor.getPosition().x + typing.getLastPosition().x,typing.getLastPosition().y+2});
    else
        cursor.setPosition({textbox.getPosition().x+1, textbox.getPosition().y-2});
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

void TextInput::setPosition(sf::Vector2f pos) {
    textbox.setPosition(pos);
}

void TextInput::setFillColor(sf::Color color) {
    textbox.setFillColor(color);
}

sf::FloatRect TextInput::getGlobalBounds() {
    return textbox.getGlobalBounds();
}

void TextInput::setSize(sf::Vector2f size) {
    textbox.setSize(size);
}
