//
// Created by Felicia Chen on 10/31/23.
//

#include "Application.h"

std::vector<GUIComponent*> Application::components;
void Application::addComponent(GUIComponent &component) {
    components.push_back(&component);
}

void Application::run() {

    sf::RenderWindow window({1325, 745}, "Art Libs");
    window.setFramerateLimit(60);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            for (auto g: components) {
                g->addEventHandler(window, event);
            }
        }
        for(auto g : components)
            g->update();

        window.clear(sf::Color::White);
        for (auto g: components)
            window.draw(*g);
        window.display();
    }
}
