#include "../include/aquarium/aquarium.hpp"

void Aquarium::Init() {
    InitWindow(800, 600, "Aquarium");
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        EndDrawing();
    }

    CloseWindow();
}
