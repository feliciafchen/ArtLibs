//
// Created by Felicia Chen on 11/30/23.
//

#include "PromptScreen.h"

void PromptScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)){
        for (auto& word : words) {
            target.draw(word);
        }
        target.draw(styleType);
        target.draw(artType);
        target.draw(adjective);
        target.draw(noun);
        target.draw(place);
        target.draw(verb);
        target.draw(where);
        target.draw(pluralNoun);
//    target.draw(artify);
    }
}

void PromptScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    styleType.addEventHandler(window,event);
    artType.addEventHandler(window, event);
    adjective.addEventHandler(window, event);
    noun.addEventHandler(window, event);
    place.addEventHandler(window, event);
    verb.addEventHandler(window, event);
    where.addEventHandler(window, event);
    pluralNoun.addEventHandler(window, event);
//    artify.addEventHandler(window, event);
}

void PromptScreen::update() {
    styleType.update();
    artType.update();
    adjective.update();
    noun.update();
    place.update();
    verb.update();
    where.update();
    pluralNoun.update();
    updatePrompt();
//    artify.update();
//    if(artify.clicked())
//        enableState(HIDDEN);
}

PromptScreen::PromptScreen() {
    disableState(HIDDEN);
    std::vector<std::string> styleChoices {"realism", "impressionism", "abstract","surrealism",
                                           "pop art", "minimalism", "anime/manga", "pixar"};
    std::vector<std::string> artChoices {"oil painting", "acrylic painting", "sketch", "charcoal drawing",
                                           "sculpture", "photograph", "comic", "street art"};
    std::vector<std::string> whereChoices {"next to", "in front of", "behind", "above", "below"};
    styleType = DropdownMenu(styleChoices, 30);
    styleType.setPosition({100,100});

    artType = DropdownMenu(artChoices, 30);
    artType.setPosition({600, 100});

    where = DropdownMenu(whereChoices,30);
    where.setPosition({300, 200});
}

const std::string &PromptScreen::getFullPrompt() {
    return fullPrompt;
}

void PromptScreen::updatePrompt() {
    fullPrompt = "A " + styleType.getSelected().getText() + " style "
            + artType.getSelected().getText() + " of a " + adjective.getString()
            + " " + noun.getString() + " in the middle of a " + place.getString()
            + " " + verb.getString() + " " + where.getSelected().getText() + " "
            + pluralNoun.getString();
}
