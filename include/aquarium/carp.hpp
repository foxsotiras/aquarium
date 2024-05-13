#include "fish.hpp"

class Carp : public Fish {
    public:
    void Init() override { Fish::Init(0, 0, 50, 50, 5, "assets/carp.png"); }
};
