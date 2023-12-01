//
// Created by Felicia Chen on 12/1/23.
//

#ifndef ARTIFY_SAVEIMAGE_H
#define ARTIFY_SAVEIMAGE_H
#include "SFML/Graphics.hpp"
#include "EventHandler.h"
#include "States.h"
#include "TextInput.h"
#include "Button.h"

class SaveImage : public sf::Drawable, public EventHandler, public States{
private:
    sf::RectangleShape background;
    sf::Text name;
    std::string fileName;
    TextInput input;
    Button button;
    void updateFileName();
public:
    SaveImage();
    const std::string& getFileName();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //ARTIFY_SAVEIMAGE_H
