#include "level.h"
#include "structs.h"


Level::Level(size_t h, size_t w)
{
	height = h;
	width = w;

	balls = {Ball()};
	Cell cell;
	cell.color = 0x00000000;
	level.resize(height*width, cell)
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