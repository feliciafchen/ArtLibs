//
// Created by Felicia Chen on 11/30/23.
//

#include "Artify.h"

void Artify::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(logo);
    if(isEditScreen)
        window.draw(editScreen);
    else
        window.draw(promptScreen);
    window.draw(myArt);
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
    if(promptScreen.checkState(HIDDEN) && !isEditScreen){
        isEditScreen = true;
        std::string imageUrl = API::getImage(promptScreen.getFullPrompt());
        std::cout << imageUrl;
        std::string filePath = "images/artified.png";

        texture.loadFromFile(filePath);
        if (API::DownloadImageToFile(imageUrl, filePath)) {
            texture.loadFromFile(filePath);
        }
        editScreen = EditScreen(texture, promptScreen.getFullPrompt());
    }
    if(editScreen.checkState(HIDDEN) && isEditScreen){
        isEditScreen = false;
        promptScreen = PromptScreen();
        promptScreen.disableState(HIDDEN);
    }
    if(editScreen.checkState(SAVED)){
        editScreen.disableState(SAVED);
        myArt.push(editScreen.getFileName());
    }
    if(myArt.checkState(SELECTED)){
        isEditScreen = true;
        std::string filePath = "my_art/" + myArt.getSelectedText();
        texture.loadFromFile(filePath);
        editScreen = EditScreen(texture, true);
        myArt.deselect();
    }
}

Snapshot &Artify::getSnapshot() {
}

void Artify::applySnapshot(const Snapshot &snapshot) {
}

Artify::Artify() : isEditScreen(false){

}
