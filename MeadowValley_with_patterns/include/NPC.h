#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp> // For position

class NPC {
private:
    std::string name;
    std::vector<std::string> dialogues;
    sf::Vector2f position;
    int currentDialogueIndex;
public:
    NPC(const std::string& name, const std::vector<std::string>& dialogues, sf::Vector2f position);

    std::string getName() const;
    sf::Vector2f getPosition() const;
};

#endif // NPC_H