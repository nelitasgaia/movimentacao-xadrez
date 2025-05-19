#include <stdio.h>
#include <string.h>
#include <ctype.h>

int posicao_valida(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void mostrar_posicao(int x, int y) {
    printf("%c%d ", 'A' + x, y + 1);
}

int main() {
    char peca[20];
    char coluna_char;
    int linha, x, y;

    printf("Digite a peça (rei, rainha, torre, bispo, cavalo ou peao): ");
    scanf("%s", peca);

    printf("Digite a posição atual (ex: D5): ");
    scanf(" %c%d", &coluna_char, &linha);

    x = toupper(coluna_char) - 'A';
    y = linha - 1;

    printf("\nMovimentos possíveis:\n");

    if (strcmp(peca, "rei") == 0) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                if (posicao_valida(x + dx, y + dy))
                    mostrar_posicao(x + dx, y + dy);
            }
        }
    } else if (strcmp(peca, "rainha") == 0) {
        for (int i = 1; i < 8; i++) {
            if (posicao_valida(x + i, y)) mostrar_posicao(x + i, y);
            if (posicao_valida(x - i, y)) mostrar_posicao(x - i, y);
            if (posicao_valida(x, y + i)) mostrar_posicao(x, y + i);
            if (posicao_valida(x, y - i)) mostrar_posicao(x, y - i);
            if (posicao_valida(x + i, y + i)) mostrar_posicao(x + i, y + i);
            if (posicao_valida(x - i, y - i)) mostrar_posicao(x - i, y - i);
            if (posicao_valida(x + i, y - i)) mostrar_posicao(x + i, y - i);
            if (posicao_valida(x - i, y + i)) mostrar_posicao(x - i, y + i);
        }
    } else if (strcmp(peca, "torre") == 0) {
        for (int i = 0; i < 8; i++) {
            if (i != y) mostrar_posicao(x, i);
            if (i != x) mostrar_posicao(i, y);
        }
    } else if (strcmp(peca, "bispo") == 0) {
        for (int i = 1; i < 8; i++) {
            if (posicao_valida(x + i, y + i)) mostrar_posicao(x + i, y + i);
            if (posicao_valida(x - i, y - i)) mostrar_posicao(x - i, y - i);
            if (posicao_valida(x + i, y - i)) mostrar_posicao(x + i, y - i);
            if (posicao_valida(x - i, y + i)) mostrar_posicao(x - i, y + i);
        }
    } else if (strcmp(peca, "cavalo") == 0) {
        int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
        for (int i = 0; i < 8; i++) {
            if (posicao_valida(x + dx[i], y + dy[i]))
                mostrar_posicao(x + dx[i], y + dy[i]);
        }
    } else if (strcmp(peca, "peao") == 0) {
        if (posicao_valida(x, y + 1)) mostrar_posicao(x, y + 1);
        if (y == 1 && posicao_valida(x, y + 2)) mostrar_posicao(x, y + 2);
    } else {
        printf("Peça inválida.\n");
    }

    printf("\n");
    return 0;
}
