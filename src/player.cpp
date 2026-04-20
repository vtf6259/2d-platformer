#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "player.h"
#include "consts.h"

Player CreatePlayer(float x, float y, float width, float height, const char *texturePath, int boundaryLeft, int boundaryRight, int boundryTop, int boundaryBottom) {
    Player player;
    player.position = (Vector2){x, y};
    //player.velocity = (Vector2){0, 0};
    player.size = (Vector2){width, height};
    player.texturePath = texturePath;
    player.isOnGround = false;
    if(player.texturePath != NULL) {
        player.texture = LoadTexture(player.texturePath);
    } else {
        player.texture = LoadTexture(texturePath);
    }
    player.boundaryLeft = boundaryLeft;
    player.boundaryRight = boundaryRight;
    player.boundaryTop = boundryTop;
    player.boundaryBottom = boundaryBottom;
    return player;
}

void UpdatePlayer(Player *player) {
    if(player->position.x < player->boundaryLeft) {
        player->position.x = player->boundaryLeft;
    }
    if(player->position.x > player->boundaryRight) {  
        player->position.x = player->boundaryRight;
    }
    if(player->position.y < player->boundaryTop) {
        player->position.y = player->boundaryTop;
    }
    if(player->position.y > player->boundaryBottom) {
        player->position.y = player->boundaryBottom;
        player->isOnGround = true;
    }

    if(player->texturePath == NULL) {
        DrawRectangle(player->position.x, player->position.y, player->size.x, player->size.y, RED);
    } else {
        DrawTexture(player->texture, player->position.x, player->position.y, WHITE);
    }
    //printf("Frame Time: %f\nCeil frame time%f\n",GetFrameTime(),ceil(GetFrameTime()));
}

void MovePlayer(Player *player) {
    
    int dt = GetFrameTime() * DELTA_MULTIPLIER;
    if (IsKeyDown(KEY_RIGHT_ALT)) {
        DrawText(TextFormat("Delta Time: %f\nDelta Speed: %f", GetFrameTime(), GetFrameTime() * DELTA_MULTIPLIER * SPEED), 10, 50, 20, GREEN);
    }
    if (IsKeyDown(KEY_RIGHT /*IsKeyDown(KEY_D)*/)) {
        player->position.x =  player->position.x + dt * SPEED;
        //printf("delta time applied\n");
        #if 0 == 1
        player->position.x = player->position.x + SPEED;
        #endif
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
    }
    if (IsKeyDown(KEY_LEFT) /*IsKeyDown(KEY_A)*/) {
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
        
        player->position.x = player->position.x - dt * SPEED;
        //printf("delta time applied\n");
        #if 0 == 1
        player->position.x = player->position.x - SPEED;
        #endif
    }
    if (IsKeyDown(KEY_UP) /*IsKeyDown(KEY_SPACE)*/) {
        
        player->position.y = player->position.y - dt * SPEED;
        //printf("delta time applied\n");
        #if 0 == 1
        player->position.y = player->position.y - SPEED;
        #endif
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
    }
    if (IsKeyDown(KEY_DOWN) /*IsKeyDown(KEY_LEFT_SHIFT) | IsKeyDown(KEY_RIGHT_SHIFT)*/) {
        
        player->position.y = player->position.y + dt * SPEED;
        //printf("delta time applied\n");
        #if 0 == 1
        player->position.y = player->position.y + SPEED;
        #endif
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
    }
    // Debug stuff KEY_LEFT_ALT is the debug key
    if (IsKeyDown(KEY_E)) {
        player->position.x = 0; // get to the left edge of the screen for boundry value testing
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
    }
    if (IsKeyDown(KEY_Q)) {
        player->position.x = 700; // get to the right edge of the screen for boundry value testing
        printf("Player position: (%f, %f)\n", player->position.x, player->position.y);
    }
    if (IsKeyDown(KEY_LEFT_ALT) && IsKeyDown(KEY_A)) {
        SetTargetFPS(60);
    }
    if (IsKeyDown(KEY_LEFT_ALT) && IsKeyDown(KEY_S)) {
        SetTargetFPS(120);
    }
}