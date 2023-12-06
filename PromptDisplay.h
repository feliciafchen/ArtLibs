//
// Created by Felicia Chen on 12/6/23.
//

#ifndef ARTIFY_PROMPTDISPLAY_H
#define ARTIFY_PROMPTDISPLAY_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "MouseEvents.h"
#include "Fonts.h"

class PromptDisplay : public EventHandler, public sf::Drawable, public States {
private:
    sf::RectangleShape background;
    sf::Text prompt;
public:
    PromptDisplay();
    PromptDisplay(const std::string& prompt, sf::Vector2f boxSize, sf::Vector2f position);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //ARTIFY_PROMPTDISPLAY_H
