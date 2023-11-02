//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_GUICOMPONENT_H
#define TEXTINPUT_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "Snapshot.h"

class GUIComponent : public sf::Drawable{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
//    virtual Snapshot& getSnapshot() = 0;
//    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //TEXTINPUT_GUICOMPONENT_H
