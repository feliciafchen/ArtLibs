//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_SNAPSHOTINTERFACE_H
#define TEXTINPUT_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface {
// this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //TEXTINPUT_SNAPSHOTINTERFACE_H
