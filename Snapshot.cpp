//
// Created by Felicia Chen on 11/2/23.
//
#include "Snapshot.h"

#include <utility>

Snapshot::Snapshot() {

}

Snapshot::Snapshot(std::string data)
: data(std::move(data))
{

}

const std::string &Snapshot::getData() const {
    return data;
}

void Snapshot::setData(const std::string &data) {
    Snapshot::data = data;
}
