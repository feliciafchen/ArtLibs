//
// Created by Felicia Chen on 11/16/23.
//

#ifndef TEXTINPUT_IMAGES_H
#define TEXTINPUT_IMAGES_H
#include <SFML/Graphics.hpp>
#include <map>
#include "ImageEnum.h"

class Images {
private:
    static inline std::map<imageEnum, sf::Texture> images;
    static void loadImage(imageEnum image);
    static std::string getImagePath(imageEnum image);
public:
    static sf::Texture& getImage(imageEnum image);
};


#endif //TEXTINPUT_IMAGES_H
