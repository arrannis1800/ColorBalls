#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "ball.h"
#include "structs.h"

class Ball;

class Level 
{
public:
	Level();
	Level(size_t h, size_t w, size_t num_balls);

	Collision bCollision(Position p);

	Cell get_level_pixel(size_t h, size_t w);

private:
	size_t height;
	size_t width;
	std::vector<Ball> balls;
	std::vector<Cell> level;
};

#endif