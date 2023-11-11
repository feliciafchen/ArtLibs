#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Item.h"

int main() {
    Item item("HELLO",{5,5},25);
    item.setFillColor(sf::Color::Black);
    item.setOutlineColor(sf::Color::White);
    item.setOutlineThickness(1);
    item.setBoxSize({250,50});
    item.setTextColor(sf::Color::White);

    sf::VideoMode videoMode(1400, 900, 32);
    sf::RenderWindow window(videoMode, "Typing");
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            item.addEventHandler(window, event);

        }
        item.update();
        window.clear();
        window.draw(item);
        window.display();
    }

//    Application::addComponent(item);
//    Application::run();
}
