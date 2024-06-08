#include "../../include/aquarium/carp.hpp"
#include "../../include/aquarium/aquarium.hpp"
#include "../../include/aquarium/pike.hpp"
#include "../../include/aquarium/rock.hpp"
#include <raylib.h>

void Aquarium::Init() {
    InitWindow(800, 600, "Aquarium");
    SetTargetFPS(60);

    Carp carp;
    for (unsigned short i = 0; i < 3; ++i) {
        carp.Init();
        carps.push_back(carp);
    }

    Pike pike;
    for (unsigned short i = 0; i < 3; ++i) {
        pike.Init();
        pikes.push_back(pike);
    }

    rocks.push_back({ 0, 500, 100, 100 });
    rocks.push_back({ 200, 520, 100, 80 });
    rocks.push_back({ 600, 400, 200, 200 });
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(SKYBLUE);

        for (Carp& carp : carps) {
            carp.CheckObstacles(rocks);
            carp.Run();
        }

        for (Pike& pike : pikes) {
            pike.CheckObstacles(rocks);
            pike.EatCarp(carps);
            pike.Run();
        }

        for (Rock& rock : rocks) {
            rock.Draw();
        }

        EndDrawing();
    }
}

void Aquarium::Done() {
    CloseWindow();
}
