#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Coin.h"
#include "Collision.h"

class Player {
public:
    Player(float speed);
    ~Player();

    void Update(float deltaTime);

    void Draw(sf::RenderWindow& window);

    sf::Vector2f GetPostion() { return body.getPosition(); }
    Collision GetCollision() { return Collision(body); }

private:
    sf::RectangleShape body;
    float speed;

};