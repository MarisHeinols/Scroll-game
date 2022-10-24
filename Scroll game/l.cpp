
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

std::vector<Platfrom> generatePlatforms() {
	//Texture loading
	sf::Texture platformTexture;
	platformTexture.loadFromFile("platform.png");
	sf::Texture groundTexture;
	groundTexture.loadFromFile("ground.png");

	//Start platform
	platforms.push_back(Platfrom(&groundTexture, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(300.0f, 350.0f)));
	//End platform
	platforms.push_back(Platfrom(&groundTexture, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(250000.0f, 350.0f)));

	//Randomly generated level
	for (size_t i = 0; i < 100; i++)
	{
		int caseOfObsticle = (1 + rand() % 6);

		if (cordsX == 800.0f) {
			platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			cordsX += 250.0f;
		}
		else {
			if (caseOfObsticle == 1) {
				printf("case 1");
				cordsY = 200.0f;
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			}
			else if (caseOfObsticle == 2) {
				printf("case 2");

				cordsY += 40.0f;
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			}
			else if (caseOfObsticle == 3) {
				printf("case 3");

				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			}
			else if (caseOfObsticle == 4) {
				printf("case 4");

				if (cordsY != 200.0f) {
					cordsY -= 40.0f;
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				}
				else {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY + 40)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY + 0)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY + -40)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY + -80)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1250.0f, cordsY + -120)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1500.0f, cordsY + -160)));
					cordsY += -160.0f;
					cordsX += 1500.0f;
				}

			}
			else if (caseOfObsticle == 5) {
				printf("case 5");

				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(cordsX, cordsY - 220)));

			}
			else if (caseOfObsticle == 6) {
				printf("case 6");

				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY - 80)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY - 120)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY - 140)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1250.0f, cordsY - 160)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1500.0f, cordsY - 200)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1750.0f, cordsY - 240)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2000.0f, cordsY - 280)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2250.0f, cordsY - 320)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2500.0f, cordsY - 360)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2750.0f, cordsY - 400)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 3020.0f, cordsY - 440)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2000.0f, cordsY)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2250.0f, cordsY - 40)));
				cordsY -= 40.0f;
				cordsX += 2250.0f;
			}
			cordsX += 250.0f;
		}
	}

	return platforms;
};