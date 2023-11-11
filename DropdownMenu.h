//
// Created by Felicia Chen on 11/10/23.
//

#ifndef TEXTINPUT_DROPDOWNMENU_H
#define TEXTINPUT_DROPDOWNMENU_H
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"
#include "GUIComponent.h"

class DropdownMenu : public GUIComponent {
private:
//    ItemList list;
    InputBox inputBox;
public:
    DropdownMenu();

};


#endif //TEXTINPUT_DROPDOWNMENU_H
