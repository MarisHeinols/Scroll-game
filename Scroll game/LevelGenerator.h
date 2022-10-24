#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <vector>

class LevelGenerator{
public:
	LevelGenerator();
	~LevelGenerator();
    std::vector<Platfrom> generatePlatforms();
    void resetCords() {
        cordsX = 800.0f;
        cordsY = 250.0f;
    }

private:
    std::vector<Platfrom> platforms;
    float cordsX = 800.0f;
    float cordsY = 250.0f;
};