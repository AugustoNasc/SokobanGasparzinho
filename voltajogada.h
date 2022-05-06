#ifndef VOLTAJOGADAS
#define VOLTAJOGADAS

#include "mapa.h"
#include "raylib.h"
#include <stdio.h>

void registrando_jogadas(MAPA mapa, int level);
void voltando_jogada(MAPA *mapa, int level, int voltando);
void adiantando_jogada(MAPA *mapa, int level, int voltando);
void apagar_jogadas(int level);

#endif