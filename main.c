#include "raylib.h"
#include "player.h"

int main(void)
{
    InitWindow(800, 600, "Gasparzinho");
    SetTargetFPS(60);
    player_create(); // instancia o jogador antes de entrar no Loop

    
    while (!WindowShouldClose()) {
        // Game loop
        player_update(); // movimentos, itens, pontuação...

        BeginDrawing();
            ClearBackground(BLACK);

            player_draw();

        DrawFPS(0, 0);
    EndDrawing();
    }

    player_destroy();
    CloseWindow();

    return 0;
}