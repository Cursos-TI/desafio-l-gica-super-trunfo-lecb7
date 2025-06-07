#include <stdio.h>

int main() {
    // Estrutura dos dados da carta (simplificado)
    char estado1[3], codigo1[4], cidade1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;

    char estado2[3], codigo2[4], cidade2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;

    // Variáveis calculadas
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

    // --- Entrada da Carta 1 ---
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", estado1);
    getchar();
    printf("Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Código (ex: A01): ");
    scanf("%3s", codigo1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // --- Entrada da Carta 2 ---
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", estado2);
    getchar();
    printf("Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Código (ex: B02): ");
    scanf("%3s", codigo2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    // --- Cálculos ---
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // --- Definir atributo para comparação ---
    // Troque a variável "atributoEscolhido" para comparar outro atributo
    // 1 = População
    // 2 = Área
    // 3 = PIB
    // 4 = Densidade Populacional
    // 5 = PIB per capita

    int atributoEscolhido = 1; // exemplo: comparar População

    float valor1, valor2;
    char nomeAtributo[30];

    // Atribui os valores e o nome do atributo escolhido
    switch (atributoEscolhido) {
        case 1:
            valor1 = (float)populacao1;
            valor2 = (float)populacao2;
            sprintf(nomeAtributo, "População");
            break;
        case 2:
            valor1 = area1;
            valor2 = area2;
            sprintf(nomeAtributo, "Área");
            break;
        case 3:
            valor1 = pib1;
            valor2 = pib2;
            sprintf(nomeAtributo, "PIB");
            break;
        case 4:
            valor1 = densidade1;
            valor2 = densidade2;
            sprintf(nomeAtributo, "Densidade Populacional");
            break;
        case 5:
            valor1 = pibPerCapita1;
            valor2 = pibPerCapita2;
            sprintf(nomeAtributo, "PIB per capita");
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // --- Mostrar dados calculados (opcional) ---
    printf("\n--- Dados calculados ---\n");
    printf("Densidade Populacional Carta 1: %.2f hab/km²\n", densidade1);
    printf("Densidade Populacional Carta 2: %.2f hab/km²\n", densidade2);
    printf("PIB per capita Carta 1: R$ %.2f\n", pibPerCapita1);
    printf("PIB per capita Carta 2: R$ %.2f\n", pibPerCapita2);

    // --- Comparação ---
    int vencedor; // 1 se carta 1 vence, 2 se carta 2 vence, 0 empate

    if (atributoEscolhido == 4) {
        // Para densidade, menor valor vence
        if (valor1 < valor2)
            vencedor = 1;
        else if (valor2 < valor1)
            vencedor = 2;
        else
            vencedor = 0;
    } else {
        // Para os outros, maior valor vence
        if (valor1 > valor2)
            vencedor = 1;
        else if (valor2 > valor1)
            vencedor = 2;
        else
            vencedor = 0;
    }

    // --- Exibir resultado da comparação ---
    printf("\nComparação de cartas (Atributo: %s):\n\n", nomeAtributo);

    printf("Carta 1 - %s (%s): ", cidade1, estado1);
    if (atributoEscolhido == 1)
        printf("%lu\n", populacao1);
    else if (atributoEscolhido == 2)
        printf("%.2f km²\n", area1);
    else if (atributoEscolhido == 3)
        printf("%.2f bilhões\n", pib1);
    else
        printf("%.2f\n", valor1);

    printf("Carta 2 - %s (%s): ", cidade2, estado2);
    if (atributoEscolhido == 1)
        printf("%lu\n", populacao2);
    else if (atributoEscolhido == 2)
        printf("%.2f km²\n", area2);
    else if (atributoEscolhido == 3)
        printf("%.2f bilhões\n", pib2);
    else
        printf("%.2f\n", valor2);

    if (vencedor == 1)
        printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    else if (vencedor == 2)
        printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}
