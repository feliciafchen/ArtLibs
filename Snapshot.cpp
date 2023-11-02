//
// Created by Felicia Chen on 11/2/23.
//
#include "Snapshot.h"

const sf::String &Snapshot::getData() const {
    return data;
}

void Snapshot::setData(const sf::String &data) {
    Snapshot::data = data;
}