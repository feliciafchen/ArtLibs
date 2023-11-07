#include <SFML/Graphics.hpp>
#include "Application.h"
#include "TextInput.h"

int main() {
    TextInput ti;
    ti.setLabel("This is a test label:");

    ti.setLabelSize(12);
    ti.setLabelMargin({15,0,2,5});
    ti.setPosition({0,0});

    Application::addComponent(ti);
    Application::run();
}
