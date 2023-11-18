//
// Created by Felicia Chen on 11/16/23.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item) {
    if(!root){
        root = new FileNode(FOLDER_ICON, parent, {200, 50}, {50,50});
        return;
    }
    else{
        if(root->getData().getText() == parent){
            root->getData().setIcon(FOLDER_ICON);
            FileNode node(FILE_ICON, item, {200, 50}, {50,50});
            root->getChildren().push_back(&node);
            return;
        }
        else{
            for(auto& i : root->getChildren()){
                if(i->getData().getText() == parent){
                    push(i, parent, item);
                    return;
                }
            }
        }
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    root->getData().addEventHandler(window, event);
    for(auto& i : root->getChildren()){
        traverse(i, window, event);
    }
}
void FileTree::traverseUpdate(FileNode *&root) {
    root->getData().update();
    for(auto& i : root->getChildren()){
        i->update();
    }
}

FileTree::FileTree() {

}

void FileTree::push(std::string parent, std::string item) {
    push(this->root, parent, item);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);
}

void FileTree::update() {
    traverseUpdate(this->root);
}

Snapshot &FileTree::getSnapshot() {
    return GUIComponent::getSnapshot();
}

sf::FloatRect FileTree::getGlobalBounds() {
    return sf::FloatRect();
}
