#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "PlayerState.h"

class Player {
private:
    static Player* instance;
    PlayerState* currentState;
    sf::Vector2f position;
    bool isMoving;
    sf::Vector2f direction;

    // Private constructor for Singleton
    Player();

public:
    // Delete copy constructor and assignment operator to prevent copies
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    // Static method to get the singleton instance
    static Player& getInstance();

    void changeState(PlayerState* newState);
    PlayerState* getCurrentState() const;
    bool canMoveTo(const sf::Vector2f& newPosition, const sf::FloatRect& screenBounds);

    // Getter and Setter for position
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& newPosition);

    // Getter and Setter for direction
    sf::Vector2f getDirection() const;
    void setDirection(const sf::Vector2f& newDirection);

    // Getter and Setter for isMoving
    bool getIsMoving() const;
    void setIsMoving(bool moving);

    // Input handling
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds);

    // Update function
    void update();
};

#endif // PLAYER_H