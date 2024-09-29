#ifndef WORLDUI_H
#define WORLDUI_H

#include <SFML/Graphics.hpp>
#include "../../include/World.h"
#include "../../include/Player.h"

class WorldUI {
private:
    sf::Texture skyTexture;
    sf::Texture cloudTexture;
    sf::Texture treeTextureAboveRiver;
    sf::Texture treeTextureVillage;
    sf::Texture playerHouseTexture;
    sf::Texture npcHouseTexture;
    sf::Texture shopTexture;
    sf::Texture charPoseTexture;
    sf::Clock waveClock;

    // Textures for player movement and idle states
    sf::Texture playerTextureIdle;
    sf::Texture playerTextureMoveUp;
    sf::Texture playerTextureMoveDown;
    sf::Texture playerTextureMoveLeft;
    sf::Texture playerTextureMoveRight;
public:
    WorldUI();
    void render(sf::RenderWindow& window, const World& world);
};

#endif // WORLDUI_H