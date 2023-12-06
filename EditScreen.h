//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_EDITSCREEN_H
#define TEXTINPUT_EDITSCREEN_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Button.h"
#include "API.h"
#include "SaveImage.h"

class EditScreen : public sf::Drawable, public EventHandler, public States {
private:
    sf::Sprite image;
    Button save;
    Button reartify;
    SaveImage saveImage;
    std::string fileName;
public:
    EditScreen();
    EditScreen(const sf::Texture& texture);
    EditScreen(const sf::Texture& texture, bool);
    void setImage(const sf::Texture& texture);
    const std::string& getFileName();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //TEXTINPUT_EDITSCREEN_H
