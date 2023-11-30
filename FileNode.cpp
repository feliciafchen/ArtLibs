//
// Created by Felicia Chen on 11/16/23.
//
#include "FileNode.h"

void FileNode::toggleChildren() {
    toggleState(CHILDREN_SHOWING);
}

void FileNode::reposition() const {
    if(isLeaf())
        return;
    sf::Vector2f dataPos = data.getPosition();
    children[0]->setPosition({dataPos.x + 20, dataPos.y + data.getGlobalBounds().height});
    for (int i = 1; i < children.size(); ++i) {
        children[i]->setPosition({data.getPosition().x + 20, children[i-1]->getGlobalBounds().height * (i+1)});
    }
}

FileNode::FileNode() {

}

FileNode::FileNode(imageEnum icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    data = FileItem(icon, text, size, position);
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!checkState(HIDDEN)){
        window.draw(data);
        if(checkState(CHILDREN_SHOWING))
        {
            for (auto& i : children) {
                window.draw(*i, states);
            }
        }
    }
}

void FileNode::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto& i : children)
        i->addEventHandler(window, event);
    data.addEventHandler(window, event);
    if(MouseEvents<FileItem>::mouseClicked(data, window)){
        toggleChildren();
        reposition();
    }
}

void FileNode::update() {
    for(auto& i : children)
        i->update();
    reposition();
    data.update();
}

Snapshot &FileNode::getSnapshot() {
    return GUIComponent::getSnapshot();
}

sf::FloatRect FileNode::getGlobalBounds() const {
    sf::FloatRect globalBounds = data.getGlobalBounds();
    if(!checkState(CHILDREN_SHOWING))
        return globalBounds;
    for(auto& i: children){
        globalBounds.height += i->getGlobalBounds().height;
    }
    return globalBounds;
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode *> &FileNode::getChildren() {
    return children;
}

void FileNode::addChild(FileNode *node) {
    children.push_back(node);
    reposition();
}

void FileNode::setPosition(const sf::Vector2f &pos) {
    data.setPosition(pos);
}
