#pragma once
#include <SFML\Graphics.hpp>
#include "Collision.h"
class Platfrom {
public:
	Platfrom(sf::Vector2f size, sf::Vector2f postion);
	~Platfrom();

	void Draw(sf::RenderWindow& window);
	Collision GetCollision() {
		return Collision(body);
	}
private:
	sf::RectangleShape body;

};