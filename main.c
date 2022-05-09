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

typedef enum GameScreen { TITLE = 0, MENU, MANUAL1, MANUAL2, CREDITO, GAMEPLAY } GameScreen;

MAPA mapa;

int main(void)
{
    FILE *arquivo;
    Music jogando;
    Sound conseguiu;
    int flag=0;
    int level=1;

    Quadrado *imagens;
    imagens = (Quadrado *)calloc(6, sizeof(Quadrado));

    Quadrado *fundo;
    fundo = (Quadrado *)calloc(13, sizeof(Quadrado));


    InitWindow(LARGURA, LARGURA, "Gasparzinho");
    GameScreen currentScreen = TITLE;

    Texture2D background = LoadTexture("assets/fundo.png");
    
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

    conseguiu = LoadSound("assets/musica/fim_fase.mp3");

    int voltando=0;
    while (!WindowShouldClose()) {
    
        switch(currentScreen){
            case TITLE: //MECANICAS DA TELA DO TITULO DO GAME
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
                
                if (IsKeyPressed(KEY_I))
                {
                    currentScreen = MANUAL1;
                }
                if (IsKeyPressed(KEY_C))
                {
                    currentScreen = CREDITO;
                }
            } break;
            case MENU: //MECANICAS DA TELA DE MENU
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
                
                if (IsKeyPressed(KEY_I))
                {
                    currentScreen = MANUAL2;
                }
                if (IsKeyPressed(KEY_Q))
                {
                    currentScreen = TITLE;
                }
            } break;
            case MANUAL1: //MECANICAS DA TELA DE INSTRUCOES NO INICIO
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                if(IsKeyPressed(KEY_Q)){
                    currentScreen = TITLE;
                }
            } break;
            case MANUAL2: //MECANICAS DA TELA DE INSTRUCOES NO JOGO
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                if(IsKeyPressed(KEY_Q)){
                    currentScreen = MENU;
                }
            } break;
            case CREDITO:
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                if(IsKeyPressed(KEY_Q)){
                    currentScreen = TITLE;
                }
            } break;
            case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
            {
                if(IsKeyPressed(KEY_M)){
                    currentScreen = MENU;
                }
                // inicio jogo   
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
                            
            } break;
            
            default:
                break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        switch(currentScreen){
            case TITLE: //TELA DO TITULO DO GAME
            {
                DrawTexture(background, LARGURA, LARGURA, WHITE); 
                DrawText("SOKOBAN", 220, 125, 36, BLACK);
                DrawText("GASPARZINHO", 116, 170, 50, BLACK);               
                DrawRectangle(170, 310, 260, 40, LIGHTGRAY);
                DrawText("JOGAR [ENTER]", 226, 322, 20, BLACK);
                DrawRectangle(170, 370, 260, 40, LIGHTGRAY);
                DrawText("INSTRUÇÕES [I]", 224, 382, 20, BLACK);
                DrawRectangle(170, 430, 260, 40, LIGHTGRAY);
                DrawText("CRÉDITOS [C]", 235, 442, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 183, 550, 15, BLACK);
            } break;

            case MENU: //MECANICAS DA TELA DE MENU
            {
                DrawTexture(background, 0, 0, WHITE);
                DrawText("JOGO PAUSADO", 126, 140, 45, BLACK);
                DrawRectangle(170, 310, 260, 40, LIGHTGRAY);
                DrawText("CONTINUAR [ENTER]", 196, 322, 20, BLACK);
                DrawRectangle(170, 370, 260, 40, LIGHTGRAY);
                DrawText("INSTRUÇÕES [I]", 224, 382, 20, BLACK);
                DrawRectangle(170, 430, 260, 40, LIGHTGRAY);
                DrawText("MENU PRINCIPAL [Q]", 197, 442, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 183, 550, 15, BLACK);
            } break;

            case MANUAL1: //MECANICAS DA TELA DE MENU
            {
                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("COMO JOGAR:", 222, 100, 25, BLACK);
                DrawText("[W] - CIMA", 248, 160, 20, BLACK);
                DrawText("[A] - ESQUERDA", 225, 195, 20, BLACK);
                DrawText("[S] - BAIXO", 245, 230, 20, BLACK);
                DrawText("[D] - DIREITA", 230, 265, 20, BLACK);
                DrawText("[M] - MENU", 246, 300, 20, BLACK);
                DrawText("[Z] - VOLTAR JOGADA", 190, 335, 20, BLACK);
                DrawText("[C] - DESFAZER VOLTA DE JOGADA", 100, 370, 20, BLACK);
                DrawText("[X] - RESETAR NÍVEL", 195, 405, 20, BLACK);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 183, 550, 15, BLACK);
            } break;
            
            case MANUAL2: //MECANICAS DA TELA DE MENU
            {
                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("COMO JOGAR:", 222, 100, 25, BLACK);
                DrawText("[W] - CIMA", 248, 160, 20, BLACK);
                DrawText("[A] - ESQUERDA", 225, 195, 20, BLACK);
                DrawText("[S] - BAIXO", 245, 230, 20, BLACK);
                DrawText("[D] - DIREITA", 230, 265, 20, BLACK);
                DrawText("[M] - MENU", 246, 300, 20, BLACK);
                DrawText("[Z] - VOLTAR JOGADA", 190, 335, 20, BLACK);
                DrawText("[C] - DESFAZER VOLTA DE JOGADA", 100, 370, 20, BLACK);
                DrawText("[X] - RESETAR NÍVEL", 195, 405, 20, BLACK);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 183, 550, 15, BLACK);
            } break;

            case CREDITO: //MECANICAS DA TELA DE CREDITOS
            {
                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("CRÉDITOS", 237, 100, 25, BLACK);
                DrawText("AUGUSTO NASCIMENTO", 178, 180, 20, BLACK);
                DrawText("[ano@cin.ufpe.br]", 218, 200, 20, BLACK);
                DrawText("EDENN WESLLEY", 215, 240, 20, BLACK);
                DrawText("[ewss@cin.ufpe.br]", 212, 260, 20, BLACK);
                DrawText("ENIO HENRIQUE", 220, 300, 20, BLACK);
                DrawText("[ehnr@cin.ufpe.br]", 212, 320, 20, BLACK);
                DrawText("GABRIEL WANDERLEY", 192, 360, 20, BLACK);
                DrawText("[gwcs@cin.ufpe.br]", 214, 380, 20, BLACK);
                DrawText("MARIA LETICIA", 223, 420, 20, BLACK);
                DrawText("[mlng@cin.ufpe.br]", 216, 440, 20, BLACK);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 183, 550, 15, BLACK);
            } break;

            case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
            {
                mapa_desenhando(flag, mapa, imagens, fundo, level);
                UpdateMusicStream(jogando);
                SetMusicVolume(jogando, 0.08);

                //TEXTO DE TESTE GAMEPLAY
                DrawRectangle(460, 560, 130, 30, WHITE);
                DrawText("[M] - PAUSA", 475, 568, 18, BLACK);
            } break;
            default:
                break;
        }

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
            PlaySound(conseguiu);
            SetSoundVolume(conseguiu, 0.3);
            POSICAO;
            flag=0;

            PlayMusicStream(jogando);
        }
    } //fim jogo

    apagar_jogadas(level);
    UnloadMusicStream(jogando);
    UnloadSound(conseguiu);
    mapa_Unload(&imagens, &fundo);
    UnloadTexture(background);  
    CloseWindow();

    fclose(arquivo);
    free(imagens);
    free(fundo);

    return 0;
}