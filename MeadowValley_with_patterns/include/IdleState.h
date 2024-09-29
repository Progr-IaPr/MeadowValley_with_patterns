#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "PlayerState.h"

class IdleState : public PlayerState {
public:
    void handleInput(Player& player, sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) override;
    void update(Player& player) override;
};

#endif // IDLESTATE_H