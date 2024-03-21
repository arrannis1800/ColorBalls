#include <stdio.h>
#include <SDL.h>
#include <math.h>

#define PI 3.14159265359
#define VELOCITY 1 

#include "structs.h"
#include "level.h"


int main(int argc, char *argv[])
{



	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("ERROR: Couldn't init sdl\n");
		return 1;
	} else
	{
		window = SDL_CreateWindow("ColorBalls", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 500, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			printf("ERROR: Couldn't create window\n");
			return 1;
		} else
		{
			surface = SDL_GetWindowSurface(window);

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
		}
	}


	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}