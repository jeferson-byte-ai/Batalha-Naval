#include <stdio.h>

#define SIZE 5
#define SHIPS 3

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tabuleiro[i][j] = '-';
}

void posicionarNavios(int navios[SHIPS][2]) {
    // Posições fixas para simplificar
    navios[0][0] = 1; navios[0][1] = 2;
    navios[1][0] = 3; navios[1][1] = 4;
    navios[2][0] = 0; navios[2][1] = 0;
}

int verificarAcerto(int tiro[2], int navios[SHIPS][2]) {
    for (int i = 0; i < SHIPS; i++) {
        if (navios[i][0] == tiro[0] && navios[i][1] == tiro[1]) {
            // Marca como afundado
            navios[i][0] = navios[i][1] = -1;
            return 1;
        }
    }
    return 0;
}

void mostrarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[SIZE][SIZE];
    int navios[SHIPS][2];
    int tiro[2];
    int tentativas = 0;
    int acertos = 0;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(navios);

    printf("=== Batalha Naval ===\n");
    printf("Tamanho do tabuleiro: %dx%d\n", SIZE, SIZE);
    printf("Quantidade de navios: %d\n\n", SHIPS);

    while (acertos < SHIPS) {
        mostrarTabuleiro(tabuleiro);

        printf("Linha (0-%d): ", SIZE - 1);
        scanf("%d", &tiro[0]);

        printf("Coluna (0-%d): ", SIZE - 1);
        scanf("%d", &tiro[1]);

        tentativas++;

        if (verificarAcerto(tiro, navios)) {
            printf("Acertou um navio!\n");
            tabuleiro[tiro[0]][tiro[1]] = 'X';
            acertos++;
        } else {
            printf("Água...\n");
            tabuleiro[tiro[0]][tiro[1]] = 'O';
        }
    }

    printf("\nParabéns! Você afundou todos os navios em %d tentativas.\n", tentativas);
    mostrarTabuleiro(tabuleiro);

    return 0;
}
