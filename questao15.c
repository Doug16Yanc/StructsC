/* Faça um programa que seja uma agenda de compromissos e:
• Crie e leia um vetor de 5 estruturas de dados com: compromisso ´
e data. A data deve ser outra estrutura de dados contendo dia, mes e ano. ˆ
• Leia dois inteiros M e A e mostre todos os compromissos do mesˆ M do ano A.
Repita o procedimento ate ler M = 0.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Compromisso
{ 
    int dia;
    int mes;
    int ano;
    char descricao[tam];
};



int main(void)
{
    #define tamanho 5
    struct Compromisso compromisso[tamanho];
 
    int month, year;
    int retorno = 0;

    printf("Iniciando operações de marcar agendamentos...\n");

    for(int i = 0; i < tamanho; i++)
    {
        printf("Descreva o compromisso:\n");
        fflush(stdin);
        fgets(compromisso[i].descricao, tam, stdin);

        printf("Digite dia:\n");
        scanf("%d", &compromisso[i].dia);

        printf("Digite mês:\n");
        scanf("%d", &compromisso[i].mes);

        printf("Digite ano:\n");
        scanf("%d", &compromisso[i].ano);
        
    }

    printf("Iniciando operações de mostrar agendamentos marcados..\n");

    printf("Digite mês e ano:\n");
    printf("Mês ou 0 para finalizar:");
    scanf("%d", &month);

    while (month != 0)
    {
        if (month != 0)
        {
            printf("Ano:");
            scanf("%d", &year);

            for (int i = 0; i < tamanho; i++)
            {
                if (compromisso[i].mes == month || compromisso[i].ano == year)
                {
                    printf("Compromisso agendado: %s\n", compromisso[i].descricao);
                    retorno++;
                }
                else
                {
                    if ((retorno) == 0 && (i == 4))
                    {
                        printf("Não há compromisso para este mês e ano.\n");

                    }
                
                }
            }
            printf("Mês ou 0 para finalizar:");
            scanf("%d", &month);
        
        }
    }
    return 0;
}