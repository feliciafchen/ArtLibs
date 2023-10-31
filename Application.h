//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_APPLICATION_H
#define TEXTINPUT_APPLICATION_H
#include <vector>
#include "GUIComponent.h"

class Application {
private:
    static std::vector<GUIComponent*> components;
public:
    static void addComponent(GUIComponent &component);
    static void run();
};

#endif //TEXTINPUT_APPLICATION_H
