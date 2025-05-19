#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAM 5
#define NAVIOS 3

void inicializar_tabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~'; // água
}

void posicionar_navios(char tabuleiro[TAM][TAM]) {
    int navios_posicionados = 0;
    while (navios_posicionados < NAVIOS) {
        int x = rand() % TAM;
        int y = rand() % TAM;
        if (tabuleiro[x][y] != 'N') {
            tabuleiro[x][y] = 'N';
            navios_posicionados++;
        }
    }
}

void mostrar_tabuleiro(char tabuleiro[TAM][TAM], int ocultar_navios) {
    printf("  A B C D E\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (ocultar_navios && tabuleiro[i][j] == 'N')
                printf("~ ");
            else
                printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int converter_coluna(char letra) {
    letra = toupper(letra);
    return letra - 'A';
}

int main() {
    char tabuleiro[TAM][TAM];
    int acertos = 0, tentativas = 0;
    char coluna_char;
    int linha;

    srand(time(NULL));
    inicializar_tabuleiro(tabuleiro);
    posicionar_navios(tabuleiro);

    printf("=== BATALHA NAVAL ===\n");
    printf("Tabuleiro 5x5 com %d navios escondidos\n\n", NAVIOS);

    while (acertos < NAVIOS) {
        mostrar_tabuleiro(tabuleiro, 1);

        printf("\nDigite sua jogada (ex: B3): ");
        scanf(" %c%d", &coluna_char, &linha);

        int col = converter_coluna(coluna_char);
        int lin = linha - 1;

        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tentativas++;

        if (tabuleiro[lin][col] == 'N') {
            printf("💥 ACERTOU o navio!\n");
            tabuleiro[lin][col] = 'X';
            acertos++;
        } else if (tabuleiro[lin][col] == 'X' || tabuleiro[lin][col] == 'O') {
            printf("Você já atirou aqui!\n");
        } else {
            printf("🌊 Água...\n");
            tabuleiro[lin][col] = 'O';
        }
    }

    printf("\n🎉 PARABÉNS! Você afundou todos os navios em %d tentativas.\n", tentativas);
    mostrar_tabuleiro(tabuleiro, 0);

    return 0;
}
