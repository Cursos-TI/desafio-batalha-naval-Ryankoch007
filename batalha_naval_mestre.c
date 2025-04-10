#include <stdio.h>

int main() {
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int i, j;

    // Cria o tabuleiro com água (0)
    int tabuleiro[10][10];
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca navios (valor 3)
    for (j = 3; j < 6; j++) tabuleiro[2][j] = 3; // horizontal
    for (i = 0; i < 3; i++) tabuleiro[7 + i][2 + i] = 3; // diagonal ↘
    for (i = 0; i < 3; i++) tabuleiro[1 + i][7 - i] = 3; // diagonal ↙
    for (i = 5; i < 8; i++) tabuleiro[i][7] = 3; // vertical

    // Matrizes das habilidades (cone, cruz, octaedro)
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    // Aplica habilidade CONE no centro (4,4)
    int origem_linha = 4;
    int origem_coluna = 4;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origem_linha + i - 2;
            int coluna = origem_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Aplica habilidade CRUZ no canto superior esquerdo (1,1)
    origem_linha = 1;
    origem_coluna = 1;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origem_linha + i - 2;
            int coluna = origem_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Aplica habilidade OCTAEDRO no canto inferior direito (8,8)
    origem_linha = 8;
    origem_coluna = 8;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origem_linha + i - 2;
            int coluna = origem_coluna + j - 2;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    // Exibe o tabuleiro
    printf("TABULEIRO - BATALHA NAVAL (HABILIDADES SEM FUNÇÃO)\n");
    printf("Legenda: . = Água, 3 = Navio, 5 = Área de Habilidade\n\n");

    printf("   ");
    for (j = 0; j < 10; j++) printf("%c ", coluna[j]);
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d ", i+1);
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}
