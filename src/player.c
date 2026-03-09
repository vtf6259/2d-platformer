#include <raylib.h>
#include <stdbool.h>
#include "player.h"

Player CreatePlayer(float x, float y, float width, float height, const char *texturePath) {
    Player player;
    player.position = (Vector2){x, y};
    player.velocity = (Vector2){0, 0};
    player.size = (Vector2){width, height};
    player.texturePath = texturePath;
    player.isOnGround = false;
    return player;
}