#ifndef RENDERER_H
#define RENDERER_H

#include "structs.h"
#include "level.h"

bool init_window(Window& window);

bool draw_window(Window& window, Level& level);

void draw_frame(Window& window, Level& level);

void close_window(Window& window);

#endif