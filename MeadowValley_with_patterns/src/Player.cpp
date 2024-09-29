#include "../include/Player.h"
#include "../include/IdleState.h"
#include <iostream>
#include "SFML/Graphics.hpp"

// Initialize the static instance to nullptr
Player* Player::instance = nullptr;

// Private constructor
Player::Player() : currentState(new IdleState()), isMoving(false), direction(0, 0), position(370.f, 900.f) {}

// Method to get the singleton instance
Player& Player::getInstance() {
    if (instance == nullptr) {
        instance = new Player();
    }
    return *instance;
}

void Player::changeState(PlayerState* newState) {
    if (currentState) {
        delete currentState;  // Clean up the old state
    }
    currentState = newState;
}

PlayerState* Player::getCurrentState() const {
    return currentState;
}

// Collision detection function with screen bounds
bool Player::canMoveTo(const sf::Vector2f& newPosition, const sf::FloatRect& screenBounds) {
    const float playerWidth = 64.0f;
    const float playerHeight = 64.0f;

    // Define bounds for the player's movement area
    sf::FloatRect playerBounds(newPosition.x, newPosition.y, playerWidth, playerHeight);

    // Define the lower river boundary as the upper limit for player movement
    float lowerRiverBoundary = screenBounds.height * 0.45f + 50;

    // Prevent player from moving above the river boundary
    if (playerBounds.top < lowerRiverBoundary) {
        return false;
    }

    // Adjust the bottom boundary to raise it a bit
    float adjustedBottomBoundary = screenBounds.height - 10;

    // Prevent player from moving outside the screen bounds
    if (playerBounds.left < screenBounds.left ||
        playerBounds.left + playerBounds.width > screenBounds.width || 
        playerBounds.top + playerBounds.height > adjustedBottomBoundary) { 
        return false;
    }

    return true;
}

// Getter and Setter for position
sf::Vector2f Player::getPosition() const {
    return position;
}

void Player::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
}

// Getter and Setter for direction
sf::Vector2f Player::getDirection() const {
    return direction;
}

void Player::setDirection(const sf::Vector2f& newDirection) {
    direction = newDirection;
}

// Getter and Setter for isMoving
bool Player::getIsMoving() const {
    return isMoving;
}

void Player::setIsMoving(bool moving) {
    isMoving = moving;
}

// Input handling
void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) {
    if (currentState) {
        currentState->handleInput(*this, key, isPressed, screenBounds);  // Delegate to current state
    }
}

// Update function
void Player::update() {
    if (currentState) {
        currentState->update(*this);  // Delegate to current state
    }
}