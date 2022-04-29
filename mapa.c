#define QTD_QUADRADOS 12 
#define LARGURA 600
#define DIMENSAO LARGURA/QTD_QUADRADOS

Quadrado peca;


char **mapa_caractere(int level){ 
    if(level ==1){
        char mapa_caractere[QTD_QUADRADOS][QTD_QUADRADOS+1]={
                "############",
                "########@@@#",
                "########BB@#",
                "#+######@B@#",
                "#+######@###",
                "#+@@@@@@@###",
                "#@@###@@@@##",
                "######@@@@##",
        }

        return mapa_caractere;
    }
    //...


}


void mapa_desenhando(char **mapa){ //desenha os mapas

    for(int j=0; j<QTD_QUADRADOS; j++){
        for(int k=0; k<QTD_QUADRADOS; k++){

                if(tab[j][k]=='#'){
                peca.imagem = LoadTexture(" ");}
                
                if(tab[j][k]=='P'){
                peca.imagem = LoadTexture(" ");}
                
                if(tab[j][k]=='@'){
                peca.imagem = LoadTexture(" ");}
                
                if(tab[j][k]=='+'){
                peca.imagem = LoadTexture(" ");}
                
                if(tab[j][k]=='B'){
                peca.imagem = LoadTexture(" ");}
                
                peca.coordenada = (Vector2) {
                    k*(DIMENSAO),
                    j*(DIMENSAO),
                };
                
                DrawTextureRec(
                        peca.imagem, 
                        (Rectangle) {0, 0, DIMENSAO, DIMENSAO}, 
                        peca.coordenada, 
                        WHITE);

        }
    }
}