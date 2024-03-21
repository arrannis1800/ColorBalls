#ifndef BALL_H
#define BALL_H

#include <random>

#include "level.h"
class Level;

class Ball 
{
public:
	Ball(Position pos, Color col, Level* level);

	Position get_position();

	void update_position();

private:
	Position position;
	float rad_direction;
	Color color;
	Level* world;
};

#endif