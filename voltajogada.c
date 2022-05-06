#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "mapa.h"
#include "voltajogada.h"



void registrando_jogadas(MAPA mapa, int level){
    FILE *arq;
    char endereco[50];
    sprintf(endereco, "jogadas/jog_mapa%d.bin", level);
    arq = fopen(endereco, "ab");

    fwrite(&mapa, sizeof(MAPA), 1, arq);

    fclose(arq);

}

void voltando_jogada(MAPA *mapa, int level, int voltando){
    FILE *arq;
    char endereco[50];
    sprintf(endereco, "jogadas/jog_mapa%d.bin", level);

    arq = fopen(endereco, "rb");

    fseek(arq, (-2-voltando)*sizeof(MAPA), SEEK_END);

    fread(mapa, sizeof(MAPA), 1, arq);


    fclose(arq);
}

void adiantando_jogada(MAPA *mapa, int level, int voltando){
    FILE *arq;
    char endereco[50];
    sprintf(endereco, "jogadas/jog_mapa%d.bin", level);

    arq = fopen(endereco, "rb");

    fseek(arq, (-voltando)*sizeof(MAPA), SEEK_END);
    fread(mapa, sizeof(MAPA), 1, arq);


    fclose(arq);
}

void apagar_jogadas(int level){

    FILE *arquivo;
    char endereco[50];

    sprintf(endereco, "jogadas/jog_mapa%d.bin", level);
    arquivo = fopen(endereco, "wb");

    fclose(arquivo);

}
