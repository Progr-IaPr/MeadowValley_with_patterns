#include "../include/ObjectFactory.h"

// Factory method to create NPCs
NPC ObjectFactory::createNPC(const std::string& name, const std::vector<std::string>& dialogue, const sf::Vector2f& position) {
    return NPC(name, dialogue, position);
}

// Factory method to create Fields
Field ObjectFactory::createField(int id, int slots, const sf::Vector2f& position) {
    return Field(id, slots, position);
}

Tree ObjectFactory::createTree(const sf::Vector2f& position) {
    return Tree(position);
}

House ObjectFactory::createHouse(const sf::Vector2f& position, bool isPlayerHouse) {
    return House(position, isPlayerHouse);
}