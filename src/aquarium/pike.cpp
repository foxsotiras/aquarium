#include "../../include/aquarium/carp.hpp"
#include "../../include/aquarium/pike.hpp"
#include "../../include/aquarium/fish.hpp"
#include <iterator>
#include <list>
#include <raylib.h>

void Pike::Init() {
    Fish::Init(300, 300, 100, 50, 2, "assets/pike.png");
}

void Pike::EatCarp(std::list<Carp>& carps) {
    std::list<Carp>::iterator index = carps.begin();
    unsigned short i = 0;
    for (const Carp& carp : carps) {
        if (CheckCollisionRecs(m_hitbox, carp.GetHitbox())) {
            std::advance(index, i);
            carps.erase(index);
            break;
        }
        ++i;
    }
}
