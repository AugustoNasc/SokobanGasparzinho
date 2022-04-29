#ifndef PLAYER
#define PLAYER

#include "raylib.h"

typedef struct {
    Texture2D imagem;
    Rectangle coordenada;
} Player;

void player_criado();
void player_free();
void player_move();
void player_desenhado();

#endif