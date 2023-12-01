//
// Created by Felicia Chen on 11/30/23.
//

#ifndef TEXTINPUT_ARTIFY_H
#define TEXTINPUT_ARTIFY_H
#include "GUIComponent.h"
#include "Logo.h"
#include "Files.h"
#include "PromptScreen.h"
#include "EditScreen.h"

class Artify : public GUIComponent {
private:
    Logo logo;
    Files myArt;
    PromptScreen promptScreen;
    EditScreen editScreen;
    bool screen;
public:
    Artify();
    //required functions
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    //not used here
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};


#endif //TEXTINPUT_ARTIFY_H
