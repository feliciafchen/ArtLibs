#include <SFML/Graphics.hpp>
#include "Application.h"
#include "DropdownMenu.h"

int main() {
    std::vector<std::string> items{"apples", "bananas", "strawberry"};
    DropdownMenu item(items,25);
    item.setBoxSize({400,50});
    item.setFillColor(sf::Color::Transparent);
    item.setOutlineColor(sf::Color::White);
    item.setOutlineThickness(1);
    item.setTextColor(sf::Color::White);
    item.setPosition({10,10});

    Application::addComponent(item);
    Application::run();
}
