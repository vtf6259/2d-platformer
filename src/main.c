#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include "consts.h"
#include "player.h"
#include "level.h"
#include "assets.h"

void cleanUp() {
    // Unload textures, free memory, etc.
}


int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "2D Platformer");
    Player player = CreatePlayer(100, 100, 50, 50, PLAYER_TEXTURE, 0, 700, 0, 500);
    loadLevel(&player);
    SetTargetFPS(120);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0, 0); /*SCREEN_WIDTH - 75*/
        UpdatePlayer(&player);
        MovePlayer(&player);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}