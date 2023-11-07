//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_GUICOMPONENT_H
#define TEXTINPUT_GUICOMPONENT_H
#include "EventHandler.h"
#include "SnapshotInterface.h"
#include "States.h"

class GUIComponent : public EventHandler,
        public States, public SnapshotInterface, public sf::Drawable, public sf::Transformable{
public:
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override = 0;
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override = 0;
    void update() override = 0;
    Snapshot& getSnapshot() override = 0;
    void applySnapshot(const Snapshot& snapshot) override = 0;
};


#endif //TEXTINPUT_GUICOMPONENT_H
