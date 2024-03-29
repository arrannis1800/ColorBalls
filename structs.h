#ifndef STRUCTS_H
#define STRUCTS_H
#include <SDL.h>

struct Window
{
	SDL_Window* window;
	SDL_Renderer* renderer;
};

struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
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