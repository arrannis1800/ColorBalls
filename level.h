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
	Level(uint32_t h, uint32_t w, size_t num_balls);

	void update_level();

	Collision bCollision(Position p);

	Cell get_level_pixel(uint32_t h, uint32_t w);

	std::vector<Ball> get_balls();
private:
	uint32_t height;
	uint32_t width;
	std::vector<Ball> balls;
	std::vector<Cell> level;
};

#endif