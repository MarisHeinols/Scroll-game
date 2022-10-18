#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Coin.h"
#include <sstream>
#include "Source.h"
#include <vector>

static const float VIEW_HEIGHT = 512.0F;

void ReisizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(512,512),"Scroll game", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::Texture groundTexture;
	groundTexture.loadFromFile("ground.png");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player.png");

	Player player(&playerTexture,0.7f,100.0f);

	std::vector<Platfrom> platforms;
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 150.0f), sf::Vector2f(700.0f, 280.0f)));
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 190.0f), sf::Vector2f(900.0f, 220.0f)));
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1100.0f, 190.0f)));
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1300.0f, 190.0f)));
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 1000.0f), sf::Vector2f(1300.0f, -570.0f)));
	platforms.push_back(Platfrom(nullptr, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1100.0f, 190.0f)));
	platforms.push_back(Platfrom(&groundTexture, sf::Vector2f(100000000.0f, 100.0f), sf::Vector2f(300.0f, 350.0f)));
	float deltaTime = 0.1f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) {
			deltaTime = 1.0f / 20.0f;
		}


		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::Resized:
				ReisizeView(window, view);
			default:
				break;
			}
		}


		player.Update(deltaTime);
		Collision player_colider = player.GetCollision();

		sf::Vector2f direction;

		for (Platfrom& platform : platforms)
			if (platform.GetCollision().CheckCollision(player_colider, direction, 1.0f))
				player.onCollision(direction);


		view.setCenter(player.GetPostion());

		window.clear();
		window.setView(view);
		player.Draw(window);
		for (Platfrom& platform : platforms)
			platform.Draw(window);
		window.display();
	}
	return 0;
}