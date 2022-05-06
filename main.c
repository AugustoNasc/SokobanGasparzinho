#include "raylib.h"
#include "mapa.h"
#include <string.h>
#include <stdio.h>
#include "movimentos.h"

#define QTD_QUADRADOS 12 
#define LARGURA 600
#define DIMENSAO LARGURA/QTD_QUADRADOS
                  
#define POSICAO for(int i=0; i<QTD_QUADRADOS; i++){\
                    for(int j=0; j<QTD_QUADRADOS; j++){\
\
                        if(mapa.mapa[i][j]=='P'){\
                            gY=i; gX=j;\
                        }\
\
                    }\
                }

int gX, gY;

MAPA mapa;
Quadrado peca;


int main(void)
{
    Music jogando;
    int flag=0;
    InitWindow(LARGURA, LARGURA, "Gasparzinho");
    InitAudioDevice();
    SetTargetFPS(60);
    mapa_criando1(&mapa);
    mapa_especial(&mapa);
    
    jogando = LoadMusicStream("C:/Users/augus/Downloads/terror.wav");
    PlayMusicStream(jogando);
    POSICAO;
    
    while (!WindowShouldClose()) {
       
       
       if(IsKeyPressed(KEY_A)){ flag=1; movimentos_move(&gX, &gY, flag, &mapa);}
       
       else if(IsKeyPressed(KEY_D)){ flag=2; movimentos_move(&gX, &gY, flag, &mapa);}
       
       else if(IsKeyPressed(KEY_S)){ flag=3; movimentos_move(&gX, &gY, flag, &mapa);}
       
       else if(IsKeyPressed(KEY_W)){ flag=4; movimentos_move(&gX, &gY, flag, &mapa);}
        
       
        
        BeginDrawing();
            ClearBackground(BLACK);
            
        mapa_desenhando(flag, mapa, peca);
        UpdateMusicStream(jogando);
        SetMusicVolume(jogando, 0.08);
        
        /*if(mapa_conseguiu()){
        
        }*/

         DrawFPS(0, 0);
    EndDrawing();
    }
    
    UnloadMusicStream(jogando);
    UnloadTexture(peca.imagem);
    CloseWindow();

    return 0;
}