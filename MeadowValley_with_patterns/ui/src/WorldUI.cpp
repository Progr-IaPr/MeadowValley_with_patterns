#include "WorldUI.h"
#include <iostream>
#include <cmath> // For wave simulation

WorldUI::WorldUI() {
    // Load sky texture
    if (!skyTexture.loadFromFile("assets/Sky/DaySky.png")) {
        std::cout << "Failed to load sky texture!" << std::endl;
    }

    // Load cloud texture
    if (!cloudTexture.loadFromFile("assets/Clouds/GreyClouds.png")) {
        std::cout << "Failed to load cloud texture!" << std::endl;
    }

    // Load tree textures (one for above the river, one for the village)
    if (!treeTextureAboveRiver.loadFromFile("assets/Trees/TreeAboveRiver.png")) {
        std::cout << "Failed to load tree texture for trees above river!" << std::endl;
    }
    if (!treeTextureVillage.loadFromFile("assets/Trees/TreeVillage.png")) {
        std::cout << "Failed to load tree texture for village trees!" << std::endl;
    }

    // Load NPC texture (Sprite-Sheet)
    if (!charPoseTexture.loadFromFile("assets/Chars/Pose1.png")) {
        std::cout << "Failed to load NPC texture!" << std::endl;
    }

    // Load house textures (Player's house, NPC houses, and the shop)
    if (!playerHouseTexture.loadFromFile("assets/Houses/PlayerHouse.png")) {
        std::cout << "Failed to load player house texture!" << std::endl;
    }
    if (!npcHouseTexture.loadFromFile("assets/Houses/NPCHouse.png")) {
        std::cout << "Failed to load NPC house texture!" << std::endl;
    }
    if (!shopTexture.loadFromFile("assets/Houses/Shop.png")) {
        std::cout << "Failed to load shop texture!" << std::endl;
    }

    // Load textures for the player
    if (!playerTextureIdle.loadFromFile("assets/Chars/Pose1.png")) {
        std::cout << "Failed to load player idle texture!" << std::endl;
    }
    if (!playerTextureMoveUp.loadFromFile("assets/Chars/MovingUp.png")) {
        std::cout << "Failed to load player move up texture!" << std::endl;
    }
    if (!playerTextureMoveDown.loadFromFile("assets/Chars/MovingDown.png")) {
        std::cout << "Failed to load player move down texture!" << std::endl;
    }
    if (!playerTextureMoveLeft.loadFromFile("assets/Chars/MovingLeft.png")) {
        std::cout << "Failed to load player move left texture!" << std::endl;
    }
    if (!playerTextureMoveRight.loadFromFile("assets/Chars/MovingRight.png")) {
        std::cout << "Failed to load player move right texture!" << std::endl;
    }
}

void WorldUI::render(sf::RenderWindow& window, const World& world) {
    // Get window size dynamically
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = windowSize.x;
    float windowHeight = windowSize.y;

    float lowerRiverBoundary = windowHeight * 0.45 + 50;

    // Render grass background
    sf::RectangleShape grassBackground(sf::Vector2f(windowWidth, windowHeight));
    grassBackground.setFillColor(sf::Color(34, 139, 34));  // Green color for grass
    window.draw(grassBackground);

    // Render sky texture with scaling
    sf::Sprite skySprite;
    skySprite.setTexture(skyTexture);

    // Get the original size of the texture
    sf::Vector2u textureSize = skyTexture.getSize();

    // Calculate scaling factors
    float scaleX = windowWidth / static_cast<float>(textureSize.x);
    float scaleY = (windowHeight * 0.25) / static_cast<float>(textureSize.y);  // Only cover 25% of the height

    // Set scale to the sprite
    skySprite.setScale(scaleX, scaleY);
    skySprite.setPosition(0, 0);
    window.draw(skySprite);

    // Render cloud texture with scaling
    sf::Sprite cloudSprite;
    cloudSprite.setTexture(cloudTexture);
    sf::Vector2u cloudTextureSize = cloudTexture.getSize();

    // Calculate scale factors for the cloud
    float cloudScaleX = (windowWidth / 3) / static_cast<float>(cloudTextureSize.x);  // clouds take 1/3 of width
    float cloudScaleY = (windowHeight * 0.15) / static_cast<float>(cloudTextureSize.y);  // clouds take 15% of height

    // Set scale to cloud sprite
    cloudSprite.setScale(cloudScaleX, cloudScaleY);

    // Render multiple clouds
    cloudSprite.setPosition(0, 50);  // Cloud 1 position
    window.draw(cloudSprite);

    cloudSprite.setPosition(640, 50);  // Cloud 2 position
    window.draw(cloudSprite);

    cloudSprite.setPosition(1280, 50);  // Cloud 3 position
    window.draw(cloudSprite);

    // Render river with gradient and waves
    sf::VertexArray riverGradient(sf::Quads, 4);
    riverGradient[0].position = sf::Vector2f(0, windowHeight * 0.45);
    riverGradient[1].position = sf::Vector2f(windowWidth, windowHeight * 0.45);
    riverGradient[2].position = sf::Vector2f(windowWidth, windowHeight * 0.45 + 50);
    riverGradient[3].position = sf::Vector2f(0, windowHeight * 0.45 + 50);

    // Create a gradient color (lighter blue at the top, darker at the bottom)
    riverGradient[0].color = sf::Color(70, 130, 180);
    riverGradient[1].color = sf::Color(0, 0, 139);
    riverGradient[2].color = sf::Color(0, 0, 139);
    riverGradient[3].color = sf::Color(0, 0, 100);

    window.draw(riverGradient);

    // Simulate water wave movement
    float waveAmplitude = 5.0f;  // Amplitude of the waves
    float waveFrequency = 10.0f;  // Frequency of the waves
    float time = waveClock.getElapsedTime().asSeconds();  // Get elapsed time for wave animation

    for (unsigned int i = 0; i < riverGradient.getVertexCount(); ++i) {
        if (i < 2) {  // Only apply to the top two vertices for wave movement
            riverGradient[i].position.y += waveAmplitude * std::sin(waveFrequency * (riverGradient[i].position.x / windowWidth) + time);
        }
    }
    window.draw(riverGradient);  // Draw the river with wave movement

    // Render fence (only 3 sides)
    sf::RectangleShape leftFence(sf::Vector2f(5.0f, 300.0f));  // Left side fence
    leftFence.setFillColor(sf::Color(139, 69, 19));
    leftFence.setPosition(230.0f, 650.0f);
    window.draw(leftFence);

    sf::RectangleShape rightFence(sf::Vector2f(5.0f, 300.0f));  // Right side fence
    rightFence.setFillColor(sf::Color(139, 69, 19));
    rightFence.setPosition(650.0f, 650.0f);
    window.draw(rightFence);

    sf::RectangleShape topFence(sf::Vector2f(420.0f, 5.0f));  // Top side fence
    topFence.setFillColor(sf::Color(139, 69, 19));
    topFence.setPosition(230.0f, 650.0f);
    window.draw(topFence);

    // Render fields (inside the fence)
    for (const auto& field : world.getFieldList()) {
        sf::RectangleShape fieldShape(sf::Vector2f(70.0f, 70.0f));
        if (field.isUnlocked()) {
            fieldShape.setFillColor(sf::Color(139, 69, 19)); // Brown for unlocked fields
        }
        else {
            fieldShape.setFillColor(sf::Color(105, 105, 105)); // Grey for locked fields
        }
        fieldShape.setPosition(field.getPosition().x * (windowWidth / 800), field.getPosition().y * (windowHeight / 600));
        window.draw(fieldShape);
    }

    // Render trees above the river and in the village
    sf::Sprite treeSprite;

    for (const auto& tree : world.getTreeList()) {
        if (tree.getPosition().y < windowHeight * 0.25) {
            treeSprite.setTexture(treeTextureAboveRiver);
        }
        else {
            treeSprite.setTexture(treeTextureVillage);
        }

        // Set the position for each tree
        treeSprite.setPosition(tree.getPosition().x * (windowWidth / 800), tree.getPosition().y * (windowHeight / 600));
        treeSprite.setScale(1.5f, 1.5f);  

        window.draw(treeSprite);
    }

    // Render houses using the appropriate texture for each type
    sf::Sprite houseSprite;
    for (const auto& house : world.getHouseList()) {
        if (house.getIsPlayerHouse()) {
            houseSprite.setTexture(playerHouseTexture);  // Player's house texture
        }
        else if (house.getPosition() == sf::Vector2f(400, 330)) {
            houseSprite.setTexture(shopTexture);  // Shop texture
        }
        else {
            houseSprite.setTexture(npcHouseTexture);  // NPC house texture
        }

        // Scale and position the house sprite
        houseSprite.setPosition(house.getPosition().x * (windowWidth / 800), house.getPosition().y * (windowHeight / 600));
        houseSprite.setScale(2.5f, 2.5f);
        window.draw(houseSprite);
    }

    // Render NPCs
    sf::Sprite npcSprite;
    npcSprite.setTexture(charPoseTexture);

    // Set initial frame for NPC
    int frameWidth = 64; 
    int frameHeight = 64;
    int npcTotalFrames = 5;  // Number of animation frames per NPC

    // Set a basic animation for each NPC
    float frameTime = waveClock.getElapsedTime().asSeconds();
    int currentFrame = static_cast<int>(frameTime * 10) % npcTotalFrames;  // Cycle through frames

    // Render each NPC
    for (const auto& npc : world.getNPCList()) {
        npcSprite.setPosition(npc.getPosition());
        npcSprite.setScale(1.5f, 1.5f);
        npcSprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));  // Animate

        window.draw(npcSprite);
    }

    // Get the Player instance via Singleton
    Player& player = Player::getInstance();

    // Render player based on movement state
    sf::Sprite playerSprite;

    // Frame information
    const int idleFrames = 5;
    const int moveFrames = 6;

    int playerTotalFrames = 0;

    if (player.getIsMoving()) {
        sf::Vector2f direction = player.getDirection();
        if (direction == sf::Vector2f(0, -1)) {
            playerSprite.setTexture(playerTextureMoveUp);
        }
        else if (direction == sf::Vector2f(0, 1)) {
            playerSprite.setTexture(playerTextureMoveDown);
        }
        else if (direction == sf::Vector2f(-1, 0)) {
            playerSprite.setTexture(playerTextureMoveLeft);
        }
        else if (direction == sf::Vector2f(1, 0)) {
            playerSprite.setTexture(playerTextureMoveRight);
        }
        playerTotalFrames = moveFrames;
    }
    else {
        playerSprite.setTexture(playerTextureIdle);
        playerTotalFrames = idleFrames;
    }

    // Animate player by cycling through frames
    float playerFrameTime = waveClock.getElapsedTime().asSeconds();
    int playerCurrentFrame = static_cast<int>(playerFrameTime * 8) % playerTotalFrames;

    // Set texture rectangle to current frame
    playerSprite.setTextureRect(sf::IntRect(playerCurrentFrame* frameWidth, 0, frameWidth, frameHeight));

    // Set the player's position
    playerSprite.setPosition(player.getPosition());
    playerSprite.setScale(1.5f, 1.5f);

    // Render the player
    window.draw(playerSprite);    
}