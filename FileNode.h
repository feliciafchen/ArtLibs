//
// Created by Felicia Chen on 11/16/23.
//

#ifndef TEXTINPUT_FILENODE_H
#define TEXTINPUT_FILENODE_H
#include "FileItem.h"
#include "GUIComponent.h"
#include "Images.h"

class FileNode : public GUIComponent
{
private:
    //This is the data represented in the tree
    FileItem data;
    //this is all the child nodes in the tree, a vector would also work just fine
    std::vector<FileNode*> children;
    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChildren();
    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;
public:
    // this is so I can use the iterator for the children map publicly
    typedef typename std::map<std::string, FileNode*>::iterator iterator;
    FileNode();
    FileNode(imageEnum icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    //This is not currently used
    virtual void applySnapshot(const Snapshot& snapshot) override;
    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    //does nothing now
    void update() override;
    //does nothing now
    virtual Snapshot& getSnapshot() override;
    //does nothing now
    sf::FloatRect getGlobalBounds() const;
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();
    void addChild(FileNode* node);
    FileItem* getDoubleClicked();
    void setPosition(const sf::Vector2f &pos);
    //iterators
    iterator begin();
    iterator end();
};


#endif //TEXTINPUT_FILENODE_H
