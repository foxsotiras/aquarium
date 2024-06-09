#pragma once

#include <raylib.h>

struct Rock {
    Rectangle rect;

	Rock(int x, int y, int width, int height);
	void Draw();
};
