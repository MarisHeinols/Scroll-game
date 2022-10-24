#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Collision.h"
class Platfrom {
public:
	Platfrom(sf::Texture*, sf::Vector2f size, sf::Vector2f postion);
	~Platfrom();

	void Draw(sf::RenderWindow& window);

	void setTexture(sf::Texture* texture);

	Collision GetCollision() {
		return Collision(body);
	}
	sf::Vector2f GetPostion() { return body.getPosition(); }
private:
	sf::RectangleShape body;

};