#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>

class Player;  // Forward declaration to avoid cyclic dependencies

class PlayerState {
public:
    virtual ~PlayerState() = default;

    // Handle input for the current state
    virtual void handleInput(Player& player, sf::Keyboard::Key key, bool isPressed, const sf::FloatRect& screenBounds) = 0;

    // Update the player state
    virtual void update(Player& player) = 0;
};

#endif // PLAYERSTATE_H