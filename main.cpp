#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Application.h"
#include "API.h"
#include "Artify.h"
#include "Logo.h"
#include "DropdownMenu.h"

int main() {

    std::string imageUrl = "https://oaidalleapiprodscus.blob.core.windows.net/private/org-4Ta4ceiC1Xg7z1Accpgokit9/user-iA6glXUGteYJBocksTorkhIs/img-MMp0Fikx3EUXr3GZrJWFf2yQ.png?st=2023-12-01T00%3A22%3A24Z&se=2023-12-01T02%3A22%3A24Z&sp=r&sv=2021-08-06&sr=b&rscd=inline&rsct=image/png&skoid=6aaadede-4fb3-4698-a8f6-684d7786b067&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2023-11-30T23%3A19%3A58Z&ske=2023-12-01T23%3A19%3A58Z&sks=b&skv=2021-08-06&sig=k/4tdjLCKZ7neiNz7v7MIsEYmsN0cOn5dtIvyjTZ7Bg%3D";
    std::cout << imageUrl;
    std::string filePath = "images/artified.png";

    Files files;

    Logo logo;
    std::vector<std::string> words = {"pixar", "art deco", "abstract", "realistic", "anime", "minimalistic"};
    std::vector<std::string> words2 = {"comic", "painting", "sculpture", "watercolor", "sketch", "photograph"};

    DropdownMenu item(words,25);
    item.setBoxSize({200,50});
    item.setFillColor(sf::Color(217,217,217));
    item.setOutlineColor(sf::Color::White);
    item.setOutlineThickness(3);
    item.setTextColor(sf::Color::Black);
    item.setPosition({10,10});

    if (API::DownloadImageToFile(imageUrl, filePath)) {
        sf::Texture texture;
        if (texture.loadFromFile(filePath)) {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setScale(.25,.25);
            sprite.setPosition(250,250);

            sf::RenderWindow window(sf::VideoMode(1325, 745), "Art Libs");
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    item.addEventHandler(window, event);
                    files.addEventHandler(window, event);
                }
                item.update();
                files.update();

                window.clear(sf::Color::White);
                window.draw(logo);
                window.draw(files);
                window.display();
            }
        } else {
            std::cerr << "Failed to load image from file." << std::endl;
        }
    } else {
        std::cerr << "Failed to download and save image." << std::endl;
    }

    return 0;
//    Artify artify;
//    Application::addComponent(artify);
//    Application::run();
}
