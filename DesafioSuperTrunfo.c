#include <stdio.h>

// Estrutura para armazenar as propriedades de uma carta
typedef struct {
    char codigo[4];       // Código da carta (ex: A01, B02)
    int populacao;        // População da cidade
    float area;           // Área da cidade
    float pib;            // PIB da cidade
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

int main() {
    Carta cartas[8][4]; // 8 estados (A-H), 4 cidades por estado
    char estados[] = "ABCDEFGH";

    // Cadastro das cartas
    printf("Bem-vindo ao cadastro de cartas do Super Trunfo - Países!\n\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            // Gerar código da carta
            snprintf(cartas[i][j].codigo, 4, "%c%02d", estados[i], j + 1);

            // Entrada dos dados
            printf("Cadastro da carta %s:\n", cartas[i][j].codigo);
            printf("População: ");
            scanf("%d", &cartas[i][j].populacao);
            printf("Área (km²): ");
            scanf("%f", &cartas[i][j].area);
            printf("PIB (em milhões): ");
            scanf("%f", &cartas[i][j].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);
            printf("\n");
        }
    }

    // Exibição dos dados cadastrados
    printf("\n--- Cartas Cadastradas ---\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Carta %s:\n", cartas[i][j].codigo);
            printf("  População: %d\n", cartas[i][j].populacao);
            printf("  Área: %.2f km²\n", cartas[i][j].area);
            printf("  PIB: %.2f milhões\n", cartas[i][j].pib);
            printf("  Pontos turísticos: %d\n", cartas[i][j].pontos_turisticos);
            printf("\n");
        }
    }

    return 0;
}