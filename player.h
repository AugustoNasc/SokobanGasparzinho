#ifndef PLAYER
#define PLAYER

#include "raylib.h"

typedef struct {
    Texture2D texture;
    Rectangle rec;
} Player;

void player_create();
void player_destroy();
void player_update();
void player_draw();

#endif