#include "renderer.h"

#include <stdio.h>

#include "consts.h"

bool init_window(Window& window)
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("ERROR: Couldn't init sdl\n");
		success = false;
        return success;
	} else
	{
		window.window = SDL_CreateWindow("ColorBalls", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LEVEL_WIDTH, LEVEL_HEIGHT, SDL_WINDOW_SHOWN);
		if(window.window == NULL)
		{
			printf("ERROR: Couldn't create window\n");
			success = false;
        	return success;
		} else
		{
			window.renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED);
		}
	}

	return success;
};

void draw_frame(Window& window, Level& level)
{

    SDL_RenderClear(window.renderer);
    for (uint32_t row = 0; row < LEVEL_HEIGHT; row++)
    {
    	for (uint32_t col = 0; col < LEVEL_WIDTH; col++)
    	{
    		Color cell = level.get_level_pixel(row, col).color;
    		SDL_SetRenderDrawColor(window.renderer, cell.r, cell.g, cell.b, 255);
			SDL_RenderDrawPoint(window.renderer, col, row);	
    	}
    }

    std::vector<Ball> balls = level.get_balls();
	for (auto& ball : balls)
	{
		Color color = ball.get_color();
		SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, 255);
		Position pos = ball.get_position();
		SDL_RenderDrawPoint(window.renderer, pos.x, pos.y);	
	}

	SDL_RenderPresent(window.renderer);

	SDL_Delay(100);
};

bool draw_window(Window& window, Level& level)
{
	bool success = true;

	if (window.renderer == nullptr)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
        return success;
    }

	SDL_Event e;
	bool quit = false;
	while (!quit)
	{

		draw_frame(window,level);

		level.update_level();

		while (SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
	return success;
};

void close_window(Window& window)
{
	SDL_DestroyRenderer(window.renderer);
	SDL_DestroyWindow(window.window);
	SDL_Quit();
};