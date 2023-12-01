//
// Created by Felicia Chen on 11/30/23.
//

#include "Artify.h"

void Artify::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(logo);
    window.draw(myArt);
    if(isEditScreen)
        window.draw(editScreen);
    else
        window.draw(promptScreen);
}

void Artify::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    myArt.addEventHandler(window, event);
    if(isEditScreen)
        editScreen.addEventHandler(window, event);
    else
        promptScreen.addEventHandler(window, event);
}

void Artify::update() {
    myArt.update();
    if(isEditScreen){
        logo.enableEditState();
        editScreen.update();
    }
    else{
        logo.enablePromptState();
        promptScreen.update();
    }
    if(promptScreen.checkState(HIDDEN) && isEditScreen == false){
        isEditScreen = true;
//        std::string imageUrl = API::getImage(promptScreen.getFullPrompt());
//        std::cout << imageUrl;
        std::string filePath = "images/artified.png";

        texture.loadFromFile(filePath);
//        if (API::DownloadImageToFile(imageUrl, filePath)) {
//            texture.loadFromFile(filePath);
//        }
        editScreen = EditScreen(texture);
    }
}

Snapshot &Artify::getSnapshot() {
}

void Artify::applySnapshot(const Snapshot &snapshot) {
}

bool Artify::getEditScreen() const {
    return isEditScreen;
}

void Artify::setEditScreen(bool screen) {
    Artify::isEditScreen = screen;
}

Artify::Artify() : isEditScreen(false){

}
