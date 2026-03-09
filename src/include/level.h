#pragma once
#include "player.h"

#include <raylib.h>

void addPlatform(int arrPos);

typedef struct {
    Vector2 position;
    Vector2 size;
} Platform;

typedef struct {
    Platform* platforms;
    int count;
} platformDynamic;

#include "levelFile.h"

typedef struct {
    Player player;
    LevelFileData levelData;
} Level;
