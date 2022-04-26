#include "raylib.h"

#include "player.h"

#include <stdlib.h>

#define DIMENSAO 128

Player *p;

void player_create()
{
    p = (Player *) malloc(sizeof(Player));

    p->texture = LoadTexture("assets/PNG/Retina/Player/player_03.png");
    p->rec = (Rectangle) {
        GetScreenWidth() / 2 - p->texture.width / 2,
        GetScreenHeight() / 2 - p->texture.height / 2,
        DIMENSAO,
        DIMENSAO
    };

}

void player_destroy()
{
    UnloadTexture(p->texture);
    free(p);
}

void player_draw()
{
    if (p == NULL) {
        return;
    }

    DrawTexture(
        p->texture,
        p->rec.x,
        p->rec.y,
        WHITE
    );
}

void player_update()
{
    Vector2 delta = { 0 };

    delta.x = (IsKeyPressed(KEY_D) - IsKeyPressed(KEY_A)) * DIMENSAO;
    delta.y = (IsKeyPressed(KEY_S) - IsKeyPressed(KEY_W)) * DIMENSAO;

    p->rec.x += delta.x;
    p->rec.y += delta.y;

}