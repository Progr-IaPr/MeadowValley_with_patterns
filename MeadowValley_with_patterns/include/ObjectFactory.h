#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "NPC.h"
#include "Field.h"
#include "Tree.h"
#include "House.h"

class ObjectFactory {
public:
    static NPC createNPC(const std::string& name, const std::vector<std::string>& dialogue, const sf::Vector2f& position);
    static Field createField(int id, int slots, const sf::Vector2f& position);
    static Tree createTree(const sf::Vector2f& position);
    static House createHouse(const sf::Vector2f& position, bool isPlayerHouse);
};

#endif // OBJECTFACTORY_H