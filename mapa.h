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

void mapa_especial(MAPA *mapa);
int mapa_conseguiu(MAPA mapa);
void mapa_desenhando(int gFlag, MAPA mapa, Quadrado *imagens, Quadrado *fundo, int level);
void mapa_declararpng(Quadrado **imagens);
void mapa_fundo(Quadrado **fundo);
void mapa_Unload(Quadrado **imagens, Quadrado **fundo);
MAPA mapa_rezetar(int level);


#endif