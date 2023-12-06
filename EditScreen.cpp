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
    if(checkState(REARTIFY)){
        target.draw(regenerate);
        target.draw(promptDisplay);
    }
}

void EditScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    if(saveImage.checkState(HIDDEN)){
        reartify.addEventHandler(window, event);
        if(!save.checkState(DISABLED))
            save.addEventHandler(window, event);
        if(checkState(REARTIFY)){
            regenerate.addEventHandler(window, event);
            promptDisplay.addEventHandler(window, event);
        }
    }
    saveImage.addEventHandler(window,event);
}

void EditScreen::update() {
    if(!save.checkState(DISABLED))
        save.update();
    reartify.update();
    saveImage.update();
    regenerate.update();
    promptDisplay.update();
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
    if(regenerate.checkState(CLICKED)){
        regenerate.disableState(CLICKED);
        std::string imageUrl = API::getImage(request);
        std::cout << std::endl << imageUrl;
        std::string filePath = "images/artified.png";

        if (API::DownloadImageToFile(imageUrl, filePath)) {
            texture.loadFromFile(filePath);
        }
        this->image.setTexture(texture);
        save.disableState(CLICKED);
        save.disableState(DISABLED);
        save.setLabel("Save");
        disableState(SAVED);
        saveImage = SaveImage();
    }
}

EditScreen::EditScreen() {

}

EditScreen::EditScreen(const sf::Texture& texture, const std::string& request) {
    this->texture = texture;
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);
    save.setLabel("Save");
    save.setPosition({image.getPosition().x, 620});

    this -> request = request;
    enableState(REARTIFY);

    promptDisplay = PromptDisplay(request, {image.getGlobalBounds().width, image.getGlobalBounds().height}, {1325/2 - image.getGlobalBounds().width/2,
                                  static_cast<float>(745/2 - image.getGlobalBounds().height/2.2)});

    regenerate.setLabel("Reartify");
    regenerate.setPosition({1325/2 - regenerate.getGlobalBounds().width/2, 620});

    reartify.setLabel("New");
    reartify.setPosition({image.getPosition().x + image.getGlobalBounds().width - reartify.getGlobalBounds().width, 620});
}
EditScreen::EditScreen(const sf::Texture& texture, bool) {
    this->image.setTexture(texture);
    this->image.scale({.4,.4});
    this->image.setPosition(1325/2 - image.getGlobalBounds().width/2,
                            745/2 - image.getGlobalBounds().height/2.2);

    save.setPosition({1325/2 - reartify.getGlobalBounds().width - 35, 620});
    save.setSaved();
    save.enableState(DISABLED);

    disableState(REARTIFY);

    reartify.setLabel("New");
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

