#include "../include/aquarium/fish.hpp"

void Fish::Init(float x, float y, int width, int height, float speed, const char* file) {
    m_coords.x = x;
    m_coords.y = y;
    m_speed = speed;
    Image image = LoadImage(file);
    ImageResize(&image, width, height);
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void Fish::Draw() {
    DrawTextureV(m_texture, m_coords, WHITE);
}
