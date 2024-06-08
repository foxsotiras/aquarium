#include "../../include/aquarium/carp.hpp"
#include "../../include/aquarium/fish.hpp"

void Carp::Init() {
    Fish::Init(100, 100, 50, 50, 2, "assets/carp.png");
}
