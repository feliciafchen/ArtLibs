//
// Created by Felicia Chen on 11/30/23.
//

#include "PromptScreen.h"

void PromptScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN)){
        for (auto& word : words) {
            target.draw(word);
        }
        target.draw(artify);
        target.draw(adjective);
        target.draw(noun);
        target.draw(place);
        target.draw(verb);
        target.draw(where);
        target.draw(pluralNoun);
        target.draw(styleType);
        target.draw(artType);
    }
}

void PromptScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(HIDDEN))
        return;
    styleType.addEventHandler(window,event);
    artType.addEventHandler(window, event);
    where.addEventHandler(window, event);
    if(!styleType.checkState(CLICKED) && !artType.checkState(CLICKED) && !where.checkState(CLICKED)){
        adjective.addEventHandler(window, event);
        noun.addEventHandler(window, event);
        place.addEventHandler(window, event);
        verb.addEventHandler(window, event);
        pluralNoun.addEventHandler(window, event);
        artify.addEventHandler(window, event);
    }
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
    artify.update();
    if(artify.checkState(CLICKED)){
        std::cout << getFullPrompt();
        enableState(HIDDEN);
        artify.disableState(CLICKED);
    }
}

PromptScreen::PromptScreen() {
    disableState(HIDDEN);
    artify.setLabel("Artify");
    artify.setPosition({1325/2 - artify.getGlobalBounds().width/2, 550});
    //initializing words
    {
        for(auto& word : words)
            word.setFillColor(sf::Color::Black);
        words[0].setPosition({497,309});
        words[1].setPosition({780, 309});
        words[2].setPosition({533,370});
        words[3].setPosition({994, 437});
    }
    //initializing dropdowns
    {
        std::vector<std::string> styleChoices {"realism", "impressionism", "abstract","surrealism",
                                               "pop art", "minimalism", "anime/manga", "pixar"};
        std::vector<std::string> artChoices {"oil painting", "acrylic painting", "sketch", "charcoal art",
                                             "movie poster", "photograph", "comic", "watercolor"};
        std::vector<std::string> whereChoices {"next to", "in front of", "behind", "above", "below"};
        styleType = DropdownMenu(styleChoices, 30);
        styleType.setPosition({280,310});

        artType = DropdownMenu(artChoices, 30);
        artType.setPosition({570, 309});

        where = DropdownMenu(whereChoices,30);
        where.setPosition({550, 437});
    }
   //initializing textinputs
    {
        adjective.setPosition({876, 310});
        words[4].setCharacterSize(20);
        words[4].setPosition({930, 340});
        noun.setPosition({320, 371});
        words[5].setCharacterSize(20);
        words[5].setPosition({395, 401});
        place.setPosition({825, 372});
        words[6].setCharacterSize(20);
        words[6].setPosition({890, 401});
        verb.setPosition({315, 437});
        words[7].setCharacterSize(20);
        words[7].setPosition({385, 467});
        pluralNoun.setPosition({790, 437});
        words[8].setCharacterSize(20);
        words[8].setPosition({835, 467});
    }
}

const std::string &PromptScreen::getFullPrompt() {
    updatePrompt();
    return fullPrompt;
}

void PromptScreen::updatePrompt() {
    fullPrompt = "A " + styleType.getSelected().getText() + " style "
            + artType.getSelected().getText() + " of a(n) " + adjective.getString()
            + " " + noun.getString() + " in the middle of a(n) " + place.getString()
            + " " + verb.getString() + " " + where.getSelected().getText() + " "
            + pluralNoun.getString();
}
