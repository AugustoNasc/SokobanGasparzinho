#include <SFML/Graphics.hpp>
#include <string>
#include "mapa.hpp"
#include "voltajogada.hpp"

#define QTD_QUADRADOS 12
#define LARGURA 600
#define DIMENSAO LARGURA/QTD_QUADRADOS
#define PINTAR(parametro) (parametro).coordenada.x = k*DIMENSAO; \
                          (parametro).coordenada.y = j*DIMENSAO; \
                          \
                          if(gFlag==1){ (parametro).coordenada.x-=15; } \
                          if(gFlag==2){ (parametro).coordenada.x+=6; } \
                          \
                          sprite.setTexture((parametro).imagem); \
                          sprite.setTextureRect(sf::IntRect(0, 0, DIMENSAO, DIMENSAO)); \
                          sprite.setPosition((parametro).coordenada.x, (parametro).coordenada.y); \
                          window.draw(sprite);

void mapa_especial(MAPA *mapa) {
    for(int i=0; i<QTD_QUADRADOS; i++) {
        for(int j=0; j<QTD_QUADRADOS; j++) {
            if((*mapa).mapa[i][j]=='+') {
                (*mapa).especial_inicio[i][j]=1;
                (*mapa).especial_atual[i][j]=1;
            } else {
                (*mapa).especial_inicio[i][j]=0;
                (*mapa).especial_atual[i][j]=0;
            }
        }
    }
}

int mapa_conseguiu(MAPA mapa) {
    int contador=0;
    for(int i=0; i<QTD_QUADRADOS; i++) {
        for(int k=0; k<QTD_QUADRADOS; k++) {
            if(mapa.especial_atual[i][k]==1) {
                contador++;
            }
        }
    }
    if(contador==0) {
        return 1;
    } else {
        return 0;
    }
}

void mapa_declararpng(Quadrado **imagens) {
    (*imagens)[0].imagem.loadFromFile("assets/mapa/adicionado mapa/crate_12.png"); //box
    (*imagens)[1].imagem.loadFromFile("assets/mapa/adicionado mapa/Layer 2_sprite_1.png"); //p
    (*imagens)[2].imagem.loadFromFile("assets/mapa/adicionado mapa/Layer 2_sprite_5.png"); //pa
    (*imagens)[3].imagem.loadFromFile("assets/mapa/adicionado mapa/Layer 2_sprite_6.png"); //pd
    (*imagens)[4].imagem.loadFromFile("assets/mapa/adicionado mapa/Layer 2_sprite_2.png"); //ps
    (*imagens)[5].imagem.loadFromFile("assets/mapa/adicionado mapa/Layer 2_sprite_4.png"); //pw
}

void mapa_fundo(Quadrado **fundo) {
    char endereco[50];

    for(int level=1; level<=13; level++) {
        sprintf(endereco, "assets/mapa/mapa%d.png", level);
        (*fundo)[level-1].imagem.loadFromFile(endereco);
    }
}

void mapa_desenhando(int gFlag, MAPA mapa, Quadrado *imagens, Quadrado *fundo, int level, sf::RenderWindow &window) {
    sf::Sprite sprite;

    (fundo[level-1]).coordenada = sf::Vector2f(0, 0);
    sprite.setTexture((fundo[level-1]).imagem);
    sprite.setTextureRect(sf::IntRect(0, 0, LARGURA, LARGURA));
    sprite.setPosition((fundo[level-1]).coordenada.x, (fundo[level-1]).coordenada.y);
    window.draw(sprite);

    for(int j=0; j<QTD_QUADRADOS; j++) {
        for(int k=0; k<QTD_QUADRADOS; k++) {
            if(mapa.mapa[j][k]=='P') {
                if(gFlag==0) {
                    PINTAR(imagens[1]);
                } else if(gFlag==1) {
                    PINTAR(imagens[2]);
                } else if(gFlag==2) {
                    PINTAR(imagens[3]);
                } else if(gFlag==3) {
                    PINTAR(imagens[4]);
                } else if(gFlag==4) {
                    PINTAR(imagens[5]);
                }
            }

            if(mapa.mapa[j][k]=='B') { //box
                (imagens[0]).coordenada = sf::Vector2f(k*(DIMENSAO)+3, j*(DIMENSAO)+3);
                sprite.setTexture((imagens[0]).imagem);
                sprite.setTextureRect(sf::IntRect(0, 0, DIMENSAO-7, DIMENSAO-7));
                sprite.setPosition((imagens[0]).coordenada.x, (imagens[0]).coordenada.y);
                window.draw(sprite);
            }
        }
    }
}

MAPA mapa_rezetar(int level) {
    char endereco[50];
    MAPA mapinha;
    FILE *arquivo;
    apagar_jogadas(level);
    sprintf(endereco, "mapastxt/mapa%d.txt", level);
    arquivo = fopen(endereco, "rt");
    fread(mapinha.mapa, sizeof(char), 12*13, arquivo);
    mapa_especial(&mapinha);
    fclose(arquivo);
    return mapinha;
}