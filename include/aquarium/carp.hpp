#include "fish.hpp"

#pragma once

class Carp : public Fish {
    public:
    void Init() override { Fish::Init(400, 300, 50, 50, 2, "assets/carp.png"); }
};
