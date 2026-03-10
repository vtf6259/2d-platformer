#include <raylib.h>
#include <stdlib.h>
#include "assets.h"
#include "consts.h"
#include "player.h"
#include "level.h"
#include "globals.h"

void loadLevel() {
    currentLevel.player = CreatePlayer(0, 0, 50, 50, PLAYER_TEXTURE, 0, 700);

}
void addPlatform(int arrPos) {
    currentLevel.levelData.platformData->count++;
    currentLevel.levelData.platformData->platforms = realloc(currentLevel.levelData.platformData->platforms, sizeof(Platform) * currentLevel.levelData.platformData->count);
}
