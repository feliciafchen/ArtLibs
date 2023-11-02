//
// Created by Felicia Chen on 10/31/23.
//

#ifndef TEXTINPUT_SNAPSHOT_H
#define TEXTINPUT_SNAPSHOT_H
#include <SFML/Graphics.hpp>

class Snapshot {
private:
    sf::String data;
public:
    const sf::String &getData() const;
    void setData(const sf::String &data);
};

#endif //TEXTINPUT_SNAPSHOT_H
