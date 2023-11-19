#include "guarda_nivel.hpp"
#include <stdio.h>

void guarda_salva_nivel(int level){
    FILE *arq = fopen("jogadas/nivel.txt", "wt");
    fprintf(arq, "%d", level);
    fclose(arq);
}

int guarda_ler_nivel(void){

    int level;
    FILE *arq = fopen("jogadas/nivel.txt", "rt");
    fscanf(arq, "%d", &level);
    fclose(arq);

    return level;
}