#ifndef LEVEL_H
#define LEVEL_H

#include "ball.h"

class Level 
{
public:
	Level(size_t h, size_t w);

	Collision bCollision(Position p);

private:
	size_t height;
	size_t width;
	std::vector<Ball> balls;
	std::vector<Cell> level;
};

#endif