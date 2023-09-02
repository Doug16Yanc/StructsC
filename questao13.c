/*Faça um programa que leia um vetor com os dados de 5 carros: marca (maximo 15 ´
letras), ano e preço. Leia um valor p e mostre as informaçoes de todos os carros com ˜
preço menor que p. Repita este processo ate que seja lido um valor p = 0.*/

#include <stdio.h>
#include <string.h>

#define tam 900

void recebeP();

struct Carro  
{
    char modelo[tam];
    int ano;
    float preco;
};

int main(void)
{
    #define tamanho 5

    struct Carro carro[tamanho];

    float p;
    int retorno = 0;

    for (int i = 0; i < tamanho; i++)
    {
        printf("Modelo do carro %d: ", i + 1);
        fflush(stdin);
        fgets(carro[i].modelo, tam, stdin);

        printf("Ano:");
        scanf("%d", &carro[i].ano);

        printf("Preço (R$):");
        scanf("%f", &carro[i].preco);
    }

    printf("Digite o valor de um número arbitrário P (0 para finalizar):");
    scanf("%f", &p);


    while(p > 0)
    {
        printf("Procurando carros com preços menores...\n");

        for (int i = 0; i < tamanho; i++)
        {
            if (p > carro[i].preco)
            {
                printf("\nNome: %s\nano: %d\npreço (R$): %.2f\n", carro[i].modelo, carro[i].ano, carro[i].preco);
                retorno++;
            }
            else
            {
                if ((retorno == 0) && (i == 4))
                {
                    printf("\nNão há carros com valores de preços menores que p.\n");
                }
            }
        }
        printf("Digite o valor de um número arbitrário P (0 para finalizar):");
        scanf("%f", &p);
    }
    return 0;
}