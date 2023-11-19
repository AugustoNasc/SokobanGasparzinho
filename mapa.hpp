#ifndef MAPA_HPP
#define MAPA_HPP

#include <SFML/Graphics.hpp>

struct Quadrado {
    sf::Texture imagem;
    sf::Vector2f coordenada;
};

struct MAPA {
    char mapa[12][13];
    int especial_inicio[12][12];
    int especial_atual[12][12];
};

void mapa_especial(MAPA* mapa);
int mapa_conseguiu(MAPA mapa);
void mapa_desenhando(int gFlag, MAPA mapa, Quadrado* imagens, Quadrado* fundo, int level, sf::RenderWindow& window);
void mapa_declararpng(Quadrado** imagens);
void mapa_fundo(Quadrado** fundo);
MAPA mapa_rezetar(int level);

#endif