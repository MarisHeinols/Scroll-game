#include "Platform.h"

Platfrom::Platfrom(sf::Texture* texture, sf::Vector2f size, sf::Vector2f postion)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(postion);
	body.setTexture(texture);

}

Platfrom::~Platfrom()
{
}

void Platfrom::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Platfrom::setTexture(sf::Texture* texture) {
	body.setTexture(texture);
}
