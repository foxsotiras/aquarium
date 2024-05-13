#include "../include/aquarium/aquarium.hpp"

void Aquarium::Init() {
    InitWindow(800, 600, "Aquarium");
    carp.Init();
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        carp.Draw();
        EndDrawing();
    }

    CloseWindow();
}
