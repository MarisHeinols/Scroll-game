#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Coin.h"
#include "Collision.h"

class Player {
public:
    Player(sf::Texture* texture, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    void onCollision(sf::Vector2f direction);

    sf::Vector2f GetPostion() { return body.getPosition(); }
    Collision GetCollision() { return Collision(body); }

private:
    sf::RectangleShape body;
    float speed;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
    bool x_collision;


};