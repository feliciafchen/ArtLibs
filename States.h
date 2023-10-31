//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_STATES_H
#define TEXTINPUT_STATES_H
#include "ObjectState.h"
#include <map>

class States {
private:
    std::map<ObjectState, bool> states;
public:
    States();
    bool checkState(ObjectState state) const;
    void enableState(ObjectState state);
    void disableState(ObjectState state);
    void toggleState(ObjectState state);
};


#endif //TEXTINPUT_STATES_H
