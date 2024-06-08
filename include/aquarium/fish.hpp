#pragma once

#include "rock.hpp"
#include <list>
#include <raylib.h>

class Fish {
public:
    virtual ~Fish();

    virtual void Init() = 0;
    void Init(float x, float y, int width, int height, float velocity, const char* file);
    void Draw() const;
    void Run();

    void CheckObstacles(const std::list<Rock>& rocks);
    void MoveForward();
    void MoveLeft();
    void MoveRight();

    Rectangle GetHitbox() const;

protected:
    Vector2 m_coords;
    Texture2D m_texture;
    Rectangle m_hitbox;
    float m_velocity;
    float m_angle;
    unsigned short state{0};
    unsigned short fps_since_last_change{0};
};
