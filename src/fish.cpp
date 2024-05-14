#include "../include/aquarium/fish.hpp"
#include "../include/aquarium/aquarium.hpp"
#include <cmath>
#include <random>

namespace State {
    unsigned short state = 0;
    unsigned short fps_since_last_change = Aquarium::FPS;
    enum States { Idle = 0, MoveLeft, MoveForward, MoveRight };
}

void Fish::Init(float x, float y, int width, int height, float speed, const char* file) {
    m_coords.x = x;
    m_coords.y = y;
    std::random_device rd;
    std::uniform_real_distribution<float> dist(0, 2 * PI);
    m_angle = dist(rd);
    m_speed = speed;
    Image image = LoadImage(file);
    ImageResize(&image, width, height);
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void Fish::Draw() {
    DrawTextureEx(m_texture, m_coords, -m_angle * 180 / PI, 1, WHITE);
}

void Fish::Run() {
    if (State::fps_since_last_change == Aquarium::FPS) {
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, 3);
        State::state = dist(rd);
        State::fps_since_last_change = 0;
    }
    switch (State::state) {
        case State::States::Idle:
        break;
        case State::States::MoveLeft:
        MoveLeft();
        break;
        case State::States::MoveForward:
        MoveForward();
        break;
        case State::States::MoveRight:
        MoveRight();
        break;
    }
    ++State::fps_since_last_change;
}

void Fish::CheckObstacles() {
    if (m_coords.x <= 0 || m_coords.x + m_texture.width >= Aquarium::SCREEN_WIDTH
        || m_coords.y <= 0 || m_coords.y + m_texture.height >= Aquarium::SCREEN_HEIGHT) {
        m_angle += PI;
    }
}

void Fish::MoveForward() {
    CheckObstacles();
    m_coords.x += m_speed * cos(m_angle);
    m_coords.y += m_speed * sin(m_angle);
}

void Fish::MoveLeft() {
    m_angle += PI / 256;
    MoveForward();
}

void Fish::MoveRight() {
    m_angle -= PI / 256;
    MoveForward();
}
