/*Considerando a estrutura
struct Vetor{
float x;
float y;
float z;
};
para representar um vetor no R3, implemente um programa que calcule a soma de dois vetores.*/

#include <stdio.h>

struct Vetor
{
    float x;
    float y;
    float z;
};

int main(void)
{
    #define tam 2

    struct Vetor vetor[tam];
    int contador = 0;
    float somaVetorialX = 0, somaVetorialY = 0, somaVetorialZ = 0;

    for (contador = 0; contador < tam; contador++)
    {
        printf("Valor do vetor X :");
        scanf("%f", &vetor[contador].x);

        printf("Valor do vetor Y :");
        scanf("%f", &vetor[contador].y);

        printf("Valor do vetor Z :");
        scanf("%f", &vetor[contador].z);
    }
    somaVetorialX = vetor[0].x + vetor[1].x;
    somaVetorialY = vetor[0].y + vetor[1].y;
    somaVetorialZ = vetor[0].z + vetor[1].z;

    printf("\nAs somas dos valores dos vetores X, Y e Z são iguais, respectivamente, a %.1f, %.1f e %.1f.", somaVetorialX, somaVetorialY, somaVetorialZ);

    return 0;
}