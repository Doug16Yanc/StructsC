/*Faça um programa que leia os dados de 10 alunos (Nome, matricula, Media Final), arma- ´
zenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores,
o vetor dos aprovados e o vetor dos reprovados, considerando a media mínima para a
aprovac¸ao como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos ˜
dados do vetor de reprovados.*/


#include <stdio.h>
#include <string.h>

#define tam 900

void mostraSituacao();

struct Alunos
{
    char nome[tam];
    int matricula;
    float mediaFinal;
};

int main()
{
    #define tamanho 10

    struct Alunos alunos[tamanho];

    for(int i = 0; i < tamanho; i++)
    {
        printf("Digite o nome do %dº aluno:\n", i + 1);
        fflush(stdin);
        fgets(alunos[i].nome, tam, stdin);

        printf("Número da matrícula:\n");
        scanf("%d", &alunos[i].matricula);

        printf("Média final:\n");
        scanf("%f", &alunos[i].mediaFinal);
    }
    
    printf("\n");
    
    printf("Vetor dos aprovados.\n");
    
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].mediaFinal >= 5.0)
        {
            printf("\nNome: %s\nMatrícula: %d\nMédia final: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].mediaFinal);
        }
    }
    
    printf("\n");
    
    printf("Vetor dos reprovados.\n");
    
    for (int i = 0; i < tamanho; i++)
    {
        if (alunos[i].mediaFinal < 5.0)
        {
            printf("\nNome: %s\nMatrícula: %d\nMédia final: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].mediaFinal);
        }
    }
    return 0;
}


 

