#include "../include/aquarium/aquarium.hpp"

int main() {
    Aquarium* aquarium = new Aquarium();
    aquarium->Init();
    aquarium->Run();
    delete aquarium;

    return 0;
}
