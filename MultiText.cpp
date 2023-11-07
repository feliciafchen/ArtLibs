//
// Created by Felicia Chen on 10/17/23.
//

#include "MultiText.h"
#include "iostream"
MultiText::MultiText() : MultiText({100,100}, "", Fonts::getFont(FREE_SANS), sf::Color::Black, 24){
}

MultiText::MultiText(sf::Vector2f position, const std::string &text, const sf::Font &font, const sf::Color &color, unsigned int size) {
    this->firstPos = position;
    setPosition(position);
    setString(text);
    setFont(font);
    setFillColor(color);
    setSize(size);

    placeholder.setPosition(position);
    placeholder.setString(text);
    placeholder.setFont(font);
    placeholder.setFillColor(color);
    placeholder.setCharacterSize(size);
}

void MultiText::setString(const std::string &text) {
    push(text);
    placeholder.setString(text);
}

sf::String MultiText::getText() {
    sf::String string = "";
    auto iter = multiText.begin();
    for (; iter != multiText.end(); ++iter) {
        string += (*iter).getString();
    }
    return string;
}

void MultiText::setFillColor(const sf::Color &color) {
    auto iter = multiText.begin();
    for (; iter != multiText.end(); ++iter) {
        (*iter).setFillColor(color);
    }
}

void MultiText::setPosition(const sf::Vector2f &position) {
    firstPos = position;
}


void MultiText::setSize(unsigned int size) {
    auto iter = multiText.begin();
    for (; iter != multiText.end(); ++iter) {
        (*iter).setCharacterSize(size);
    }
}

void MultiText::setFont(const sf::Font &font) {
    auto iter = multiText.begin();
    for (; iter != multiText.end(); ++iter) {
        (*iter).setFont(font);
    }
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    auto iter = multiText.begin();
    for (; iter != multiText.end(); ++iter) {
        window.draw(*iter);
    }
}

void MultiText::push(char c) {
    multiText.emplace_back(c, getLastPosition());
}

void MultiText::push(const std::string &s) {
    for (int i = 0; i < s.size(); ++i) {
        multiText.emplace_back(s[i], getLastPosition());
    }
}

MultiText::iterator MultiText::begin() {
    return multiText.begin();
}

MultiText::iterator MultiText::end() {
    return multiText.end();
}

void MultiText::update() {
    if(!multiText.empty()){
        auto iter = multiText.begin();

        sf::Vector2f tempPos = (*iter).getPosition();
        sf::Glyph g = (*iter).getFont()->getGlyph((*iter).getString()[0], (*iter).getCharacterSize(), false);

        for (; iter != multiText.end(); ++iter) {
            (*iter).setPosition(tempPos);
            g = (*iter).getFont()->getGlyph((*iter).getString()[0], (*iter).getCharacterSize(), false);
            tempPos.x += g.advance;
        }
    }
}

void MultiText::pop() {
    if(!multiText.empty())
        multiText.pop_back();
}

sf::Vector2f MultiText::getLastPosition() {
    if (!multiText.empty()) {
        auto iter = multiText.rbegin();
        sf::Vector2f pos = iter->getPosition();
        sf::Glyph g = iter->getFont()->getGlyph((*iter).getString()[0], (*iter).getCharacterSize(), false);
        pos.x += g.advance;

        std::cout << pos.x;
        return pos;
    }
    return firstPos;
}
