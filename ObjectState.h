//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_OBJECTSTATE_H
#define TEXTINPUT_OBJECTSTATE_H

enum ObjectState {
    HOVERED,
    CLICKED,
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    CHILDREN_SHOWING,
    SAVED,
    DOUBLE_CLICKED,
    FIRST,
    SELECTED,
    ///This should always be the last state
    LASTSTATE
};

#endif //TEXTINPUT_OBJECTSTATE_H
