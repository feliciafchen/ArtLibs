//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_SNAPSHOT_H
#define TEXTINPUT_SNAPSHOT_H
#include <iostream>

class Snapshot {
private:
    std::string data;
public:
    Snapshot();
    explicit Snapshot(std::string data);
    const std::string &getData() const;
    void setData(const std::string &data);
};

#endif //TEXTINPUT_SNAPSHOT_H
