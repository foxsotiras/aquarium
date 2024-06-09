#include "../../include/aquarium/carp.hpp"
#include "../../include/aquarium/aquarium.hpp"
#include "../../include/aquarium/pike.hpp"
#include "../../include/aquarium/rock.hpp"
#include <raylib.h>

void Aquarium::Init() {
    InitWindow(800, 600, "Aquarium");
    SetTargetFPS(75);

    Carp carp;
    carp.Init();
    for (unsigned short i = 0; i < 3; ++i) {
        carps.push_back(carp);
    }

    Pike pike;
    pike.Init();
    for (unsigned short i = 0; i < 3; ++i) {
        pikes.push_back(pike);
    }

    rocks.push_back({ 0, 500, 100, 100 });
    rocks.push_back({ 200, 520, 100, 80 });
    rocks.push_back({ 600, 400, 200, 200 });
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_L)) {
            Carp* carp = new Carp[5000];
            for (int i = 0; i < 5000; ++i) {
                carp[i].Init();
                carps.push_back(carp[i]);
            }
        }

        if (IsKeyDown(KEY_A)) {
            Carp carp;
            carp.Init();
            carps.push_back(carp);
        }

        if (IsKeyDown(KEY_D)) {
            if (!carps.empty()) {
                carps.pop_back();
            }
        }
        
        if (IsKeyDown(KEY_W)) {
            Pike pike;
            pike.Init();
            pikes.push_back(pike);
        }

        if (IsKeyDown(KEY_S)) {
            if (!pikes.empty()) {
                pikes.pop_back();
            }
        }

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
