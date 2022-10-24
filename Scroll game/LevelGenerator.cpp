#include "LevelGenerator.h"

LevelGenerator::LevelGenerator()
{
}

LevelGenerator::~LevelGenerator()
{
}

std::vector<Platfrom> LevelGenerator::generatePlatforms() {
	platforms.clear();
	//Texture loading
	sf::Texture platformTexture;
	platformTexture.loadFromFile("platform.png");

	//Start platform
	platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(300.0f, 350.0f)));

	//Randomly generated level
	for (size_t i = 0; i < 100; i++)
	{
		int caseOfObsticle = (1 + rand() % 7);

		if (cordsX == 800.0f) {
			platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			cordsX += 250.0f;
		}
		else {
			if (caseOfObsticle == 1) {
				if (cordsY < 200.0f) {
					cordsY = 200.0f;
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));

				}
				else {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));

				}
			}
			else if (caseOfObsticle == 2) {
				if (cordsY > 200.0f) {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40.0f)));
					cordsY -= 40.0f;
					cordsX += 250.0f;
				}
				else {
					cordsY += 40.0f;
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				}
			}
			else if (caseOfObsticle == 3) {

				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
			}
			else if (caseOfObsticle == 4) {

				if (cordsY > 200.0f) {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY - 80.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY - 120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY - 140.0f)));
					cordsY -= 140.0f;
					cordsX += 1000.0f;
				}
				else {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY + 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY + 0.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY -40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY -80.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1250.0f, cordsY -120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1500.0f, cordsY -160.0f)));
					cordsY -= 160.0f;
					cordsX += 1500.0f;
				}

			}
			else if (caseOfObsticle == 5) {
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 200.0f), sf::Vector2f(cordsX, cordsY - 260.0f)));


			}
			else if (caseOfObsticle == 6) {
				if(cordsX > 2000.0f){
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY - 80.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY - 120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY - 140.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1250.0f, cordsY - 160.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1500.0f, cordsY - 200.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 1750.0f, cordsY - 240.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2000.0f, cordsY - 280.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2250.0f, cordsY - 320.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2500.0f, cordsY - 360.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2750.0f, cordsY - 400.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 3020.0f, cordsY - 440.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2000.0f, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX + 2250.0f, cordsY - 40.0f)));
					cordsY -= 40.0f;
					cordsX += 2250.0f;
				}
				else {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
				}
			}
			else if (caseOfObsticle == 7) {
				if (cordsX > 2000 && cordsY < 0.0f) {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(20.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY - 80.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(20.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY - 120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 950.0f, cordsY + 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(20.0f, 50.0f), sf::Vector2f(cordsX + 1200.0f, cordsY + 120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 1450.0f, cordsY + 80.0f)));
					cordsX += 1450.0f;
					cordsY += 80.0f;
				}
				else {
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX, cordsY)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 250.0f, cordsY - 40.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 500.0f, cordsY - 80.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 750.0f, cordsY - 120.0f)));
					platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(cordsX + 1000.0f, cordsY - 140.0f)));
					cordsY -= 140.0f;
					cordsX += 1000.0f;
				}
			}
			cordsX += 250.0f;
		}
	}
	//End platform
	platforms.push_back(Platfrom(&platformTexture, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(cordsX, cordsY)));

	return platforms;
};