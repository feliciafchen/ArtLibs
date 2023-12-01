//
// Created by Felicia Chen on 12/1/23.
//

#include "SaveImage.h"

void SaveImage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    target.draw(background);
    target.draw(input);
    target.draw(button);
    target.draw(name);

}

void SaveImage::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    input.addEventHandler(window, event);
    button.addEventHandler(window, event);
}

void SaveImage::update() {
    if(checkState(HIDDEN))
        return;
    input.update();
    button.update();
    if(button.checkState(CLICKED)){
        enableState(SAVED);
        enableState(HIDDEN);
    }
}

SaveImage::SaveImage() {
    enableState(HIDDEN);
    disableState(SAVED);
    background.setFillColor(sf::Color(237,237,237));
    background.setSize({500,250});
    background.setPosition(1325/2 - 500/2, 745/2 - 250/2);
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color(217,217,217));

    input.setSize({250,30});
    input.setPosition({background.getPosition().x + background.getGlobalBounds().width/2 - 250/2,
                       background.getPosition().y + background.getGlobalBounds().height/2 - 10});
    input.setFillColor(sf::Color::White);
    button.setLabel("Save");
    button.setPosition({background.getPosition().x + background.getGlobalBounds().width/2 - button.getGlobalBounds().width/2,
                      background.getPosition().y + background.getGlobalBounds().height/2 + button.getGlobalBounds().height});

    name = sf::Text("filename: ", Fonts::getFont(KIRANG_HAERANG), 30);
    name.setFillColor(sf::Color::Black);
    name.setPosition({background.getPosition().x + background.getGlobalBounds().width/2 - name.getGlobalBounds().width/2,
                       background.getPosition().y + background.getGlobalBounds().height/2 - name.getGlobalBounds().height * 3});
}

const std::string &SaveImage::getFileName() {
    updateFileName();
    return fileName;
}

void SaveImage::updateFileName() {
    fileName = input.getString();
}
