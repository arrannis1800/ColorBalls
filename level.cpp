#include "level.h"


Level::Level(size_t h, size_t w, size_t num_balls)
{
	height = h;
	width = w;

	for(size_t i = 0; i < num_balls; i++)
	{
		Ball ball = Ball({.x=i*2,.y=i*2}, {.r=255,.g=255,.b=255}, this);
		balls.push_back(ball);
	}

	for(size_t i = 0; i < height*width; i++)
	{
		Cell cell;
		cell.color = {.r=i/height,.g=i%width,.b=i%width};
		level.push_back(cell);
	}
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

Cell Level::get_level_pixel(size_t h, size_t w)
{
	return level[w+h*width];
};