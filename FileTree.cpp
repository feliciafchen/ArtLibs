//
// Created by Felicia Chen on 11/16/23.
//

#include "FileTree.h"

FileNode *FileTree::find(FileNode *parent, const std::string &data) {
    if(parent){
        if(parent->getData().getText() == data)
            return parent;
        for(auto& i : parent->getChildren())
            find(i, data);
    }
    return nullptr;
}

FileNode *FileTree::createNode(const std::string &data) {
    auto*t = new FileNode(FILE_ICON, data, {250,50}, {0,0});
    return t;
}

std::vector<std::string> FileTree::getDirectories(const std::string &path) {
    std::vector<std::string> directories;
    std::string s = path;
    size_t pos = s.find('/');
    std::string token;
    while (pos != std::string::npos) {
        token = s.substr(0, pos);
        directories.push_back(token);
        s.erase(0, pos+1);
        pos = s.find('/');
    }
    directories.push_back(s);
    return directories;
}

void FileTree::push(FileNode *parent, FileNode *child) {
    parent->addChild(child);
}

void FileTree::push(const std::string &path) {
    auto directories = getDirectories(path);

    if(directories.empty())
        return;

    std::string token = directories[0];
    if(!root){
        if (token.empty()) {
            root = createNode("/");
        } else {
            root = createNode(token);
        }
    }

    if(directories.size() == 1)
        return;

    FileNode* current = root;

    for (int i = 1; i < directories.size(); ++i) {
        token = directories[i];
        FileNode* child = nullptr;

        for (FileNode* childNode : current->getChildren()) {
            child = find(childNode, token);
            if(child)
                break;
        }

        if (!child) {
            child = createNode(token);
            push(current, child);
        }
        current = child;
    }
}

FileTree::FileTree() {
    enableState(FIRST);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
}

void FileTree::update() {
    root->update();
    root->getDoubleClicked(selectedText);
}

Snapshot &FileTree::getSnapshot() {
    return GUIComponent::getSnapshot();
}

sf::FloatRect FileTree::getGlobalBounds() {
    return sf::FloatRect();
}
