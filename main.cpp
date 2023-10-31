#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Box.h"

int main() {
    Box box;
    Application::addComponent(box);
    Application::run();
}
