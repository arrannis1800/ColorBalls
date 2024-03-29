#include "level.h"


Level::Level(size_t h, size_t w, size_t num_balls)
{
	height = h;
	width = w;

	for(size_t i = 0; i < num_balls; i++)
	{
		Ball ball = Ball({.x=(i+1)*10,.y=(i+1)*50}, {.r=255,.g=255,.b=255}, this);
		balls.push_back(ball);
	}

	for(size_t i = 0; i < height*width; i++)
	{
		Cell cell;
		cell.color = {.r=(uint8_t)(i/height),.g=(uint8_t)(i%width),.b=(uint8_t)(i%width)};
		level.push_back(cell);
	}
};

void Level::update_level()
{
	for (auto& ball : balls)
	{
		ball.update_position();
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
		res += 2;
	}
	return Collision(res);
};

Cell Level::get_level_pixel(size_t h, size_t w)
{
	return level[w+h*width];
};

std::vector<Ball> Level::get_balls()
{
	return balls;
};