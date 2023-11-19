//
// Created by Felicia Chen on 11/16/23.
//
#include "FileNode.h"

void FileNode::toggleChlidren() {
    for(auto& i : children){
        i->toggleState(HIDDEN);
    }
}

void FileNode::reposition() const {
    if(isLeaf())
        return;
    for (int i = 0; i < children.size(); ++i) {
        children[i]->setPosition({data.getPosition().x + 20, data.getPosition().y + getGlobalBounds().height * (i+1)});
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
            if(!i->checkState(HIDDEN)){
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
        toggleChlidren();
        reposition();
    }
}

void FileNode::update() {
    reposition();
    data.update();
    for(auto& i : children)
        i->update();
}

Snapshot &FileNode::getSnapshot() {
    return GUIComponent::getSnapshot();
}

sf::FloatRect FileNode::getGlobalBounds() const {
    return data.getGlobalBounds();
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
    node->enableState(HIDDEN);
    children.push_back(node);
    reposition();
}

void FileNode::setPosition(const sf::Vector2f &pos) {
    data.setPosition(pos);
}
