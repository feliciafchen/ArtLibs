#include <SFML/Graphics.hpp>
#include "Application.h"
#include "DropdownMenu.h"
#include "TextInput.h"
#include "Menu.h"

int main() {
    std::vector<std::string> options = {"Item 1", "Item 2", "Item 3"};
    Menu menu("Menu 1", options, 25);
    menu.setBoxSize({200,50});
    menu.setFillColor(sf::Color::Transparent);
    menu.setOutlineColor(sf::Color::White);
    menu.setOutlineThickness(1);
    menu.setTextColor(sf::Color::White);
    menu.setPosition({100,100});

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
            menu.addEventHandler(window, event);

        }
        menu.update();
        window.clear();
        window.draw(menu);
        window.display();
    }

//    std::vector<std::string> items{"apples", "bananas", "strawberry"};
//    DropdownMenu item(items,25);
//    item.setBoxSize({400,50});
//    item.setFillColor(sf::Color::Transparent);
//    item.setOutlineColor(sf::Color::Black);
//    item.setOutlineThickness(1);
//    item.setTextColor(sf::Color::Black);
//    item.setPosition({100,100});
//
//    TextInput ti("First Name:",25, {10,10},200,sf::Color::Black,sf::Color::Black,sf::Color::Transparent,sf::Color::Black,1);
//
//    Application::addComponent(item);
//    Application::addComponent(ti);
//    Application::run();
}
