#include <stdio.h>

#define NUM_PAISES 2
#define NUM_ATRIBUTOS 4

// Estrutura para armazenar informações de um país
typedef struct {
    char sigla[3];            // Sigla do país
    char codigo[3];           // Código da carta
    char nome[50];            // Nome do país
    int populacao;            // População
    float area;               // Área em km²
    int pib;                  // PIB em bilhões de dólares
    int densidadeDemografica; // Densidade demográfica (habitantes por km²)
} Carta;

// Função para exibir o menu de escolha de atributos
void exibirMenuAtributos() {
    printf("Escolha um atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Demográfica\n");
}

// Função para comparar dois atributos entre as cartas
int compararAtributos(int atributo, Carta carta1, Carta carta2, float *soma1, float *soma2) {
    float resultado1 = 0, resultado2 = 0;

    switch (atributo) {
        case 1:  // População
            resultado1 = carta1.populacao;
            resultado2 = carta2.populacao;
            break;
        case 2:  // Área
            resultado1 = carta1.area;
            resultado2 = carta2.area;
            break;
        case 3:  // PIB
            resultado1 = carta1.pib;
            resultado2 = carta2.pib;
            break;
        case 4:  // Densidade Demográfica
            resultado1 = carta1.densidadeDemografica;
            resultado2 = carta2.densidadeDemografica;
            break;
        default:
            printf("Opção inválida!\n");
            return 0; // Retorno de erro
    }

    // Se o atributo for Densidade Demográfica, vence a menor densidade
    if ((atributo != 4 && resultado1 > resultado2) || (atributo == 4 && resultado1 < resultado2)) {
        *soma1 += resultado1;
        *soma2 += resultado2;
        return 1;
    } else if ((atributo != 4 && resultado1 < resultado2) || (atributo == 4 && resultado1 > resultado2)) {
        *soma1 += resultado1;
        *soma2 += resultado2;
        return -1;
    } else {
        *soma1 += resultado1;
        *soma2 += resultado2;
        return 0; // Empate
    }
}

// Função para verificar se a entrada é válida (entre 1 e 4)
int obterAtributoValido() {
    int atributo;
    do {
        printf("Digite um número entre 1 e 4 para escolher o atributo: ");
        if (scanf("%d", &atributo) != 1) { // Verifica se a entrada é um número
            while (getchar() != '\n'); // Limpa o buffer
            printf("Entrada inválida! Tente novamente.\n");
        }
        else if (atributo < 1 || atributo > 4) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo < 1 || atributo > 4);
    return atributo;
}

// Função para exibir as informações das cartas
void exibirCarta(Carta carta) {
    printf("\n--- Informações da Carta ---\n");
    printf("Nome: %s\n", carta.nome);
    printf("Sigla: %s\n", carta.sigla);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %d bilhões\n", carta.pib);
    printf("Densidade Demográfica: %d habitantes/km²\n", carta.densidadeDemografica);
}

// Função para mostrar os resultados da comparação
void mostrarResultado(Carta carta1, Carta carta2, int atributo1, int atributo2, float soma1, float soma2) {
    printf("\n--- Resultado da Comparação ---\n");
    printf("Comparando %s (%s) e %s (%s)\n", carta1.nome, carta1.sigla, carta2.nome, carta2.sigla);
    
    // Atributos escolhidos
    printf("\nAtributos escolhidos para a comparação:\n");
    if (atributo1 == 1) {
        printf("1. População\n");
    } else if (atributo1 == 2) {
        printf("1. Área\n");
    } else if (atributo1 == 3) {
        printf("1. PIB\n");
    } else if (atributo1 == 4) {
        printf("1. Densidade Demográfica\n");
    }

    if (atributo2 == 1) {
        printf("2. População\n");
    } else if (atributo2 == 2) {
        printf("2. Área\n");
    } else if (atributo2 == 3) {
        printf("2. PIB\n");
    } else if (atributo2 == 4) {
        printf("2. Densidade Demográfica\n");
    }

    // Exibição dos valores de cada atributo
    printf("\nValores de cada atributo:\n");
    if (atributo1 == 1) {
        printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
    } else if (atributo1 == 2) {
        printf("Área: %.2f km² vs %.2f km²\n", carta1.area, carta2.area);
    } else if (atributo1 == 3) {
        printf("PIB: %d bilhões vs %d bilhões\n", carta1.pib, carta2.pib);
    } else if (atributo1 == 4) {
        printf("Densidade Demográfica: %d vs %d\n", carta1.densidadeDemografica, carta2.densidadeDemografica);
    }

    if (atributo2 == 1) {
        printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
    } else if (atributo2 == 2) {
        printf("Área: %.2f km² vs %.2f km²\n", carta1.area, carta2.area);
    } else if (atributo2 == 3) {
        printf("PIB: %d bilhões vs %d bilhões\n", carta1.pib, carta2.pib);
    } else if (atributo2 == 4) {
        printf("Densidade Demográfica: %d vs %d\n", carta1.densidadeDemografica, carta2.densidadeDemografica);
    }

    // Exibição da soma dos atributos
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    // Determinando o vencedor
    if (soma1 > soma2) {
        printf("\n%s venceu!\n", carta1.nome);
    } else if (soma1 < soma2) {
        printf("\n%s venceu!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

// Função principal
int main() {
    Carta carta1 = {"SP", "C1", "São Paulo", 119000000, 248.90, 920833, 36}; // Dados de São Paulo
    Carta carta2 = {"BA", "C2", "Bahia", 14850513, 56729, 1144, 13};        // Dados da Bahia

    int atributo1, atributo2;
    float soma1 = 0, soma2 = 0;
    int resultado1, resultado2;

    printf("Super Trunfo: Comparação de Países\n");

    // Exibindo as cartas
    printf("\n--- Cartas Disponíveis ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Exibindo menu e pegando atributos válidos
    exibirMenuAtributos();
    atributo1 = obterAtributoValido();

    do {
        printf("Escolha o segundo atributo para comparação (não pode ser o mesmo que o primeiro):\n");
        exibirMenuAtributos();
        atributo2 = obterAtributoValido();
    } while (atributo1 == atributo2);

    // Comparando os atributos
    resultado1 = compararAtributos(atributo1, carta1, carta2, &soma1, &soma2);
    resultado2 = compararAtributos(atributo2, carta1, carta2, &soma1, &soma2);

    // Mostrando o resultado
    mostrarResultado(carta1, carta2, atributo1, atributo2, soma1, soma2);

    return 0;
}