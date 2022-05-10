#include "raylib.h"
#include "mapa.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "movimentos.h"
#include "voltajogada.h"
#include "guarda_nivel.h"

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

typedef enum GameScreen { TITLE = 0, MENU, MANUAL1, MANUAL2, ESCOLHER_NIVEL, CREDITO, GAMEPLAY, PARABENS } GameScreen;

MAPA mapa;

int main(void)
{
    FILE *arquivo;
    Music jogando, abertura;
    Sound conseguiu;
    int flag=0;
    int level=1, maximo=1, Ultimo=0;

    Quadrado *imagens;
    imagens = (Quadrado *)calloc(6, sizeof(Quadrado));

    Quadrado *fundo;
    fundo = (Quadrado *)calloc(13, sizeof(Quadrado));


    InitWindow(LARGURA, LARGURA, "Gasparzinho");
    GameScreen currentScreen = TITLE;

    Vector2 posicaoMouse={0,0};
    Rectangle mouse = {posicaoMouse.x, posicaoMouse.y, 20, 20};

    Texture2D background = LoadTexture("assets/fundo.png");
    
    InitAudioDevice();
    SetTargetFPS(60);
    //mapa_criando1(&mapa);
    abertura = LoadMusicStream("assets/musica/suspira.mp3");
    
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

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel[4];
                
                for(int i=0; i<4; i++){
                    botaoNivel[i].x=200;
                    botaoNivel[i].y=300+60*i;
                    botaoNivel[i].width=200;
                    botaoNivel[i].height=50;                  
                }
                for(int i=0; i<4; i++){

                    if(CheckCollisionRecs(botaoNivel[i], mouse)){

                        //DrawRectangle(50, 310+60*i, 500, 50, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                if(i==0)
                                currentScreen = GAMEPLAY;
                                if(i==1)
                                currentScreen = MANUAL1;
                                if(i==2)
                                currentScreen = CREDITO;
                                if(i==3)
                                currentScreen = ESCOLHER_NIVEL;
                            }
                    }

                }

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
                if (IsKeyPressed(KEY_H))
                {
                    currentScreen = ESCOLHER_NIVEL;
                }

            } break;
            case MENU: //MECANICAS DA TELA DE MENU
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel[3];
                
                for(int i=0; i<3; i++){
                    botaoNivel[i].x=200;
                    botaoNivel[i].y=322+60*i;
                    botaoNivel[i].width=200;
                    botaoNivel[i].height=60;                  
                }
                for(int i=0; i<3; i++){

                    if(CheckCollisionRecs(botaoNivel[i], mouse)){

                        //DrawRectangle(160, 300+60*i, 280, 60, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                if(i==0)
                                currentScreen = GAMEPLAY;
                                if(i==1)
                                currentScreen = MANUAL2;
                                if(i==2)
                                currentScreen = TITLE;
                            }
                    }

                }

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

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel = {200, 500, 200, 60};
                

                    if(CheckCollisionRecs(botaoNivel, mouse)){

                        //DrawRectangle(190, 490, 220, 70, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                currentScreen = TITLE;
                            }
                    }


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

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel = {200, 500, 200, 60};
                

                    if(CheckCollisionRecs(botaoNivel, mouse)){

                        //DrawRectangle(190, 490, 220, 70, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                currentScreen = MENU;
                            }
                    }

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

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel = {200, 500, 200, 60};
                

                    if(CheckCollisionRecs(botaoNivel, mouse)){

                        //DrawRectangle(190, 490, 220, 70, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                currentScreen = TITLE;
                            }
                    }

                if(IsKeyPressed(KEY_Q)){
                    currentScreen = TITLE;
                }
            } break;
            case ESCOLHER_NIVEL:{

                maximo = guarda_ler_nivel();

                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 6, 6};
                Rectangle botaoNivel[maximo];
                
                for(int i=1; i<=maximo; i++){
                    botaoNivel[i-1].x=280;
                    botaoNivel[i-1].y=80+35*i;
                    botaoNivel[i-1].width=50;
                    botaoNivel[i-1].height=20;                  
                }
                for(int i=1; i<=maximo; i++){

                    if(CheckCollisionRecs(botaoNivel[i-1], mouse)){
                        //DrawRectangle(280, 80+30*i, 50, 30, LIGHTGRAY);

                        sprintf(endereco, "%d", i);
                        //DrawText(endereco, 300, 90+40*i, 20, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                level=i;
                                mapa=mapa_rezetar(level);
                                POSICAO;
                                mapa_especial(&mapa);
                                currentScreen = GAMEPLAY;
                            }
                    }

                Rectangle botaoNivel2 = {400, 550, 200, 50};

                    if(CheckCollisionRecs(botaoNivel2, mouse)){

                        //DrawRectangle(190, 490, 220, 70, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                currentScreen = TITLE;
                            }
                    }
                }
                if (IsKeyPressed(KEY_Q))
                {
                    currentScreen = TITLE;
                }

            }break;

            case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
            {
                if(IsKeyPressed(KEY_M)){
                    currentScreen = MENU;
                }
                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel = {460, 560, 130, 30};

                    if(CheckCollisionRecs(botaoNivel, mouse)){

                        DrawRectangle(460, 560, 140, 40, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                currentScreen = MENU;
                            }
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
            case PARABENS:
            {
                DrawTextureRec(background,
                                (Rectangle){0,0, 600, 600},
                                (Vector2){0, 0},
                                WHITE);

                posicaoMouse.x=GetMouseX();
                posicaoMouse.y=GetMouseY();

                double p = GetScreenWidth()/(double)600;
                SetMouseScale((1/p), (1/p));
                mouse = (Rectangle) {(float) posicaoMouse.x, (float) posicaoMouse.y, 15, 15};

                Rectangle botaoNivel[2];
                
                for(int i=0; i<2; i++){
                    botaoNivel[i].x=200;
                    botaoNivel[i].y=322+60*i;
                    botaoNivel[i].width=200;
                    botaoNivel[i].height=60;                  
                }
                for(int i=0; i<2; i++){

                    if(CheckCollisionRecs(botaoNivel[i], mouse)){

                        //DrawRectangle(160, 300+60*i, 280, 60, BLACK);

                            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
                                if(i==0)
                                currentScreen = GAMEPLAY;
                                if(i==1)
                                currentScreen = TITLE;
                            }
                    }

                }

                if(IsKeyPressed(KEY_ENTER)){
                    currentScreen = GAMEPLAY;
                }
                if (IsKeyPressed(KEY_Q)){
                    currentScreen = TITLE;
                }
            }break;
            default:
                break;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        switch(currentScreen){
            case TITLE: //TELA DO TITULO DO GAME
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawText("SOKOBAN", 220, 125, 36, WHITE);
                DrawText("GASPARZINHO", 116, 170, 50, WHITE);               
                DrawRectangle(170, 300, 260, 40, LIGHTGRAY);
                DrawText("JOGAR [ENTER]", 226, 312, 20, BLACK);
                DrawRectangle(170, 360, 260, 40, LIGHTGRAY);
                DrawText("INSTRUÇÕES [I]", 224, 372, 20, BLACK);
                DrawRectangle(170, 420, 260, 40, LIGHTGRAY);
                DrawText("CRÉDITOS [C]", 235, 432, 20, BLACK);
                DrawRectangle(170, 480, 260, 40, LIGHTGRAY);
                DrawText("ESCOLHER NÍVEL [H]", 195, 492, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            } break;

            case MENU: //MECANICAS DA TELA DE MENU
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawText("JOGO PAUSADO", 120, 140, 45, WHITE);
                DrawRectangle(170, 310, 260, 40, LIGHTGRAY);
                DrawText("CONTINUAR [ENTER]", 196, 322, 20, BLACK);
                DrawRectangle(170, 370, 260, 40, LIGHTGRAY);
                DrawText("INSTRUÇÕES [I]", 224, 382, 20, BLACK);
                DrawRectangle(170, 430, 260, 40, LIGHTGRAY);
                DrawText("MENU PRINCIPAL [Q]", 197, 442, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            } break;

            case MANUAL1: //MECANICAS DA TELA DE MENU
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("COMO JOGAR:", 222, 100, 25, BLACK);
                DrawText("[W] - CIMA", 248, 160, 20, WHITE);
                DrawText("[A] - ESQUERDA", 225, 195, 20, WHITE);
                DrawText("[S] - BAIXO", 245, 230, 20, WHITE);
                DrawText("[D] - DIREITA", 230, 265, 20, WHITE);
                DrawText("[M] - MENU", 246, 300, 20, WHITE);
                DrawText("[Z] - VOLTAR JOGADA", 190, 335, 20, WHITE);
                DrawText("[C] - DESFAZER VOLTA DE JOGADA", 115, 370, 20, WHITE);
                DrawText("[X] - RESETAR NÍVEL", 195, 405, 20, WHITE);
                DrawRectangle(205, 492, 190, 35, LIGHTGRAY);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            } break;
            
            case MANUAL2: //MECANICAS DA TELA DE MENU
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("COMO JOGAR:", 222, 100, 25, BLACK);
                DrawText("[W] - CIMA", 248, 160, 20, WHITE);
                DrawText("[A] - ESQUERDA", 225, 195, 20, WHITE);
                DrawText("[S] - BAIXO", 245, 230, 20, WHITE);
                DrawText("[D] - DIREITA", 230, 265, 20, WHITE);
                DrawText("[M] - MENU", 246, 300, 20, WHITE);
                DrawText("[Z] - VOLTAR JOGADA", 190, 335, 20, WHITE);
                DrawText("[C] - DESFAZER VOLTA DE JOGADA", 115, 370, 20, WHITE);
                DrawText("[X] - RESETAR NÍVEL", 195, 405, 20, WHITE);
                DrawRectangle(205, 492, 190, 35, LIGHTGRAY);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            } break;

            case CREDITO: //MECANICAS DA TELA DE CREDITOS
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawRectangle(190, 90, 220, 40, LIGHTGRAY);
                DrawText("CRÉDITOS", 237, 100, 25, BLACK);
                DrawText("AUGUSTO NASCIMENTO", 178, 180, 20, WHITE);
                DrawText("[ano@cin.ufpe.br]", 218, 200, 20, WHITE);
                DrawText("EDENN WESLLEY", 215, 240, 20, WHITE);
                DrawText("[ewss@cin.ufpe.br]", 212, 260, 20, WHITE);
                DrawText("ENIO HENRIQUE", 220, 300, 20, WHITE);
                DrawText("[ehnr@cin.ufpe.br]", 212, 320, 20, WHITE);
                DrawText("GABRIEL WANDERLEY", 192, 360, 20, WHITE);
                DrawText("[gwcs@cin.ufpe.br]", 214, 380, 20, WHITE);
                DrawText("MARIA LETICIA", 223, 420, 20, WHITE);
                DrawText("[mlng@cin.ufpe.br]", 216, 440, 20, WHITE);
                DrawRectangle(205, 492, 190, 35, LIGHTGRAY);
                DrawText("VOLTAR [Q]", 245, 500, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            } break;

            case ESCOLHER_NIVEL:
            {
                UpdateMusicStream(abertura);
                PlayMusicStream(abertura);
                SetMusicVolume(abertura, 0.2);

                DrawRectangle(160, 50, 310, 40, LIGHTGRAY);
                DrawText("NIVEIS JA PASSADOS", 190, 60, 25, BLACK);
                for(int i=1; i<13; i++){
                    if(maximo>=i){
                        sprintf(endereco, "%d", i);
                        DrawText(endereco, 305, 80+35*i, 20, WHITE);
                    }
                } 
                DrawRectangle(420, 550, 170, 35, LIGHTGRAY);
                DrawText("VOLTAR [Q]", 450, 559, 20, BLACK);

            }break;

            case GAMEPLAY: //MECANICAS DA TELA DE GAMEPLAY
            {
                StopMusicStream(abertura);
                mapa_desenhando(flag, mapa, imagens, fundo, level);
                UpdateMusicStream(jogando);
                SetMusicVolume(jogando, 0.08);

                //TEXTO DE TESTE GAMEPLAY
                DrawRectangle(460, 560, 130, 30, LIGHTGRAY);
                DrawText("[M] - PAUSA", 475, 568, 18, BLACK);
            } break;
            case PARABENS:
            {
                DrawText("PARABUEINS!!", 120, 170, 55, WHITE);
                DrawText("VOCÊ CONSEGUIU!", 190, 130, 25, WHITE);
                if(Ultimo){
                DrawText("ACABOU COM TUDO,", 100, 268, 40, WHITE);
                DrawText("NINJA DO PÂNTANO!!", 10, 312, 55, WHITE);
                }
                else{
                DrawRectangle(173, 300, 260, 40, LIGHTGRAY);
                DrawText("CONTINUAR [ENTER]", 198, 312, 20, BLACK);
                }
                DrawRectangle(172, 360, 260, 40, LIGHTGRAY);
                DrawText("MENU PRINCIPAL [Q]", 202, 372, 20, BLACK);
                DrawText("Para sair do jogo pressione ESC", 161, 550, 18, WHITE);
            }break;
            default:
                break;
        }

        /*if(mapa_conseguiu()){
        
        }*/

        DrawFPS(0, 0);
        EndDrawing();

        if(mapa_conseguiu(mapa)){
            
            currentScreen = PARABENS;
            apagar_jogadas(level);

            if(level!=13){
                level++;
                Ultimo=0;
            }
            else{
                level=1;
                Ultimo=1;
            }
                guarda_salva_nivel(level);
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
    UnloadMusicStream(abertura);
    UnloadSound(conseguiu);
    mapa_Unload(&imagens, &fundo);
    UnloadTexture(background);  
    CloseWindow();

    fclose(arquivo);
    free(imagens);
    free(fundo);

    return 0;
}