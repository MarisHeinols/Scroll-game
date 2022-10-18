#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Coin.h"
#include <sstream>
#include "Platform.h"
#include "Source.h"

static const float VIEW_HEIGHT = 512.0F;

void ReisizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(512,512),"Scroll game", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	Player player(0.7f);

	Platfrom platfrom1(sf::Vector2f(400.0f, 200.0f), sf::Vector2f(250.0f, 250.0f));
	Platfrom platfrom2(sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

	float deltaTime = 0.1f;

	while (window.isOpen())
	{
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

		platfrom1.GetCollision().CheckCollision(player.GetCollision(), 0.0f);
		platfrom2.GetCollision().CheckCollision(player.GetCollision(), 1.0f);

		view.setCenter(player.GetPostion());

		window.clear();
		window.setView(view);
		player.Draw(window);
		platfrom1.Draw(window);
		platfrom2.Draw(window);
		window.display();
	}
	return 0;
}