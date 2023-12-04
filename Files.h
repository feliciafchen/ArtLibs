//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_FILES_H
#define TEXTINPUT_FILES_H
#include <SFML/Graphics.hpp>
#include "FileTree.h"
#include <fstream>

class Files : public EventHandler, public sf::Drawable {
private:
    FileTree files;
public:
    Files();
    void push(const std::string& filename);
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //TEXTINPUT_FILES_H
