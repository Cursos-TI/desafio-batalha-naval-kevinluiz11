#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com água (0)
        }
    }
}

void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = -i; j <= i; j++) {
            int x = origemX + i;
            int y = origemY + j;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                tabuleiro[x][y] = 5; // Marca a área de efeito da habilidade
            }
        }
    }
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = -TAMANHO_HABILIDADE / 2; i <= TAMANHO_HABILIDADE / 2; i++) {
        int x = origemX + i;
        int y = origemY;
        if (x >= 0 && x < TAMANHO_TABULEIRO) {
            tabuleiro[x][y] = 5;
        }
        x = origemX;
        y = origemY + i;
        if (y >= 0 && y < TAMANHO_TABULEIRO) {
            tabuleiro[x][y] = 5;
        }
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemX, int origemY) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = -i; j <= i; j++) {
            int x = origemX + i;
            int y = origemY + j;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                tabuleiro[x][y] = 5;
            }
            x = origemX - i;
            if (x >= 0 && x < TAMANHO_TABULEIRO) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 2, 5);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 5);

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
