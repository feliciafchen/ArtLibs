//
// Created by Felicia Chen on 10/31/23.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LASTSTATE; ++i) {
        states[static_cast<ObjectState>(i)] = false;
    }
}

bool States::checkState(ObjectState state) const{
    return states.at(state);
}

void States::enableState(ObjectState state) {
    states[state] = true;
}

void States::disableState(ObjectState state) {
    states[state] = false;
}

void States::toggleState(ObjectState state) {
    states[state] = !states[state];
}
