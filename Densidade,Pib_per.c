#include <stdio.h>
#include <string.h> // Necessário para strcpy

int main() {
    // Variáveis para armazenar as informações das duas cidades
   
    char A01[10], B02[10];
    char SaoPaulo[50], Bahia[50];
    
    int populacao1 = 119000000, populacao2 = 14850513;
    float area1 = 248.21 ; 
    float area2 = 567.29; 
    float pib1 = 920.833; 
    float pib2 = 114.4;
    int ponto_turistico1 = 36,  ponto_turistico2 = 13;

    // Entrada de dados para a primeira cidade
    
    strcpy(A01,  "SP01");
    strcpy(SaoPaulo, "São Paulo");
    populacao1 = 119000000;
    area1 = 248.21;
    pib1 = 920.833;
    ponto_turistico1 = 36;

    // Cálculo da densidade populacional e PIB per capita
    float densidade1 = populacao1/ area1;
    float pib_per_capita1 = pib1 * 1.0E9 / populacao1;

    // Entrada de dados para a segunda cidade
   

    strcpy(B02, "BA02");
    strcpy(Bahia, "Bahia");
    populacao2 = 14850513;
    area2 = 567.29;
    pib2 = 114.4;
    ponto_turistico2 = 13;

    // Cálculo da densidade populacional e PIB per capita
    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = pib2 * 1.0E9 / populacao2;

    // Exibição dos resultados formatados
    printf("\nCarta 1:\n");
    printf("Código: %s\n", A01);
    printf("Nome da Cidade: %s\n", SaoPaulo);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.3f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", ponto_turistico1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);

    printf("\nCarta 2:\n");
    printf("Código: %s\n", B02);
    printf("Nome da Cidade: %s\n", Bahia);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.3f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", ponto_turistico2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);

    return 0;
}
