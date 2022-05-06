#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"

typedef struct{
    Texture2D imagem;
    Vector2 coordenada;
} Quadrado;

typedef struct{
    char mapa[12][13];
    
    int especial_inicio[12][12];

    int especial_atual[12][12];

}MAPA;

void mapa_criando1(MAPA *mapa);
void mapa_criando2(MAPA *mapa);
void mapa_criando3(MAPA *mapa);
void mapa_criando4(MAPA *mapa);
void mapa_especial(MAPA *mapa);
int mapa_conseguiu(MAPA mapa);
void mapa_desenhando(int gFlag, MAPA mapa, Quadrado peca);


#endif