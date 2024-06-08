#include "../../include/aquarium/rock.hpp"
#include <raylib.h>

Rock::Rock(int x, int y, int width, int height)  {
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
}

void Rock::Draw() {
	DrawRectangleRec(rect, GRAY);
}
