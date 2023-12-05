//
// Created by Felicia Chen on 11/16/23.
//

#ifndef TEXTINPUT_FILETREE_H
#define TEXTINPUT_FILETREE_H
#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    FileNode* root = nullptr;
    FileNode* doubleClicked;
    FileNode* find(FileNode* parent, const std::string& data);
    FileNode* createNode(const std::string& data);
    std::vector<std::string> getDirectories(const std::string& path);
    void push(FileNode* parent, FileNode* child);
    sf::Vector2f initPosition = {0, 0};
public:
    //constructors
    FileTree();
    //this is the public version of push
    void push(const std::string& path);
    //draws the root node of the tree
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    //does nothing now
    void applySnapshot(const Snapshot& snapshot) override;
    //calls the traverse function to add the event handlers to each node
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    //does nothing now
    void update() override;
    //does nothing now
    Snapshot& getSnapshot() override;
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();
};


#endif //TEXTINPUT_FILETREE_H
