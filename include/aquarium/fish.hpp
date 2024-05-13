#include <raylib.h>

class Fish {
    public:
    virtual void Init() { Fish::Init(0, 0, 30, 30, 0, "assets/error.png"); }
    void Init(float x, float y, int width, int height, float speed, const char* file );
    void Draw();

    protected:
    Vector2 m_coords;
    Vector2 m_offset;
    Texture2D m_texture;
    float m_speed;
};
