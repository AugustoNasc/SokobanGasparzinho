#include "raylib.h"
#include "mapa.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "movimentos.h"
#include "voltajogada.h"

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


int main(void)
{
    FILE *arquivo;
    Music jogando;
    int flag=0;
    int level=1;

    Quadrado *imagens;
    imagens = (Quadrado *)calloc(6, sizeof(Quadrado));

    Quadrado *fundo;
    fundo = (Quadrado *)calloc(13, sizeof(Quadrado));


    InitWindow(LARGURA, LARGURA, "Gasparzinho");
    InitAudioDevice();
    SetTargetFPS(60);
    //mapa_criando1(&mapa);
    
    char endereco[50];
    sprintf(endereco, "mapastxt/mapa%d.txt", level);
    arquivo = fopen(endereco, "rt");
    fread(mapa.mapa, sizeof(char), 12*13, arquivo);
    mapa_especial(&mapa);
    POSICAO;

    mapa_declararpng(&imagens);
    mapa_fundo(&fundo);
    
    jogando = LoadMusicStream("assets/musica/terror.wav");
    PlayMusicStream(jogando);

    int voltando=0;
    while (!WindowShouldClose()) {
       
       
       if(IsKeyPressed(KEY_A)){ 
            flag=1; 
            voltando=0;
            movimentos_move(&gX, &gY, flag, &mapa, level);
       }
       
       else if(IsKeyPressed(KEY_D)){ 
            flag=2;
            voltando=0;
            movimentos_move(&gX, &gY, flag, &mapa, level);
       }
       
       else if(IsKeyPressed(KEY_S)){ 
            flag=3;
            voltando=0;
            movimentos_move(&gX, &gY, flag, &mapa, level);
       }
       
       else if(IsKeyPressed(KEY_W)){ 
            flag=4; 
            voltando=0;
            movimentos_move(&gX, &gY, flag, &mapa, level);
       }

       else if(IsKeyPressed(KEY_Z)){ 
            voltando_jogada(&mapa, level, voltando);
            voltando++;
            //mapa.especial_atual[1][3]=1;
            flag=0;
            POSICAO;
       }

       else if(IsKeyPressed(KEY_C)){ 
           if(voltando!=0){
                adiantando_jogada(&mapa, level, voltando);
                voltando--;
                flag=0;
                POSICAO;
           }
        }
       else if(IsKeyPressed(KEY_X)){ 

            mapa = mapa_rezetar(level);

            mapa_especial(&mapa);

            StopMusicStream(jogando);

            POSICAO;
            flag=0;

            PlayMusicStream(jogando);
        }
        //provisorio, so para admins
       else if(IsKeyPressed(KEY_P)){ 
           apagar_jogadas(level);
            level++;

            sprintf(endereco, "mapastxt/mapa%d.txt", level);

            arquivo = fopen(endereco, "rt");

            fread(mapa.mapa, sizeof(char), 12*13, arquivo);

            mapa_especial(&mapa);

            StopMusicStream(jogando);

            POSICAO;
            flag=0;

            PlayMusicStream(jogando);
        }

       else if(IsKeyPressed(KEY_O)){ 
           apagar_jogadas(level);
            level--;

            sprintf(endereco, "mapastxt/mapa%d.txt", level);

            arquivo = fopen(endereco, "rt");

            fread(mapa.mapa, sizeof(char), 12*13, arquivo);

            mapa_especial(&mapa);

            StopMusicStream(jogando);

            POSICAO;
            flag=0;

            PlayMusicStream(jogando);
        }
        
       
        
        BeginDrawing();
            ClearBackground(BLACK);
            
        mapa_desenhando(flag, mapa, imagens, fundo, level);

        UpdateMusicStream(jogando);
        SetMusicVolume(jogando, 0.08);
        
        /*if(mapa_conseguiu()){
        
        }*/

         DrawFPS(0, 0);
    EndDrawing();

        if(mapa_conseguiu(mapa)){

            apagar_jogadas(level);
            level++;

            sprintf(endereco, "mapastxt/mapa%d.txt", level);
            arquivo = fopen(endereco, "rt");
            fread(mapa.mapa, sizeof(char), 12*13, arquivo);
            mapa_especial(&mapa);


            StopMusicStream(jogando);

            POSICAO;
            flag=0;

            PlayMusicStream(jogando);
        }
    }
    apagar_jogadas(level);
    UnloadMusicStream(jogando);
    mapa_Unload(&imagens, &fundo);
    CloseWindow();

    fclose(arquivo);
    free(imagens);
    free(fundo);

    return 0;
}