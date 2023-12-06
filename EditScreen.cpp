//
// Created by Felicia Chen on 11/30/23.
//

#include "EditScreen.h"

void EditScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(checkState(HIDDEN))
        return;
    target.draw(image);
    target.draw(save);
    target.draw(reartify);
    target.draw(saveImage);
}

void EditScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    if(saveImage.checkState(HIDDEN)){
        reartify.addEventHandler(window, event);
        if(!save.checkState(DISABLED))
            save.addEventHandler(window, event);
    }
    saveImage.addEventHandler(window,event);
}

void EditScreen::update() {
    if(!save.checkState(DISABLED))
        save.update();
    reartify.update();
    saveImage.update();
    if(reartify.checkState(CLICKED)){
        enableState(HIDDEN);
        reartify.disableState(CLICKED);
    }
    if(save.checkState(CLICKED) && !saveImage.checkState(SAVED)){
        saveImage.disableState(HIDDEN);
        save.disableState(CLICKED);
    }
    if(saveImage.checkState(SAVED)){
        saveImage.disableState(SAVED);
        save.setLabel("Saved!");
        save.enableState(DISABLED);
        fileName = saveImage.getFileName();
        enableState(SAVED);
        image.getTexture()->copyToImage().saveToFile("my_art/" + saveImage.getFileName());
    }
}

EditScreen::EditScreen() {

}

EditScreen::EditScreen(const sf::Texture& texture) {
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);
    save.setLabel("Save");
    save.setPosition({1325/2 - reartify.getGlobalBounds().width - 35, 620});

    reartify.setLabel("Reartify");
    reartify.setPosition({1325/2 + reartify.getGlobalBounds().width/2 - 10, 620});
}
EditScreen::EditScreen(const sf::Texture& texture, bool) {
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);

    save.setPosition({1325/2 - reartify.getGlobalBounds().width - 35, 620});
    save.setLabel("Saved!");
    save.setFillColor(sf::Color(217, 217, 217));
    save.enableState(DISABLED);

    reartify.setLabel("Reartify");
    reartify.setPosition({1325/2 + reartify.getGlobalBounds().width/2 - 10, 620});
}

void EditScreen::setImage(const sf::Texture &texture) {
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);
}

const std::string &EditScreen::getFileName() {
    return fileName;
}

