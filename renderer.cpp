#include "renderer.h"

#include <stdio.h>

#include "consts.h"

bool init_window(Window& window)
{
	

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("ERROR: Couldn't init sdl\n");
		return false;
	} else
	{
		window.window = SDL_CreateWindow("ColorBalls", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LEVEL_HEIGHT, LEVEL_WIDTH, SDL_WINDOW_SHOWN);
		if(window.window == NULL)
		{
			printf("ERROR: Couldn't create window\n");
			return false;
		} 
	}

	return true;
};

void draw_window(Window& window)
{
	window.surface = SDL_GetWindowSurface(window.window);

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
};

void close_window(Window& window)
{
	SDL_DestroyWindow(window.window);
	SDL_Quit();
};