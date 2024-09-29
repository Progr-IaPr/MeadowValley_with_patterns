#include "../include/IdleState.h"
#include "../include/WalkingState.h"
#include "../include/Player.h"

void IdleState::handleInput(Player& player, sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) {
    if (isPressed) {
        switch (key) {
        case sf::Keyboard::W:
        case sf::Keyboard::A:
        case sf::Keyboard::S:
        case sf::Keyboard::D:
            player.changeState(new WalkingState());  // change state
            player.getCurrentState()->handleInput(player, key, isPressed, screenBounds);
            break;
        default:
            break;
        }
    }
}

void IdleState::update(Player& player) {
    // Idle specific update logic
    player.setIsMoving(false);
}