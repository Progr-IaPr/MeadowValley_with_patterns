#ifndef HOUSE_H
#define HOUSE_H

class House {
private:
    sf::Vector2f position;
    bool isPlayerHouse;
public:
    House(const sf::Vector2f& pos, bool isPlayerHouse) : position(pos), isPlayerHouse(isPlayerHouse) {}

    sf::Vector2f getPosition() const { return position; }
    bool getIsPlayerHouse() const { return isPlayerHouse; }
};

#endif