#include "Player.h"

Player::Player(float speed)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setFillColor(sf::Color::Red);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(200.0f, 200.0f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movment(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		movment.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movment.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movment.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		movment.y += speed * deltaTime;
	}
	body.move(movment);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
