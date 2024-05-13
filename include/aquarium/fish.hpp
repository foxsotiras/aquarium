#include <raylib.h>

#pragma once

class Fish {
    public:
    virtual void Init() { Fish::Init(0, 0, 30, 30, 0, "assets/error.png"); }
    void Init(float x, float y, int width, int height, float speed, const char* file);
    void Draw();
    void Run();
    void CheckObstacles();
    void MoveForward();
    void MoveLeft();
    void MoveRight();

    void setSpeed(float speed) { m_speed = speed; }
    void setAngle(float angle) { m_angle = angle; }

    protected:
    Vector2 m_coords;
    float m_angle;
    Texture2D m_texture;
    float m_speed;
};
