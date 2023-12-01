//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_EDITSCREEN_H
#define TEXTINPUT_EDITSCREEN_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Button.h"

class EditScreen : public sf::Drawable, public EventHandler {
private:
    sf::Sprite image;
    Button save;
    Button reartify;
public:
    EditScreen();
    EditScreen(sf::Texture& image);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //TEXTINPUT_EDITSCREEN_H
