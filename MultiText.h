//
// Created by Felicia Chen on 10/17/23.
//

#ifndef TEXTINPUT_MULTITEXT_H
#define TEXTINPUT_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include <list>
#include "Letter.h"
#include "Fonts.h"
#include "Cursor.h"

class MultiText : public sf::Drawable {
private:
    std::list<Letter> multiText;
    sf::Vector2f position;
public:
    typedef std::list<Letter>::iterator iterator;

    MultiText();
    MultiText(sf::Vector2f position, const std::string& text, const sf::Font& font, const sf::Color& color, unsigned int size);

    void push(char c);
    void push(const std::string& s);
    void pop();

    iterator begin();
    iterator end();

    void setString(const std::string& text);
    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getLastPosition();
    void setSize(unsigned int size);
    void setFont(const sf::Font& font);
    void update();
    std::string getString();
    sf::Vector2f getFirstPosition();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //TEXTINPUT_MULTITEXT_H
