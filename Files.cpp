//
// Created by Felicia Chen on 11/30/23.
//

#include "Files.h"

Files::Files() {
    system("cd /Users/feliciachen/CLionProjects/Fall23/Artify/");
    std::string command = "find  my_art > a.txt";
    system(command.c_str());
    std::ifstream fin;
    fin.open("a.txt");
    bool first = true;
    while(fin >> command)
    {
        if(first)
            files.push(command);
        files.push(command);
    }
    fin.close();
}

void Files::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    files.addEventHandler(window, event);
}

void Files::update() {
    files.update();
    if(files.checkState(SELECTED) && !checkState(SELECTED)){
        enableState(SELECTED);
    }
}

void Files::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(files);
}

void Files::push(const std::string &filename) {
    files.push("My Art/" + filename);
}

std::string Files::getSelectedText() {
    return files.getSelectedText();
}

void Files::deselect() {
    files.deselect();
    disableState(SELECTED);
}
