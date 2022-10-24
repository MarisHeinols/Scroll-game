#include "GameFunctions.h"

GameFunctions::GameFunctions()
{
}

GameFunctions::~GameFunctions()
{
}

void GameFunctions::runGame(const sf::RenderWindow& window, sf::View& view) {
	static const float VIEW_HEIGHT = 512.0F;
	float cordsX = 800.0f;
	float cordsY = 250.0f;
	std::vector<Platfrom> platforms;
	int score = 0;

	std::ostringstream scoreLabel;
	sf::Text scoreText;

	if (player.getIfCollision()) {
		isRunning = false;
		scoreFile.open("results.txt", ifstream::app);
		scoreFile << score << "\n";
		scoreFile.close();
	}

	if (isRunning == false) {
		view.setCenter(10, 10);
		window.clear();
		window.setView(view);
		window.draw(menuText);
		window.draw(menuScore);
		window.display();
	}
	else {
		player.Update(deltaTime);
		countScore(player.GetPostion().x);
		Collision player_colider = player.GetCollision();

		sf::Vector2f direction;

		for (Platfrom& platform : platforms)
			if (platform.GetCollision().CheckCollision(player_colider, direction, 1.0f))
				player.onCollision(direction);


		view.setCenter(player.GetPostion());

		scoreText.setPosition(player.GetPostion().x - 30, player.GetPostion().y - 200);

		window.clear();
		window.setView(view);
		window.draw(scoreText);
		player.Draw(window);
		for (Platfrom& platform : platforms)
			platform.Draw(window);
		window.display();
	}
};
