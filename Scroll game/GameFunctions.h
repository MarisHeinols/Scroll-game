#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Coin.h"
#include <sstream>
#include "Source.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
class GameFunctions {
public:
	GameFunctions();
	~GameFunctions();

	void runGame(const sf::RenderWindow& window, sf::View& view);

};