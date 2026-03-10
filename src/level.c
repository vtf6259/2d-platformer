#include <raylib.h>
#include <stdlib.h>
#include "assets.h"
#include "consts.h"
#include "player.h"
#include "level.h"
#include "globals.h"

void loadLevel(Player *player) {
    //currentLevel.player = CreatePlayer(0, 0, 50, 50, PLAYER_TEXTURE, 0, 700, 0, 500);
    currentLevel.player = player;
    currentLevel.levelData.platformData = malloc(sizeof(platformDynamic));
    currentLevel.levelData.platformData->count = 0;

}
void addPlatform(int arrPos) {
    currentLevel.levelData.platformData->count++;
    currentLevel.levelData.platformData->platforms = realloc(currentLevel.levelData.platformData->platforms, sizeof(Platform) * currentLevel.levelData.platformData->count);
}
