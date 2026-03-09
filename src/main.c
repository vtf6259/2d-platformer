#include <raylib.h>
#include <stdbool.h>
#include "consts.h"
#include "player.h"

void cleanUp() {
    // Unload textures, free memory, etc.
}


int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2D Platformer");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0, 0); /*SCREEN_WIDTH - 75*/

        EndDrawing();
    }
    return 0;
}