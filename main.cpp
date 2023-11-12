#include <SFML/Graphics.hpp>
#include "Application.h"
#include "DropdownMenu.h"

int main() {
    std::vector<std::string> items{"hi", "there", "world"};
    DropdownMenu item(items,25);
    item.setBoxSize({250,50});
    item.setFillColor(sf::Color::Black);
    item.setOutlineColor(sf::Color::White);
    item.setOutlineThickness(1);
    item.setTextColor(sf::Color::White);
    item.setPosition({100,100});

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
