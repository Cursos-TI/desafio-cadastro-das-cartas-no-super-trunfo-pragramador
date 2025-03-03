#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[20];
    char codigo[10];
    char nome_cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

int main() {
    // Definição das duas cartas
    Carta carta1 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6718903, 1200.27, 364000000000, 15};
    Carta carta2 = {"Bahia", "BA01", "Salvador", 2886698, 693.83, 140000000000, 10};
    
    // Cálculo dos atributos derivados
    float densidade1 = calcular_densidade(carta1.populacao, carta1.area);
    float densidade2 = calcular_densidade(carta2.populacao, carta2.area);
    
    float pib_per_capita1 = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    float pib_per_capita2 = calcular_pib_per_capita(carta2.pib, carta2.populacao);
    
    // Escolha do atributo a ser comparado (definido diretamente no código)
    char atributo_usado[] = "População"; // Modifique aqui para testar outros atributos
    int valor1 = carta1.populacao;
    int valor2 = carta2.populacao;
    
    // Determinação do vencedor
    printf("Comparação de cartas (Atributo: %s):\n\n", atributo_usado);
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %d\n\n", carta2.nome_cidade, carta2.estado, valor2);
    
    if (valor1 > valor2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (valor2 > valor1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
    
    return 0;
}

