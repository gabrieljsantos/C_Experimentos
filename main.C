#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>

// Função para desenhar círculo preenchido
void draw_filled_circle(SDL_Renderer* renderer, float cx, float cy, float radius) {
    for (int y = (int)-radius; y <= (int)radius; y++) {
        int dx = (int)sqrt(radius * radius - y * y);
        SDL_RenderDrawLine(renderer, cx - dx, cy + y, cx + dx, cy + y);
    }
}

int main(int argc, char* argv[]) {
    // Inicializa SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Cria a janela
    SDL_Window* window = SDL_CreateWindow("SDL3 Exemplo", 800, 600, 0);
    if (!window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria o renderer (SDL3)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, "SDL3 Renderer");
    if (!renderer) {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Limpa a tela com preto
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Desenha um retângulo verde (objeto)
    SDL_FRect object = {200.0f, 150.0f, 100.0f, 50.0f};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &object);

    // Desenha um círculo vermelho preenchido
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    draw_filled_circle(renderer, 500.0f, 300.0f, 75.0f);

    // Aplica as alterações na tela
    SDL_RenderPresent(renderer);

    // Loop de eventos simples
    SDL_Event e;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }
    }

    // Limpeza
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
