#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Movimento das peças de xadrez
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    printf("\nMovimento do Bispo:\n");
    int j = 1;
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    printf("\nMovimento da Rainha:\n");
    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    printf("\n=============================\n");
    printf("Posicionando Navios no Tabuleiro\n");
    printf("=============================\n\n");

    // 2. Inicialização do tabuleiro 10x10 com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 3. Navios representados como vetores (valor 3)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // 4. Coordenadas iniciais (linha, coluna) definidas no código
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    // 5. Validação de limites
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // 6. Verificação de sobreposição simples
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 3 ||
                tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // 7. Posicionando o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }

            // 8. Posicionando o navio vertical no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }

            // 9. Exibição do tabuleiro
            printf("Tabuleiro (0 = água, 3 = navio):\n\n");
            for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
                for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: Os navios se sobrepõem. Altere as coordenadas.\n");
        }
    } else {
        printf("Erro: Coordenadas inválidas. Os navios ultrapassam os limites do tabuleiro.\n");
    }

    return 0;
}
