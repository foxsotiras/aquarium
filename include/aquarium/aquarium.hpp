#include "carp.hpp"
#include <raylib.h>

#pragma once

class Aquarium {
    public:
    static const unsigned short SCREEN_WIDTH = 800;
    static const unsigned short SCREEN_HEIGHT = 600;
    static const unsigned short FPS = 60;

    void Init();
    void Run();

    private:
    Carp carp;
};
