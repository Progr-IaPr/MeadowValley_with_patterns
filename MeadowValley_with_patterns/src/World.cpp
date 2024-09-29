#include "../include/World.h"
#include "../include/ObjectFactory.h"
#include <cmath>

// Singleton access method
World& World::getInstance() {
    static World instance;  // Guaranteed to be created once and destroyed at program exit
    return instance;
}

// Private constructor for Singleton pattern
World::World() {
    initializeNPCs();

    // Position the player's house
    houseList.push_back(ObjectFactory::createHouse(sf::Vector2f(105, 430), true));

    // Position 3 NPC houses
    houseList.push_back(ObjectFactory::createHouse(sf::Vector2f(500, 500), false));
    houseList.push_back(ObjectFactory::createHouse(sf::Vector2f(670, 480), false));
    houseList.push_back(ObjectFactory::createHouse(sf::Vector2f(580, 310), false));

    // Position the market
    houseList.push_back(ObjectFactory::createHouse(sf::Vector2f(400, 330), false));

    // Add 9 fields in a 3x3 grid above the house
    float startX = 175;
    float startY = 375; 

    // Separate spacing for horizontal and vertical gaps
    float spacingX = 30; 
    float spacingY = 40;  

    // 3x3 grid of fields
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            float x = startX + col * spacingX;
            float y = startY + row * spacingY;  

            // First field is unlocked, others are locked
            bool isUnlocked = (row == 0 && col == 0);

            Field field = ObjectFactory::createField(row * 3 + col, 4, sf::Vector2f(x, y));
            if (isUnlocked) {
                field.buyField();
            }
            fieldList.push_back(field);
        }
    }

    // Add a tree next to the player's house
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(105, 350))); 

    // Add trees above the river
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(50, 150)));
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(150, 125)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(105, 170)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(200, 160)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(270, 150)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(330, 160)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(390, 180)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(430, 130)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(480, 170)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(530, 150)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(580, 160)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(640, 175)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(690, 145)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(740, 170))); 
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(5, 180)));    

    // Add 4 trees in the village (below the river)
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(10, 310)));  
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(500, 370))); 
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(350, 510))); 
    treeList.push_back(ObjectFactory::createTree(sf::Vector2f(700, 330))); 
}

const std::vector<House>& World::getHouseList() const {
    return houseList;
}

const std::vector<Tree>& World::getTreeList() const {
    return treeList;
}

const std::vector<Field>& World::getFieldList() const {
    return fieldList;
}

const std::vector<NPC>& World::getNPCList() const {
    return npcList;
}

void World::initializeNPCs() {
    npcList.push_back(ObjectFactory::createNPC("Milo", { "Hello there!" }, sf::Vector2f(1400, 680)));
    npcList.push_back(ObjectFactory::createNPC("Leo", { "What a nice day!" }, sf::Vector2f(1530, 900)));
    npcList.push_back(ObjectFactory::createNPC("Jess", { "Good to see you!" }, sf::Vector2f(1350, 950)));
}

bool World::checkBounds(int posX, int posY) const {
    return (posX >= 0 && posX < worldSizeX && posY >= 0 && posY < worldSizeY);
}