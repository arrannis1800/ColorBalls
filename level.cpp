#include "level.h"


Level::Level(size_t h, size_t w, size_t num_balls)
{
	height = h;
	width = w;

	for(size_t i = 0; i < num_balls; i++)
	{
		Ball ball = Ball({.x=i*2,.y=i*2}, {.color=0x00000000}, this);
		balls.push_back(ball);
	}
	Cell cell;
	cell.color.color = 0x00000000;
	level.resize(height*width, cell);
};

Collision Level::bCollision(Position p)
{
	int res = 0;
	if(p.x < 0 || p.x >= width)
	{
		res += 1;
	}
	if(p.y < 0 || p.y >= height)
	{
		res += 1;
	}
	return Collision(res);
};