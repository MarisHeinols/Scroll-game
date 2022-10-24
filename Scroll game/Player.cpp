#include "Player.h"

Player::Player(sf::Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(200.0f, 200.0f);
	body.setTexture(texture);
	this->x_collision = false;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	if(x_collision == false){
		velocity.x = 250.0f * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		velocity.x = 0.0f;
		x_collision = true;
	}

	if (direction.y < 0.0f) {
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f;
	}
}
void Player::getIfInVoid()
{
	if (body.getPosition().y > 500.0f) {
		velocity.x = 0.0f;
		x_collision = true;
	}
}
bool Player::ifWon() {
	if (body.getPosition().x > 250100.0f) {
		return true;
	}
}

