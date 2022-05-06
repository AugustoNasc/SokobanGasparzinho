#ifndef MOVIMENTOS
#define MOVIMENTOS

#include "mapa.h"
#include "raylib.h"

void TROCA_VAZIO(MAPA *mapa, int *gX, int *gY, int cont1, int cont2);

void TROCA_CAIXA(int *x, int *y, int cont1, int cont2, MAPA *mapa, int level);

void movimentos_move(int *x,int *y,int gFlag, MAPA *mapa, int level);


#endif