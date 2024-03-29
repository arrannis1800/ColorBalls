#include "ball.h"

#include <random>

#include "consts.h"

Ball::Ball(Position pos, Color col, Level* level)
{
	position = pos;
	color = col;	
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2*PI);
    rad_direction = dis(gen);
    world = level;
};

Position Ball::get_position()
{
	return position;
};

Color Ball::get_color()
{
	return color;
};

void Ball::update_position()
{
	Position temp_p;
	temp_p.x = position.x + floor(VELOCITY * sinf(rad_direction) + 0.5);
	temp_p.y = position.y + floor(VELOCITY * cosf(rad_direction) + 0.5);

	Collision is_collision = world->bCollision(temp_p);
	
	if(is_collision)
	{
		if (is_collision & 1) // horizontal
		{
			rad_direction = 2*PI - rad_direction;
		} 
		if (is_collision & 2) // vertical
		{
			rad_direction = fmod(2*PI - rad_direction + PI, 2*PI);
		}
		update_position();
		return;
	}

	position = temp_p;
	
	return;
};