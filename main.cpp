#include <SFML/Graphics.hpp>
#include "Application.h"
#include "DropdownMenu.h"
#include "TextInput.h"
#include "Menu.h"
#include "MenuBar.h"
#include "FileItem.h"
#include "ImageEnum.h"
#include "FileNode.h"
#include "FileTree.h"

int main() {
    FileNode child2(FILE_ICON, "child2", {200, 50}, {100, 100});
    FileNode child(FILE_ICON, "child", {200, 50}, {100, 100});
    FileNode tree(FOLDER_ICON, "File 1", {200, 50}, {100, 100});
    FileNode tree2(FILE_ICON, "File 1", {200, 50}, {100, 100});
    tree2.addChild(&child);
    tree2.addChild(&child2);
    tree.addChild(&tree2);

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
            tree.addEventHandler(window, event);
        }
        tree.update();
        window.clear();
        window.draw(tree);
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
