#include <SFML/Graphics.hpp>
#include "Typing.h"
#include "States.h"

int main() {
//    Typing typing;

    States

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
//            typing.addEventHandler(window, event);

        }
//        typing.update();
        window.clear();
//        window.draw(typing);
        window.display();
    }
}
