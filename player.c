#include "raylib.h"

#include "player.h"

#include <stdlib.h>

#define DIMENSAO 128

//testando essa parada de branch

Player *gasparzinho;

void player_criado()
{
    gasparzinho = (Player *) malloc(sizeof(Player));

    gasparzinho->imagem = LoadTexture("assets/PNG/Retina/Player/player_03.png");
    gasparzinho->coordenada = (Rectangle) {
        GetScreenWidth() / 2 - gasparzinho->imagem.width / 2,
        GetScreenHeight() / 2 - gasparzinho->imagem.height / 2,
        DIMENSAO,
        DIMENSAO
    };

}

void player_free()
{
    UnloadTexture(gasparzinho->imagem);
    free(gasparzinho);
}

void player_desenhado()
{
    if (gasparzinho == NULL) {
        return;
    }

    DrawTexture(
        gasparzinho->imagem,
        gasparzinho->coordenada.x,
        gasparzinho->coordenada.y,
        WHITE
    );
}

void player_move()
{
    Vector2 delta = { 0 };

    delta.x = (IsKeyPressed(KEY_D) - IsKeyPressed(KEY_A)) * DIMENSAO;
    delta.y = (IsKeyPressed(KEY_S) - IsKeyPressed(KEY_W)) * DIMENSAO;

    gasparzinho->coordenada.x += delta.x;
    gasparzinho->coordenada.y += delta.y;

}