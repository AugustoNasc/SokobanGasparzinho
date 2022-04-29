#include "raylib.h"
#include "player.h"

int main(void)
{
    InitWindow(800, 600, "Gasparzinho");
    SetTargetFPS(60);
    player_criado(); // instancia o jogador antes de entrar no Loop

    
    while (!WindowShouldClose()) {
        // Game loop
        player_move(); // movimentos, itens, pontuação...

        BeginDrawing();
            ClearBackground(BLACK);

            player_desenhado();

        DrawFPS(0, 0);
    EndDrawing();
    }

    player_free();
    CloseWindow();

    return 0;
}