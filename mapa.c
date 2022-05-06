#include "raylib.h"
#include "mapa.h"
#include <string.h>

#define QTD_QUADRADOS 12 
#define LARGURA 600
#define DIMENSAO LARGURA/QTD_QUADRADOS

void mapa_criando1(MAPA *mapa){

    strcpy( (*mapa).mapa[0], "############" );
    strcpy( (*mapa).mapa[1], "########@@P#" );
    strcpy( (*mapa).mapa[2], "########BB@#" );
    strcpy( (*mapa).mapa[3], "#+######@B@#" );
    strcpy( (*mapa).mapa[4], "#+######@###" );
    strcpy( (*mapa).mapa[5], "#+@@@@@@@###" );
    strcpy( (*mapa).mapa[6], "#@@###@@@@##" );
    strcpy( (*mapa).mapa[7], "######@@@@##" );
    strcpy( (*mapa).mapa[8], "############" );
    strcpy( (*mapa).mapa[9], "############" );
    strcpy( (*mapa).mapa[10], "############" );
    strcpy( (*mapa).mapa[11], "############" );

}

void mapa_criando2(MAPA *mapa){

    strcpy( (*mapa).mapa[0], "############" );
    strcpy( (*mapa).mapa[1], "########@@P#" );
    strcpy( (*mapa).mapa[2], "########BB@#" );
    strcpy( (*mapa).mapa[3], "#+######@B@#" );
    strcpy( (*mapa).mapa[4], "#+######@###" );
    strcpy( (*mapa).mapa[5], "#+@@@@@@@###" );
    strcpy( (*mapa).mapa[6], "#@@###@@@@##" );
    strcpy( (*mapa).mapa[7], "######@@@@##" );
    strcpy( (*mapa).mapa[8], "############" );
    strcpy( (*mapa).mapa[9], "############" );
    strcpy( (*mapa).mapa[10], "############" );
    strcpy( (*mapa).mapa[11], "############" );

}

void mapa_criando3(MAPA *mapa){

    strcpy( (*mapa).mapa[0], "############" );
    strcpy( (*mapa).mapa[1], "########@@P#" );
    strcpy( (*mapa).mapa[2], "########BB@#" );
    strcpy( (*mapa).mapa[3], "#+######@B@#" );
    strcpy( (*mapa).mapa[4], "#+######@###" );
    strcpy( (*mapa).mapa[5], "#+@@@@@@@###" );
    strcpy( (*mapa).mapa[6], "#@@###@@@@##" );
    strcpy( (*mapa).mapa[7], "######@@@@##" );
    strcpy( (*mapa).mapa[8], "############" );
    strcpy( (*mapa).mapa[9], "############" );
    strcpy( (*mapa).mapa[10], "############" );
    strcpy( (*mapa).mapa[11], "############" );

}

void mapa_criando4(MAPA *mapa){

    strcpy( (*mapa).mapa[0], "############" );
    strcpy( (*mapa).mapa[1], "########@@P#" );
    strcpy( (*mapa).mapa[2], "########BB@#" );
    strcpy( (*mapa).mapa[3], "#+######@B@#" );
    strcpy( (*mapa).mapa[4], "#+######@###" );
    strcpy( (*mapa).mapa[5], "#+@@@@@@@###" );
    strcpy( (*mapa).mapa[6], "#@@###@@@@##" );
    strcpy( (*mapa).mapa[7], "######@@@@##" );
    strcpy( (*mapa).mapa[8], "############" );
    strcpy( (*mapa).mapa[9], "############" );
    strcpy( (*mapa).mapa[10], "############" );
    strcpy( (*mapa).mapa[11], "############" );

}

void mapa_criando5(MAPA *mapa){

    strcpy( (*mapa).mapa[0], "############" );
    strcpy( (*mapa).mapa[1], "########@@P#" );
    strcpy( (*mapa).mapa[2], "########BB@#" );
    strcpy( (*mapa).mapa[3], "#+######@B@#" );
    strcpy( (*mapa).mapa[4], "#+######@###" );
    strcpy( (*mapa).mapa[5], "#+@@@@@@@###" );
    strcpy( (*mapa).mapa[6], "#@@###@@@@##" );
    strcpy( (*mapa).mapa[7], "######@@@@##" );
    strcpy( (*mapa).mapa[8], "############" );
    strcpy( (*mapa).mapa[9], "############" );
    strcpy( (*mapa).mapa[10], "############" );
    strcpy( (*mapa).mapa[11], "############" );

}


void mapa_especial(MAPA *mapa){//mapa vai ser global
    for(int i=0; i<QTD_QUADRADOS; i++){
        for(int j=0; j<QTD_QUADRADOS; j++){
            if((*mapa).mapa[i][j]=='+'){
            (*mapa).especial_inicio[i][j]=1;
            (*mapa).especial_atual[i][j]=1;
            }
            else{
            (*mapa).especial_inicio[i][j]=0;
            (*mapa).especial_atual[i][j]=0;
            }
        }
    }
}

int mapa_conseguiu(MAPA mapa){
    int contador=0;
    for(int i=0; i<QTD_QUADRADOS; i++){
        for(int k=0; k<QTD_QUADRADOS; k++){
            if(mapa.especial_atual[i][k]==1){
                contador++;
            }
        }
    }
    if(contador==0){
        return 1;
    }
    else{
        return 0;
    }
}

void mapa_desenhando(int gFlag, MAPA mapa, Quadrado peca){ //desenha os mapas

    peca.imagem = LoadTexture("assets/mapa/ultimo.png");
    peca.coordenada= (Vector2){0, 0};
    DrawTextureRec(  peca.imagem, 
                    (Rectangle) {0, 0, LARGURA, LARGURA}, 
                    peca.coordenada, 
                    WHITE);
                    
    for(int j=0; j<QTD_QUADRADOS; j++){
                for(int k=0; k<QTD_QUADRADOS; k++){
                    
                    if(mapa.mapa[j][k]=='P'){
                    
                    if(gFlag==0){peca.imagem = LoadTexture("assets/mapa/adicionado mapa/Layer 2_sprite_1.png");}
                    else if(gFlag==1){peca.imagem = LoadTexture("assets/mapa/adicionado mapa/Layer 2_sprite_7.png");}
                    else if(gFlag==2){peca.imagem = LoadTexture("assets/mapa/adicionado mapa/Layer 2_sprite_6.png");}
                    else if(gFlag==3){peca.imagem = LoadTexture("assets/mapa/adicionado mapa/Layer 2_sprite_2.png");}
                    else if(gFlag==4){peca.imagem = LoadTexture("assets/mapa/adicionado mapa/Layer 2_sprite_4.png");}
                    
                    peca.coordenada.x = k*DIMENSAO;
                    peca.coordenada.y = j*DIMENSAO;
                    
                    DrawTextureRec(
                            peca.imagem, 
                            (Rectangle) {0, 0, DIMENSAO, DIMENSAO}, 
                            peca.coordenada, 
                            WHITE);
                    }
                    
                    if(mapa.especial_atual[j][k]==1 && (mapa.mapa[j][k]=='@'||mapa.mapa[j][k]=='+')){
                                
                    peca.imagem = LoadTexture("assets/mapa/adicionado mapa/environment_08.png");
                
                    peca.coordenada = (Vector2) {
                        k*(DIMENSAO),
                        j*(DIMENSAO)
                    };
                    
                    DrawTextureRec(
                            peca.imagem, 
                            (Rectangle) {0, 0, DIMENSAO, DIMENSAO}, 
                            peca.coordenada, 
                            WHITE);
                    }
                    
                    
                    if(mapa.mapa[j][k]=='B'){ //box
                    peca.imagem = LoadTexture("assets/mapa/adicionado mapa/crate_12.png");
                    
                    peca.coordenada = (Vector2) {
                        k*(DIMENSAO),
                        j*(DIMENSAO)
                    };
                    
                    DrawTextureRec(
                            peca.imagem, 
                            (Rectangle) {0, 0, DIMENSAO, DIMENSAO}, 
                            peca.coordenada, 
                    WHITE);
                    }

                }
                
    }

}

