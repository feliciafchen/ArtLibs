//
// Created by Felicia Chen on 11/16/23.
//

#include "Images.h"

void Images::loadImage(imageEnum image) {
    images[image].loadFromFile(getImagePath(image));
}

std::string Images::getImagePath(imageEnum img) {
    std::string f[] = {"images/file.png", "images/file.png", "images/artifylogo.png", "images/artified.png"};
    return f[img];
}

sf::Texture &Images::getImage(imageEnum image) {
    loadImage(image);
    return images[image];
}
