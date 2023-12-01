//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_PROMPTSCREEN_H
#define TEXTINPUT_PROMPTSCREEN_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "DropdownMenu.h"
#include "TextInput.h"
#include "Button.h"

class PromptScreen : public sf::Drawable, public EventHandler {
private:
    std::vector<sf::Text> words;
    std::string fullPrompt;
    DropdownMenu styleType;
    DropdownMenu artType;
    TextInput adjective;
    TextInput noun;
    TextInput event;
    TextInput verb;
    DropdownMenu where;
    TextInput pluralNoun;
    Button artify;
public:
    PromptScreen();
    const std::string& getFullPrompt();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //TEXTINPUT_PROMPTSCREEN_H
