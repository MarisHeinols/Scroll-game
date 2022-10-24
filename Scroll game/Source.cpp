#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include <sstream>
#include "Source.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "LevelGenerator.h"
using namespace std;

static const float VIEW_HEIGHT = 512.0F;

std::vector<Platfrom> platforms;

LevelGenerator gameLevel;

//Definition of dynamic texts
std::ostringstream highScoreLabel;
int highScore = 0;
sf::Text menuScore;

std::ostringstream scoreLabel;
int score = 0;
sf::Text scoreText;

//Conditonals for screen change
bool isRunning = false;
bool deathScreen = false;
bool scoreAdded = false;

void ReisizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void countScore(float xCords) {
	if ((int)xCords % 10 == 0) {
		score ++;
		scoreLabel.str("");
		scoreLabel << "Score " << score;
		scoreText.setString(scoreLabel.str());
	}
}
void updateHighScore() {
	string line;
	ifstream inputScoreFile("results.txt");
	if (inputScoreFile.is_open())
	{
		while (getline(inputScoreFile, line))
		{
			if (std::stoi(line) > highScore) {
				highScore = std::stoi(line);
			}

		}
		inputScoreFile.close();
	}
	else cout << "Unable to open file";

	highScoreLabel.str("");
	highScoreLabel << "High score " << highScore;
	menuScore.setString(highScoreLabel.str());
}
void resetScore() {
	highScore = 0;
	highScoreLabel.str("");
	highScoreLabel << "High score " << highScore;
	menuScore.setString(highScoreLabel.str());
}
void gameReset() {
	isRunning = false;
	deathScreen = false;
	scoreAdded = false;
	score = 0;
	platforms.clear();
	gameLevel.resetCords();
	platforms = gameLevel.generatePlatforms();

}
int main() {

    sf::RenderWindow window(sf::VideoMode(1000,800),"Scroll game", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//Game textures and fonts
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player.png");
	Player player(&playerTexture, 1.0f, 100.0f);

	sf::Font gameFont;
	gameFont.loadFromFile("Caver Pitalsal.ttf");


	sf::Texture platformTexture;
	platformTexture.loadFromFile("platform.png");

	//Files

	ofstream scoreFile;

	// Game texts and labels
	scoreLabel << "Score: " << score;

	scoreText.setCharacterSize(35);
	scoreText.setFillColor(sf::Color::Cyan);
	scoreText.setFont(gameFont);
	scoreText.setPosition({ 10, 10 });
	scoreText.setString(scoreLabel.str());

	sf::Text menuText;
	menuText.setCharacterSize(60);
	menuText.setFillColor(sf::Color::Cyan);
	menuText.setFont(gameFont);
	menuText.setPosition({ -100, -50});
	menuText.setString("BLOCK DASH ");

	sf::Text startText;
	startText.setCharacterSize(30);
	startText.setFillColor(sf::Color::White);
	startText.setFont(gameFont);
	startText.setPosition({ -90, 20 });
	startText.setString("Press ENTER to start");

	sf::Text resetText;
	resetText.setCharacterSize(15);
	resetText.setFillColor(sf::Color::White);
	resetText.setFont(gameFont);
	resetText.setPosition({ -50, 150 });
	resetText.setString("Press R to clear score");

	menuScore.setCharacterSize(30);
	menuScore.setFillColor(sf::Color::Red);
	menuScore.setFont(gameFont);
	menuScore.setPosition({ -70, -150 });

	sf::Text deathText;
	deathText.setCharacterSize(60);
	deathText.setFillColor(sf::Color::Red);
	deathText.setFont(gameFont);
	deathText.setPosition({ -100, -50 });
	deathText.setString("YOU DIED!!");

	sf::Text yourScore;
	yourScore.setCharacterSize(30);
	yourScore.setFillColor(sf::Color::Cyan);
	yourScore.setFont(gameFont);
	yourScore.setPosition({ -80, 20 });

	sf::Text getBack;
	getBack.setCharacterSize(15);
	getBack.setFillColor(sf::Color::White);
	getBack.setFont(gameFont);
	getBack.setPosition({ -60, 60 });
	getBack.setString("Press Q to get to menu");

	srand(time(NULL));

	//Generating level
	platforms = gameLevel.generatePlatforms();
	//Get finish cord
	float endCord = platforms.back().GetPostion().x + 200.0f;

	//Get highest score
	updateHighScore();

	//Seeting up game clock
	float deltaTime = 0.1f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) {
			deltaTime = 1.0f / 20.0f;
		}
		//Window modes and resizing
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
		//Checking if there is collision
		if (player.getIfCollision() && isRunning == true) {
			deathScreen = true;
			isRunning = false;
			if(scoreAdded == false){
				scoreFile.open("results.txt", ifstream::app);
				scoreFile << score << "\n";
				scoreFile.close();
				scoreAdded = true;
			}


		}
		//Checking if player has reached the end
		if (player.ifWon(endCord) == true) {
			deathScreen = true;
			isRunning = false;
			scoreFile.open("results.txt", ifstream::app);
			scoreFile << score << "\n";
			scoreFile.close();
			deathText.setString("YOU WON!!");
		}
		//Main menu
		if (isRunning == false && deathScreen == false) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				scoreFile.open("results.txt", std::ofstream::out | std::ofstream::trunc);
				scoreFile.close();
				resetScore();
				window.clear();
				window.draw(menuScore);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { scoreAdded = false; isRunning = true; deathScreen = false; window.clear(); }
			view.setCenter(0,0);
			window.clear();
			window.setView(view);
			window.draw(menuText);
			window.draw(menuScore);
			window.draw(startText);
			window.draw(resetText);
			window.display();
		}
		//Death or won screen
		if (isRunning == false && deathScreen == true) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				gameReset(); player.resetPlayer();player.resetCollision();window.clear(); window.display();
			}
			yourScore.setString("Your score: " + std::to_string(score));
			view.setCenter(10, 10);
			window.clear();
			window.setView(view);
			window.draw(deathText);
			window.draw(yourScore);
			window.draw(getBack);
			window.display();
		}
		//Game functionality
		if(isRunning == true && deathScreen == false) {
			player.Update(deltaTime);
			countScore(player.GetPostion().x);
			Collision player_colider = player.GetCollision();

			sf::Vector2f direction;

			player.getIfInVoid();

			for (Platfrom& platform : platforms) {
				platform.setTexture(&platformTexture);
				if (platform.GetCollision().CheckCollision(player_colider, direction, 1.0f))
					player.onCollision(direction);
			}

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
	}
	return 0;
}