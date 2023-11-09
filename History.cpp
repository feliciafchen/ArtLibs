//
// Created by Felicia Chen on 10/31/23.
//

#include "History.h"

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    if(!stack.empty())
        stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.type == KeyShortcuts::isUndo()){
        stack.pop();
        topHistory().component -> applySnapshot(topHistory().snapshot);
    }
}

bool History::empty() {
    return stack.empty();
}
