#include "../include/WalkingState.h"
#include "../include/IdleState.h"
#include "../include/Player.h"

void WalkingState::handleInput(Player& player, sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) {
    if (isPressed) {
        movePlayer(player, key, screenBounds);
    }
    else {
        // if no key is pressed, back to IdleState
        player.changeState(new IdleState());
    }
}

void WalkingState::update(Player& player) {
    // Walking specific update logic
    player.setIsMoving(true);
}

void WalkingState::movePlayer(Player& player, sf::Keyboard::Key key, const sf::FloatRect& screenBounds) {
    const float stepSize = 2.0f;
    sf::Vector2f newPosition = player.getPosition();
    sf::Vector2f direction;

    switch (key) {
    case sf::Keyboard::W:
        newPosition.y -= stepSize;
        direction = sf::Vector2f(0, -1);
        break;
    case sf::Keyboard::S:
        newPosition.y += stepSize;
        direction = sf::Vector2f(0, 1);
        break;
    case sf::Keyboard::A:
        newPosition.x -= stepSize;
        direction = sf::Vector2f(-1, 0);
        break;
    case sf::Keyboard::D:
        newPosition.x += stepSize;
        direction = sf::Vector2f(1, 0);
        break;
    default:
        break;
    }

    if (player.canMoveTo(newPosition, screenBounds)) {
        player.setPosition(newPosition);
        player.setDirection(direction);
    }
}