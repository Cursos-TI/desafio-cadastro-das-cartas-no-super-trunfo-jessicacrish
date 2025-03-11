#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char nome[50]; 
    unsigned long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular atributos derivados
void calcularAtributos(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }

    // Cálculo do Super Poder (soma de todos os atributos com pesos)
    carta->super_poder = carta->populacao * 0.5 + carta->area * 2.0 + carta->pib * 1.5 +
                         carta->pontos_turisticos * 3.0 + carta->pib_per_capita * 2.0 -
                         (carta->densidade_populacional > 0 ? (1.0 / (carta->densidade_populacional + 1)) : 0);
}

// Função para comparar dois valores e determinar o vencedor
int compararAtributo(float valor1, float valor2, int menorVence) {
    if (valor1 == valor2) return -1; // Empate
    return (menorVence ? (valor1 < valor2 ? 1 : 2) : (valor1 > valor2 ? 1 : 2));
}

int main() {
    // Definição de cartas com valores fixos
    Carta carta1 = {"São Paulo", 11900000, 1521.11, 699.28, 50, 0, 0, 0};
    Carta carta2 = {"Bahia", 14850513, 564733.18, 304.72, 30, 0, 0, 0};

    // Calculando atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    // Comparação das cartas
    printf("\nComparação de Cartas:\n");

    char *atributos[] = {"População", "Área", "PIB", "Pontos Turísticos", "Densidade Populacional", "PIB per Capita", "Super Poder"};
    float valores1[] = {carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos, carta1.densidade_populacional, carta1.pib_per_capita, carta1.super_poder};
    float valores2[] = {carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos, carta2.densidade_populacional, carta2.pib_per_capita, carta2.super_poder};
    int menorVence[] = {0, 0, 0, 0, 1, 0, 0}; // Apenas densidade populacional vence com menor valor

    int vitoriasCarta1 = 0, vitoriasCarta2 = 0;

    for (int i = 0; i < 7; i++) {
        int vencedor = compararAtributo(valores1[i], valores2[i], menorVence[i]);
        if (vencedor == 1) vitoriasCarta1++;
        else if (vencedor == 2) vitoriasCarta2++;

        if (vencedor == -1) {
            printf("%s: Empate\n", atributos[i]);
        } else {
            printf("%s: Carta %d venceu\n", atributos[i], vencedor);
        }
    }

    // Determinar vencedor geral
    printf("\nResultado Final:\n");
    if (vitoriasCarta1 > vitoriasCarta2) {
        printf("A carta '%s' venceu com %d atributos contra %d da carta '%s'.\n", carta1.nome, vitoriasCarta1, vitoriasCarta2, carta2.nome);
    } else if (vitoriasCarta2 > vitoriasCarta1) {
        printf("A carta '%s' venceu com %d atributos contra %d da carta '%s'.\n", carta2.nome, vitoriasCarta2, vitoriasCarta1, carta1.nome);
    } else {
        printf("O jogo terminou empatado, cada carta venceu %d atributos!\n", vitoriasCarta1);
    }
    
    return 0;
}
