#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Application.h"
#include "API.h"

int main() {

    std::string imageUrl = "https://oaidalleapiprodscus.blob.core.windows.net/private/org-4Ta4ceiC1Xg7z1Accpgokit9/user-iA6glXUGteYJBocksTorkhIs/img-2i1Kq3HQVdu8F3D2gSGh5pPo.png?st=2023-11-30T18%3A48%3A35Z&se=2023-11-30T20%3A48%3A35Z&sp=r&sv=2021-08-06&sr=b&rscd=inline&rsct=image/png&skoid=6aaadede-4fb3-4698-a8f6-684d7786b067&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2023-11-30T19%3A12%3A54Z&ske=2023-12-01T19%3A12%3A54Z&sks=b&skv=2021-08-06&sig=oqQ2J0Aef5Ibk/lbMVjYWW8JFuiFHbvD80UF1iFFJlU%3D";

    std::string filePath = "images/artified.png";

    if (API::DownloadImageToFile(imageUrl, filePath)) {
        sf::Texture texture;
        if (texture.loadFromFile(filePath)) {
            sf::Sprite sprite(texture);
            sprite.setScale(.25,.25);
            sprite.setPosition(250,250);

            sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "SFML Image from File");
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                window.clear();
                window.draw(sprite);
                window.display();
            }
        } else {
            std::cerr << "Failed to load image from file." << std::endl;
        }
    } else {
        std::cerr << "Failed to download and save image." << std::endl;
    }

    return 0;

//    std::vector<std::string> items{"apples", "bananas", "strawberry"};
//    DropdownMenu item(items,25);
//    item.setBoxSize({400,50});
//    item.setFillColor(sf::Color::Transparent);
//    item.setOutlineColor(sf::Color::Black);
//    item.setOutlineThickness(1);
//    item.setTextColor(sf::Color::Black);
//    item.setPosition({100,100});
//
//    Artify ti("First Name:",25, {10,10},200,sf::Color::Black,sf::Color::Black,sf::Color::Transparent,sf::Color::Black,1);
//
//    Application::addComponent(item);
//    Application::addComponent(ti);
//    Application::run();
}
