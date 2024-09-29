#ifndef WALKINGSTATE_H
#define WALKINGSTATE_H

#include "PlayerState.h"

class WalkingState : public PlayerState {
private:
    void movePlayer(Player& player, sf::Keyboard::Key key, const sf::FloatRect& screenBounds);
public:
    void handleInput(Player& player, sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) override;
    void update(Player& player) override;
};

#endif // WALKINGSTATE_H