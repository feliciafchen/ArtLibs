//
// Created by Felicia Chen on 11/16/23.
//

#ifndef TEXTINPUT_FILEITEM_H
#define TEXTINPUT_FILEITEM_H
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "ImageEnum.h"

class FileItem : public Item
{
public:
    //Constructors
    FileItem();
    FileItem(imageEnum icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(imageEnum icon);

private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
};


#endif //TEXTINPUT_FILEITEM_H
