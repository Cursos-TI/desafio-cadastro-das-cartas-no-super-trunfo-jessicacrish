#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade populacional e PIB per capita
void calcular_dados(Carta *c) {
    if (c->area > 0) {
        c->densidade_populacional = c->populacao / c->area;
    } else {
        c->densidade_populacional = 0;
    }

    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / c->populacao;
    } else {
        c->pib_per_capita = 0;
    }
}

// Função para exibir os dados da carta de forma mais legível
void exibir_carta(Carta c) {
    printf("Estado: %-15s | Código: %-5s | Nome: %-20s\n", c.estado, c.codigo, c.nome);
    printf("População: %-12d | Área: %-8.2f | PIB: %-10.2f\n", c.populacao, c.area, c.pib);
    printf("Pontos turísticos: %-2d | Densidade populacional: %-8.2f | PIB per capita: %-10.2f\n\n",
           c.pontos_turisticos, c.densidade_populacional, c.pib_per_capita);
}

// Função para comparar as cartas com base em um atributo
void comparar_cartas(Carta c1, Carta c2, char atributo[]) {
    float valor1, valor2;

    // Seleciona o valor do atributo a ser comparado
    if (strcmp(atributo, "populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "densidade") == 0) {
        valor1 = c1.densidade_populacional;
        valor2 = c2.densidade_populacional;
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
    } else {
        printf("Atributo inválido.\n");
        return;
    }

    // Exibe as cartas antes da comparação
    printf("\nDados da Carta 1:\n");
    exibir_carta(c1);
    printf("Dados da Carta 2:\n");
    exibir_carta(c2);

    // Exibe a comparação
    printf("Comparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);

    // Lógica de decisão para determinar a carta vencedora
    if ((strcmp(atributo, "densidade") == 0 && valor1 < valor2) ||
        (strcmp(atributo, "densidade") != 0 && valor1 > valor2)) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (valor1 == valor2) {
        printf("\nResultado: Empate!\n");
    } else {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nome);
    }
}

// Função para normalizar a entrada do atributo
void normalizar_entrada(char *atributo) {
    for (int i = 0; atributo[i]; i++) {
        atributo[i] = tolower(atributo[i]);
    }
}

int main() {
    // Definindo duas cartas
    Carta carta1 = {"SP", "C1", "São Paulo", 119000000, 248.90, 920833, 36};
    Carta carta2 = {"BA", "C2", "Bahia", 14850513, 56729, 1144, 13};

    // Calculando densidade populacional e PIB per capita
    calcular_dados(&carta1);
    calcular_dados(&carta2);

    // Atributo fixo para comparação
    char atributo[] = "populacao";

    // Comparar com base no atributo escolhido
    comparar_cartas(carta1, carta2, atributo);

    return 0;
}
