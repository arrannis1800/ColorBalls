#include "consts.h"
#include "structs.h"
#include "level.h"
#include "renderer.h"


int main(int argc, char *argv[])
{
	Window window;
	if(init_window(window))
	{

			Level level = Level(LEVEL_HEIGHT, LEVEL_WIDTH, BALLS);

			draw_window(window, level);
		
	}

	close_window(window);

	return 0;
}