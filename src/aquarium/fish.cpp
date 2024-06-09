#include "../../include/aquarium/fish.hpp"
#include "../../include/aquarium/rock.hpp"
#include <cmath>
#include <list>
#include <iostream>
#include <random>
#include <raylib.h>

namespace {
    enum States { Idle = 0, MoveLeft, MoveForward, MoveRight };
}

Fish::~Fish() {
    std::cout << "The object has been deleted" << '\n';
}

void Fish::Init(float x, float y, int width, int height, float velocity, const char* file) {
    m_coords.x = x;
    m_coords.y = y;
    m_hitbox.x = x;
    m_hitbox.y = y;
    m_hitbox.width = width;
    m_hitbox.height = height;
    std::random_device rd;
    std::uniform_real_distribution<float> dist(0, 2 * PI);
    m_angle = dist(rd);
    m_velocity = velocity;
    Image image = LoadImage(file);
    ImageResize(&image, width, height);
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void Fish::Draw() const {
    DrawTextureV(m_texture, m_coords, WHITE);
}

void Fish::Run() {
    if (fps_since_last_change == GetFPS()) {
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, 3);
        state = dist(rd);
        fps_since_last_change = 0;
    }
    switch (state) {
        case States::Idle:
            break;
        case States::MoveLeft:
            MoveLeft();
            break;
        case States::MoveForward:
            MoveForward();
            break;
        case States::MoveRight:
            MoveRight();
            break;
    }
    Draw();
    ++fps_since_last_change;
}

void Fish::CheckObstacles(const std::list<Rock>& rocks) {
    if (m_coords.x <= 0 || m_coords.x + m_texture.width >= GetScreenWidth() ||
        m_coords.y <= 0 || m_coords.y + m_texture.height >= GetScreenHeight()) {
        m_angle += PI;
    }

    for (const Rock& rock : rocks) {
        if (CheckCollisionRecs(m_hitbox, rock.rect)) {
            m_angle += PI;
        }
    }
}

void Fish::MoveForward() {
    m_coords.x += m_velocity * cos(m_angle);
    m_coords.y += m_velocity * sin(m_angle);
    m_hitbox.x = m_coords.x;
    m_hitbox.y = m_coords.y;
}

void Fish::MoveLeft() {
    m_angle += PI / 256;
    MoveForward();
}

void Fish::MoveRight() {
    m_angle -= PI / 256;
    MoveForward();
}

Rectangle Fish::GetHitbox() const { return m_hitbox; }
