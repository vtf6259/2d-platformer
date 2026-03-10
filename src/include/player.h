#pragma once
#include <raylib.h>
typedef struct Player {
    Vector2 position;
    //Vector2 velocity;
    Vector2 size;
    Texture2D texture;
    const char *texturePath;
    int boundaryLeft;
    int boundaryRight;
    int boundaryTop;
    int boundaryBottom;
    bool isOnGround;
} Player;

Player CreatePlayer(float x, float y, float width, float height, const char *texturePath, int boundaryLeft, int boundaryRight, int boundryTop, int boundaryBottom);
void UpdatePlayer(Player *player);
void MovePlayer(Player *player);