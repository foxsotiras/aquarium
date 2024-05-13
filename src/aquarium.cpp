#include "../include/aquarium/aquarium.hpp"

void Aquarium::Init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Aquarium");
    carp.Init();
    SetTargetFPS(FPS);
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        carp.Draw();
        carp.Run();
        EndDrawing();
    }

    CloseWindow();
}
