//
// Created by Felicia Chen on 11/16/23.
//
#include "FileNode.h"

void FileNode::toggleChlidren() {
    for(auto& i : children){
        i.second->toggleState(HIDDEN);
    }
}

void FileNode::reposition() const {
    sf::Vector2f pos = children.cbegin()->second->getPosition();
    for(auto& i : children){
        i.second->setPosition({pos.x + 10, pos.y});
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
        for (auto& i : children) {
            if(!i.second->checkState(HIDDEN))
                window.draw(*i.second, states);
        }
    }
}

void FileNode::applySnapshot(const Snapshot &snapshot) {
    GUIComponent::applySnapshot(snapshot);
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto& i : children)
        i.second->addEventHandler(window, event);
    data.addEventHandler(window, event);
}

void FileNode::update() {
    data.update();
    if(checkState(CLICKED))
        toggleChlidren();
}

Snapshot &FileNode::getSnapshot() {
    return GUIComponent::getSnapshot();
}

sf::FloatRect FileNode::getGlobalBounds() {
    return sf::FloatRect();
}

bool FileNode::isLeaf() const {
    if(children.empty())
        return true;
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}
