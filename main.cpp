#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Application.h"
#include "API.h"
#include "Artify.h"
#include "Logo.h"
#include "DropdownMenu.h"

int main() {
    Artify artify;
    Application::addComponent(artify);
    Application::run();
}
