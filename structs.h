#ifndef STRUCTS_H
#define STRUCTS_H
#include <SDL.h>

struct Window
{
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
};

struct Color
{
	uint32_t color;
};

struct Cell
{
	Color color;
};

struct Position
{
	size_t x;
	size_t y;
};

enum Collision
{
	NONE 		= 0,
	horizontal 	= 1,
	vertical 	= 2,
	both 		= 3,
};

#endif