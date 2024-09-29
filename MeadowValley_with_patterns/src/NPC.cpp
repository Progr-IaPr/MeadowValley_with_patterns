#include "../include/NPC.h"

NPC::NPC(const std::string& name, const std::vector<std::string>& dialogues, sf::Vector2f position)
    : name(name), dialogues(dialogues), position(position), currentDialogueIndex(0) {}

std::string NPC::getName() const {
    return name;
}

sf::Vector2f NPC::getPosition() const {
    return position;
}