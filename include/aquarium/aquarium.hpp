#pragma once

#include "carp.hpp"
#include "pike.hpp"
#include "rock.hpp"
#include <list>

class Aquarium {
public:
    void Init();
    void Run();
    void Done();

private:
    std::list<Rock> rocks;
    std::list<Carp> carps;
    std::list<Pike> pikes;
};
