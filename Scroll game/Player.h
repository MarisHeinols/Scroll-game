#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Collision.h"

class Player {
public:
    Player(sf::Texture* texture, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    void onCollision(sf::Vector2f direction);

    void getIfInVoid();

    bool ifWon();

    sf::Vector2f GetPostion() { return body.getPosition(); }
    Collision GetCollision() { return Collision(body); }
    bool getIfCollision() { return x_collision; }
    void resetCollision() {
        x_collision = false;
    }
    void resetPlayer() {
        body.setPosition(200.0f, 200.0f);
    }

private:
    sf::RectangleShape body;
    float speed;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    bool x_collision;
};