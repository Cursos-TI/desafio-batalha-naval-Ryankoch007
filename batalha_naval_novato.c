#include <stdio.h> 
int main () {

    char coluna[10] = {'A','B','C','D','E','F','D','E','F','G','H','I','J'};
    int i , j;
    int tabuleiro[10][10];

    //Inicializa o tabuleiro com 0 (agua)
for (int i = 0; i < 10; i++)
{
    for (int j = 0; j < 10; j++)
    {
     tabuleiro[i][j] = 0;
    }
    
}

//Navio Horizontal (linha2, coluna 3 , tamanho 3)
for (int j = 3; j < 6; j++)
{
    tabuleiro[2][j] = 3; //Preenche com 3 (navio)
}

// Navio Vertical (linha 5 , coluna 7 , tamanho 3)
for ( int i = 5; i < 8; i++)
{
    tabuleiro[i][7] = 3; //Preenche com 3 (navio)
}

//Exibe as letras das colunas (A B C D E F G H I J)
printf("   ");
for ( j = 0; j < 10; j++)
{
    printf("%c ", coluna[j]);
}
printf("\n");

// Exibe o tabuleiro com números nas linhas
for (i = 0; i < 10; i++) {
    printf("%2d ", i+1); // Números das linhas (1-10)
    for (j = 0; j < 10; j++) {
        if (tabuleiro[i][j] == 0) {
            printf(". "); // Água
        } else {
            printf("3 "); // Navio
        }
    }
    printf("\n");
}

    return 0;
}