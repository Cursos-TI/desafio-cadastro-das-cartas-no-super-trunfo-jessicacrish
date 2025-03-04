#include <stdio.h>
    
    int main () {

        // Dando nome as variaveis e os seus valores.
        char estado = 'A';
        char codigo[50] = "A01";
        char nome[50] = "SaoPaulo";
        int populacao = 11900000;
        float area = 248.21;
        float pib = 920.833;
        int npt = 36;

        printf("Ola! Boa tarde, aqui abaixo esta o cadastro da primeira carta!\n");
        printf("Carta 1: \n");
        printf("Estado: %c\n", estado);
        printf("Codigo: %s\n", codigo);
        printf("Nome da cidade: %s\n", nome);
        printf("População: %d\n", populacao);
        printf("Area em Km²: %.2f Km²\n", area);
        printf("PIB: %.3f reais\n", pib);
        printf("Numero de Pontos Turisticos: %d\n", npt);

        //Agora, vou utilizar as mesmas variaveis, entretanto, vou mudar os nomes significativos e os resultados.

        char Estado = 'B';
        char Codigo[50] = "B02";
        char Nome[50] = "Bahia";
        int Populacao = 14850513;
        float Area = 567.29;
        float PIB = 114.4;
        int NPT = 13;
        //Aqui, nos nomes significativos, coloquei todos com no maximo 1 letra maiuscula, para ter uma diferença na variação no topo do codigo.

        //Refazendo o Printf novamente.

        printf("Agora, o cadastro da segunda carta!\n");
        printf("Carta 2: \n");
        printf("Estado: %c\n", Estado);
        printf("Codigo: %s\n", Codigo);
        printf("Nome da Cidade: %s\n", Nome);
        printf("População: %d\n", Populacao);
        printf("Area em Km²: %.2f Km²\n", Area);
        printf("PIB: %.1f reais\n", PIB);
        printf("Numero de Pontos Turisticos: %d\n", NPT);

        printf ("Cadastro de duas cartas concluido, pode fechar o terminal!");

        return 0;
    }