#pragma once
#include <raylib.h>
typedef struct Player {
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    const char *texturePath;
    bool isOnGround;
} Player;

Player CreatePlayer(float x, float y, float width, float height, const char *texturePath);
bool UpdatePlayer(Player *player);