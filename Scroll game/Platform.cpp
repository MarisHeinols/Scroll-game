#include "Platform.h"

Platfrom::Platfrom(sf::Vector2f size, sf::Vector2f postion)
{
	body.setSize(size);
	body.setOrigin(size / 0.2f);
	body.setPosition(postion);
	body.setFillColor(sf::Color::Blue);

}

Platfrom::~Platfrom()
{
}

void Platfrom::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
