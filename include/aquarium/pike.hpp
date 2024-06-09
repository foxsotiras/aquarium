#pragma once

#include "carp.hpp"
#include "fish.hpp"
#include <list>

class Pike: public Fish {
public:
    void Init() override;
    void EatCarp(std::list<Carp>& carps);
};
