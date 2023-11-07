//
// Created by Felicia Chen on 10/14/23.
//

#ifndef TEXTINPUT_TYPING_H
#define TEXTINPUT_TYPING_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "MultiText.h"
#include "Cursor.h"
#include "GUIComponent.h"
#include "MouseEvents.h"

class Typing : public sf::Drawable, public States{
private:
    MultiText text;
public:
    Typing();
    Typing(sf::Vector2f,const std::string& text, const sf::Font& font, const sf::Color& color, unsigned int size);
    void setString(const std::string& text);
    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getLastPosition();
    void setSize(unsigned int size);
    void setFont(const sf::Font& font);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_TYPING_H
