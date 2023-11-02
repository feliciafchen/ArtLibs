//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H
#include "GUIComponent.h"
class TextInput : public GUIComponent{
public:
    void setLabel(sf::String label);
    void setLabelSize(sf::Vector2f);
};

#endif //TEXTINPUT_TEXTINPUT_H
