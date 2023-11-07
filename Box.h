//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_BOX_H
#define TEXTINPUT_BOX_H
#include "States.h"
#include "GUIComponent.h"

class Box : public GUIComponent {
private:
    sf::RectangleShape box;
public:
    Box();
    explicit Box(const sf::Vector2f& size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
};


#endif //TEXTINPUT_BOX_H
