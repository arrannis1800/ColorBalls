#include "level.h"


Level::Level(uint32_t h, uint32_t w, size_t num_balls)
{
	height = h;
	width = w;

	for(size_t i = 0; i < num_balls; i++)
	{
		Ball ball = Ball(
					{.x=static_cast<int64_t>((i+1)*10),.y=static_cast<int64_t>((i+1)*50)}, 
					{.r=255,.g=255,.b=255}, 
					this);
		balls.push_back(ball);
	}

	for(uint32_t i = 0; i < height*width; i++)
	{
	    Cell cell;
	    cell.color = {
	        .r = static_cast<uint8_t>((i / width) * 256 / height),
	        .g = static_cast<uint8_t>((i % width) * 256 / width),
	        .b = static_cast<uint8_t>((i / width) * 256 / height)
	    };
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

Cell Level::get_level_pixel(uint32_t h, uint32_t w)
{
	return level[w+h*width];
};

std::vector<Ball> Level::get_balls()
{
	return balls;
};