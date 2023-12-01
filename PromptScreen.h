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

class PromptScreen : public sf::Drawable, public EventHandler, public States {
private:
    std::vector<sf::Text> words = {sf::Text("style",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("of a",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("in the middle of a",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text(".",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("(adjective)",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("(noun)",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("(place)",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("(action)",Fonts::getFont(KIRANG_HAERANG)),
                                   sf::Text("(plural noun)",Fonts::getFont(KIRANG_HAERANG))};
    std::string fullPrompt;
    DropdownMenu styleType;
    DropdownMenu artType;
    TextInput adjective;
    TextInput noun;
    TextInput place;
    TextInput verb;
    DropdownMenu where;
    TextInput pluralNoun;
    Button artify;
    void updatePrompt();
public:
    PromptScreen();
    const std::string& getFullPrompt();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //TEXTINPUT_PROMPTSCREEN_H
