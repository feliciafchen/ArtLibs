//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_HISTORY_H
#define TEXTINPUT_HISTORY_H
#include "HistoryNode.h"
#include "KeyShortcuts.h"
#include <stack>

class History {
private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //TEXTINPUT_HISTORY_H
