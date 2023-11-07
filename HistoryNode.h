//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_HISTORYNODE_H
#define TEXTINPUT_HISTORYNODE_H
#include "Snapshot.h"
#include "GUIComponent.h"
struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //TEXTINPUT_HISTORYNODE_H
