#include <SFML/Graphics.hpp>
#include "Application.h"
#include "TextInput.h"
#include "Box.h"
#include "Typing.h"
#include "Fonts.h"

int main() {
    TextInput ti("First Name:", 20, {40,50}, 200, sf::Color::Black, sf::Color::Black, sf::Color::Transparent, sf::Color::Black, 1);

    Application::addComponent(ti);
    Application::run();
}
